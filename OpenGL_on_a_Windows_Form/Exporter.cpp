#include "Exporter.h"

using namespace svg;

Exporter::Exporter(std::string filename, const std::vector<gearGenerator>& theGears, int width,
					int height, const std::vector<double>& placement)
{
}

void ExportSVG()
{
	Dimensions dimensions(100, 200);
	Document doc("my_svg.svg", Layout(dimensions, Layout::BottomLeft));
	doc << Rectangle(Point(70, 55), 20, 15, Color::Yellow);
	doc.save();
}