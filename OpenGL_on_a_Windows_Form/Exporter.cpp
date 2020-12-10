#include "Exporter.h"
#include "ViewManager.h"

using namespace svg;

void Exporter::exportSVG(ViewManager &aManager, std::string filename)
{
	std::vector<gear> gears = aManager.getGearVector();
	int numGears = (int)gears.size();

	std::pair<double, double> materialDimensions = aManager.getMaterialDimensions();

	Dimensions dimensions(materialDimensions.first * INCH_TO_PX, materialDimensions.second * INCH_TO_PX);

	// Create document with input filename and dimensions
	Document doc(filename, Layout(dimensions, Layout::BottomLeft));

	// Draw rectangle around drawing representing the boundaries of the material
	doc << svg::Rectangle(Point(0, dimensions.height), dimensions.width, dimensions.height,
		Color::Transparent, Stroke(strokeWidth, Color::Black));

	// Draw the gears
	for (int i = 0; i < numGears; i++) {
		// Path SVG object allows for curved lines
		Path pathObject(Color::Transparent, Stroke(strokeWidth, Color::Black));

		// Fetch gear parameters for drawing calculations
		int numTeeth = gears[i].getT();
		double pitch = gears[i].getPitch();
		double pressureAngle = gears[i].getPR() * (PI / 180.0);
		std::pair<double, double> offset = { gears[i].getX() * INCH_TO_PX, dimensions.height - gears[i].getY() * INCH_TO_PX };

		double pitchRadius = ((numTeeth / pitch) / 2.0) * INCH_TO_PX;
		double addendum = (1.0 / pitch) * INCH_TO_PX;
		double dedendum = (1.25 / pitch) * INCH_TO_PX;
		double outerRadius = pitchRadius + addendum;

		// Calculate additional parameters
		double baseRadius = pitchRadius * std::cos(pressureAngle);
		double innerRadius = pitchRadius - dedendum;

		double toothMax = std::acos(baseRadius / outerRadius);
		double toothMin = (innerRadius < baseRadius) ? 0 : std::acos(baseRadius / innerRadius);
		double deport = (1 - clearance) * (PI / numTeeth / 2 + std::tan(pressureAngle) - pressureAngle);
		double topMax = deport - std::tan(toothMax) + toothMax;

		double alpha = -topMax;

		// Generate tooth profiles
		std::vector<std::pair<double, double>> toothProfile = getToothProfile(toothMax, toothMin, baseRadius);

		// Move to starting point to begin drawing
		pathObject << PathPoint(outerRadius * std::cos(alpha) + offset.first,
								outerRadius * std::sin(alpha) + offset.second, "M");

		//Loop through each tooth and draw the path between
		for (int j = 0; j < numTeeth; j++) {

			double startingAlpha = alpha;
			alpha += 2.0 * topMax;

			// Draw first arc (outer part of tooth)
			pathObject << ArcPoint(outerRadius, outerRadius, 0, 0, 1, outerRadius * std::cos(alpha) + offset.first,
																	  outerRadius * std::sin(alpha) + offset.second);

			alpha += std::tan(toothMax) - toothMax;

			for (auto const& point : toothProfile)
			{
				// Draw first curve to root of gear
				pathObject << PathPoint(point.second * std::cos(alpha + point.first) + offset.first,
										point.second * std::sin(alpha + point.first) + offset.second, "L");
			}

			pathObject << PathPoint(innerRadius * std::cos(alpha) + offset.first,
									innerRadius * std::sin(alpha) + offset.second, "L");

			alpha = startingAlpha + (2 * PI) / numTeeth - deport + topMax;

			pathObject << ArcPoint(innerRadius, innerRadius, 0, 0, 1, innerRadius * std::cos(alpha) + offset.first,
																	innerRadius * std::sin(alpha) + offset.second);

			for (int i = toothProfile.size() - 1; i >= 0; i--) {
				// Draw last curve to outer part of next tooth
				std::pair<double, double> point = toothProfile[i];
				pathObject << PathPoint(point.second * std::cos(alpha - point.first) + offset.first,
										point.second * std::sin(alpha - point.first) + offset.second, "L");
			}

			alpha = startingAlpha + (2 * PI) / numTeeth;
		}
		// Append path object to document
		doc << pathObject;

		// Draw circular or rectangular hub
		if (gears[i].getHubShape() == circle) {
			doc << Circle(Point(offset.first, dimensions.height - offset.second), 
								gears[i].getHubD1() * INCH_TO_PX,
								Color::Transparent, Stroke(strokeWidth, Color::Black));
		}
		else if (gears[i].getHubShape() == rectangle) {
			doc << svg::Rectangle(Point(offset.first - (gears[i].getHubD1() * INCH_TO_PX) / 2.0,
										dimensions.height - offset.second + (gears[i].getHubD2() * INCH_TO_PX) / 2.0),
										gears[i].getHubD1() * INCH_TO_PX,
										gears[i].getHubD2() * INCH_TO_PX,
										Color::Transparent, Stroke(strokeWidth, Color::Black));
		}
	}

	// Save document to .svg file
	doc.save();
}

std::vector<std::pair<double, double>> Exporter::getToothProfile(double toothMax, double toothMin, double baseRadius)
{
	std::vector<std::pair<double, double>> toothProfile;
	for (int u = 0; u < pointResolution; u++) { // Change to float
		double t = (1 - (float)u / pointResolution) * (-toothMax) + ((float)u / pointResolution) * (-toothMin);
		toothProfile.push_back(std::make_pair(std::tan(t) - t, baseRadius / std::cos(t)));
	}
	return toothProfile;
}
