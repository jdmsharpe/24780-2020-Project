#pragma once

#include <vector>
#include <string>

#include "simple_svg_1.0.0.hpp"

class gearGenerator;

class Exporter
{
public:
	Exporter(std::string filename, const std::vector<gearGenerator>& theGears, int width, 
			int height, const std::vector<double>& placement);

	void ExportSVG();
};
