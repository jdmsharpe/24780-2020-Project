#ifndef SVG_EXPORTER_H
#define SVG_EXPORTER_H

#define PI 3.14159265358979

#include "simple_svg_1.0.0.hpp"

using namespace svg;

class ViewManager; // Predefine
class GearGenerator;

class Exporter
{
private:
	std::string filename;
	double strokeWidth;
	int lineResolution;

public:
	Exporter(std::string name, int lineResolution, double strokeWidth) :
		filename(filename), lineResolution(lineResolution), strokeWidth(strokeWidth) {}

	~Exporter();

	void ExportSVG(ViewManager &aManager);

	std::vector<std::pair<double, double>> getToothProfile(double toothMax, double toothMin, double baseRadius);
};

#endif