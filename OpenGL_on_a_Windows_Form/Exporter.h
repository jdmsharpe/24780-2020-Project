#ifndef SVG_EXPORTER_H
#define SVG_EXPORTER_H

#define PI 3.14159265358979
#define INCH_TO_PX 96
#define MM_TO_PX 3.7795

#include "simple_svg_1.0.0.hpp"
#include "ViewManager.h"

using namespace svg;

class GearGenerator;

class Exporter
{
private:
	std::string filename;
	UnitSystem unitSys;
	double strokeWidth;
	int lineResolution; 
	double clearance;

public:
	Exporter(std::string filename, UnitSystem unitsys) :
		filename(filename), unitSys(unitSys), lineResolution(20), strokeWidth(0.5), clearance(0.03) {}

	~Exporter();

	void ExportSVG(ViewManager &aManager);

	std::vector<std::pair<double, double>> getToothProfile(double toothMax, double toothMin, double baseRadius);
};

#endif
