#include "Exporter.h"

using namespace svg;

void Exporter::ExportSVG(ViewManager &aManager)
{
	//std::vector<GearGenerator> gears = aManager.getGearInfo();
	//int numGears = (int)gears.size();
	int numGears = 1;
	//Dimensions dimensions(aManager.width, aManager.height);
	Dimensions dimensions(500, 500); // Until ready to incorporate ViewManager

	// Create document with input filename and dimensions
	Document doc(filename, Layout(dimensions, Layout::BottomLeft));

	// Draw rectangle around drawing representing the boundaries of the material
	doc << Rectangle(Point(0, dimensions.height), dimensions.width, dimensions.height, 
				Color::Transparent, Stroke(strokeWidth, Color::Black));

	// Draw the gears
	for (int i = 0; i < numGears; i++) {
		// Path SVG object allows for curved lines
		Path pathObject(Color::Transparent, Stroke(strokeWidth, Color::Black));

		// Fetch gear parameters for drawing calculations
		//int numTeeth = gears[i].getNumTeeth();
		//std::pair<double, double> offset = gears[i].getPosition();
		//double outerRadius = gears[i].getOuterRadius(); // Will need to calculate
		//double pitchRadius = gears[i].getPitchRadius(); // Will need to calculate
		//double pitch = gears[i].getPitch();
		//double pressureAngle = gears[i].getPressureAngle(); // Will need to calculate?
		//double clearance = gears[i].getClearance(); // Will need to calculate?
		int numTeeth = 25;
		std::pair<double, double> offset = { 250.0, 250.0 };
		double outerRadius = 68.0;
		double pitchRadius = 64.0;
		double pitch = 15.0;
		double pressureAngle = 20.0 * (PI / 180.0);
		double clearance = 0.03;

		// Calculate additional parameters
		double diff = pitch / PI;
		double baseRadius = pitchRadius * std::cos(pressureAngle);
		double footRadius = pitchRadius - diff;

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

			for (auto const &point : toothProfile)
			{
				// Draw first line to root of gear
				pathObject << PathPoint(point.second * std::cos(alpha + point.first) + offset.first,
										point.second * std::sin(alpha + point.first) + offset.second, "L");
			}

			pathObject << PathPoint(footRadius * std::cos(alpha) + offset.first, 
									footRadius * std::sin(alpha) + offset.second, "L");

			alpha = startingAlpha + (2 * PI) / numTeeth - deport + topMax;

			pathObject << ArcPoint(footRadius, footRadius, 0, 0, 1, footRadius * std::cos(alpha) + offset.first,
								   footRadius * std::sin(alpha) + offset.second);

			for (auto const &point : toothProfile) {
				// Draw last line to outer part of next tooth
				pathObject << PathPoint(point.second * std::cos(alpha - point.first) + offset.first,
										point.second * std::sin(alpha - point.first) + offset.second, "L");
			}

			alpha = startingAlpha + (2 * PI) / numTeeth;
		}
		// Append path object to document
		doc << pathObject;
	}
	// Save document to .svg file
	doc.save();
}

std::vector<std::pair<double, double>> Exporter::getToothProfile(double toothMax, double toothMin, double baseRadius)
{
	std::vector<std::pair<double, double>> toothProfile;
	for (int u = 0; u < lineResolution; u++) {
		double t = (1 - u / lineResolution) * (-toothMax) + (u / lineResolution) * (-toothMin);
		toothProfile.push_back(std::make_pair(std::tan(t) - t, baseRadius / std::cos(t)));
	}
	return toothProfile;
}