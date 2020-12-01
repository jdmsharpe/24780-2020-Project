#pragma once
#include <string>
#include <vector>
#include "DrawingUtilNG.h"
#include "fssimplewindow.h"

class Node {
private:
	std::string label;
	double x, y, z;
	double Radius;

public:

	Node() {}
	Node(const std::string& aLabel, double xCoord, double yCoord,
		double zCoord = 0., double rad = 0.);

	std::string getLabel() { return label; }

	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
	double getRadius() { return Radius; }
	bool setLabel(const std::string& newLabel) { label = newLabel; }
	void setX(double xCoord) { x = xCoord; }
	void setY(double yCoord) { y = yCoord; }
	void setZ(double zCoord) { z = zCoord; }
	bool setRadius(double rad) { Radius = rad; }

	void draw(Node node, bool showLabel = false);
};