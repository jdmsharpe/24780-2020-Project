#ifndef SVG_EXPORTER_H
#define SVG_EXPORTER_H

#include "simple_svg_1.0.0.hpp"

using namespace svg;

class gearGenerator;

class Exporter
{
private:
	std::string filename;
	double strokeWidth;
	int numGears;
	Dimensions dimensions;

public:
	Exporter(std::string filename, const std::vector<gearGenerator>& theGears, int width, 
			int height, const std::vector<double>& placement);

	~Exporter();

	void ExportSVG();
};

#endif