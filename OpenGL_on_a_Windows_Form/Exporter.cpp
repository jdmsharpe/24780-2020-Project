#include "Exporter.h"

using namespace svg;

Exporter::Exporter(std::string name, const std::vector<gearGenerator>& theGears, int width,
					int height, const std::vector<double>& placement)
{
	filename = name;
	strokeWidth = 0.5;
	//numGears = (int)theGears.size();
	Dimensions dim(width, height);
	dimensions = dim;
	// Will extract other information from theGears and placement
	// and assign to private member variables
}

void Exporter::ExportSVG()
{
	// Create document with input filename and dimensions
	Document doc(filename, Layout(dimensions, Layout::BottomLeft));
	// Draw rectangle around drawing representing the boundaries of the material
	doc << Rectangle(Point(0, 0), dimensions.width, dimensions.height, 
				Color::Transparent, Stroke(strokeWidth, Color::Black));
	// Draw the gears
	for (int i = 0; i < numGears; i++) {
		// Path SVG object allows for curved lines
		Path pathObject(Color::Transparent, Stroke(strokeWidth, Color::Black));
		// Push back points into path
		// To enable curved lines, Simple SVG was updated with PathPoint struct
		// The following is just an example
		pathObject << PathPoint(100, 200, "M"); // Move to (100, 200)
		pathObject << PathPoint(150, 250, "L"); // Draw straight line between old and new position
		pathObject << PathPoint(70, 60, "M") << PathPoint(70, 80, "C") <<
					  PathPoint(110, 80) << PathPoint(110, 60); // Bezier curve (bit hacky)
		// There are several other options. Final script will probably utilize a method
		// to programmatically determine Bezier curves to draw for both gear body and teeth.
		// This will be based around the same method used in gearGenerator to draw the gear.
		// If gears are filled in, this task becomes a good bit easier.
		doc << pathObject;
	}
	doc.save();
}