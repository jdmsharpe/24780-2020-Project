#include "Exporter.h"

using namespace svg;

Exporter::Exporter(std::string name, const std::vector<gearGenerator>& theGears, int width,
					int height, const std::vector<double>& placement)
{
	filename = name;
	strokeWidth = 0.5;
	numGears = (int)theGears.size();
	Dimensions dim(width, height);
	dimensions = dim;
	/* Will extract other information from theGears, placement
	and assign to private member variables */
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
		// Push back points into path (will have to make changes to Simple SVG header)
		// The following is just an example
		pathObject << Point(100, 200) << Point(150, 250) << Point(200, 300);
		doc << pathObject;
	}
	doc.save();
}