#ifndef SVG_EXPORTER_H
#define SVG_EXPORTER_H

#define PI 3.14159265358979
#define INCH_TO_PX 96
#define MM_TO_PX 3.7795

#include "simple_svg_1.0.0.hpp"

using namespace svg;

class ViewManager;

class Exporter
{
private:
	double strokeWidth;
	int pointResolution;
	double clearance;

public:
	Exporter() :
		pointResolution(20), strokeWidth(1), clearance(0.03) {}

	void exportSVG(ViewManager &aManager, std::string filename);

	std::vector<std::pair<double, double>> getToothProfile(double toothMax, double toothMin, double baseRadius);
};

#endif
