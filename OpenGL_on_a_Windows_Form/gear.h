#pragma once
#include <math.h>
#include "fssimplewindow.h"

extern const double Pi;

class gear
{
protected:
	double x, y, theta;
	int N;
	double R;
	double w;
	int r, g, b;

public:
	gear();
	gear(int Ni, double Ri);
	void setN(int Ni);
	void setColor(int ri, int gi, int bi);
	void setPosition(double xi, double yi, double thetai);
	int getN() const;
	void draw();
}; #pragma once
