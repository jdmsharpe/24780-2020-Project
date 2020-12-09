#include "Exporter.h"
#include "ViewManager.h"

using namespace svg;

void Exporter::exportSVG(ViewManager &aManager, std::string filename)
{
	std::vector<gear> gears = aManager.getGearVector();
	int numGears = (int)gears.size();

	//if (unitSys == imperial) {
	//	int width = aManager.width * INCH_TO_PX;
	//	int height = aManager.height * INCH_TO_PX;
	//}
	//else if (unitSys == metric) {
	//	int width = aManager.width * MM_TO_PX;
	//	int height = aManager.height * MM_TO_PX;
	//}

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

		double pitchRadius = (numTeeth / pitch) / 2.0 * INCH_TO_PX;
		double addendum = 1.0 / pitch;
		double dedendum = 1.25 * addendum;
		double tooth_depth = addendum + dedendum;
		double outerRadius = gears[i].getOuter_radius() * INCH_TO_PX;

		// Calculate additional parameters
		double baseRadius = (pitchRadius - dedendum) * std::cos(pressureAngle);
		double footRadius = (pitchRadius - dedendum) - pitch / PI;

		double toothMax = std::acos(baseRadius / outerRadius);
		double toothMin = (footRadius < baseRadius) ? 0 : std::acos(baseRadius / footRadius);
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
			alpha += 2 * topMax;

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

			pathObject << PathPoint(footRadius * std::cos(alpha) + offset.first,
				footRadius * std::sin(alpha) + offset.second, "L");

			alpha = startingAlpha + (2 * PI) / numTeeth - deport + topMax;

			pathObject << ArcPoint(footRadius, footRadius, 0, 0, 1, footRadius * std::cos(alpha) + offset.first,
				footRadius * std::sin(alpha) + offset.second);

			for (auto const& point : toothProfile) {
				// Draw last curve to outer part of next tooth
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
	for (int u = 0; u < pointResolution; u++) {
		double t = (1 - u / pointResolution) * (-toothMax) + (u / pointResolution) * (-toothMin);
		toothProfile.push_back(std::make_pair(std::tan(t) - t, baseRadius / std::cos(t)));
	}
	return toothProfile;
}
