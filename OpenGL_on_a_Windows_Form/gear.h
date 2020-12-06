#pragma once
#include <math.h>
#include <cmath>
#include <string>

extern const double Pi;

enum HubShape { none = 0, circle = 1, rectangle = 2 };

class gear
{
protected:
	std::string label;
	double x, y, theta;
	int N;
	double R, OR;
	double w;
	int r, g, b;
	double inner_radius, outer_radius, teeth, tooth_depth;
	HubShape shape;
	double shapeParameter[2];

public:
	gear();
	gear(const std::string& aLabel, double xCoord, double yCoord,
		double zCoord, double rad, double irad, int T, double TD);
	void setN(int Ni);
	void setinner_radius(double rad) { R = rad; }
	void setouter_radius(double rad) { OR = rad; }
	void setTeeth(double T) { teeth = T; }
	void setTooth_depth(double TD) { tooth_depth = TD; }
	void setColor(int ri, int gi, int bi);
	void setPosition(double xi, double yi, double thetai);
	double getInner_radius() { return R; }
	double getOuter_radius() { return OR; }
	double getTD() { return tooth_depth; }
	double getX() { return x; }
	double getY() { return y; }
	double getT() { return teeth; }
	int getN() const;
	void draw(float inner_radius, float outer_radius,
		int teeth, float tooth_depth);
};