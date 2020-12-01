# include "gear.h"

const double Pi = 3.142;

gear::gear() : N(0), R(0) {}

gear::gear(int Ni, double Ri)
{
	N = Ni;
	R = Ri;
}


void gear::setN(int Ni)
{
	N = Ni;
	R = N * 10 / Pi;
}

void gear::setColor(int ri, int gi, int bi)
{
	r = ri;
	g = gi;
	b = bi;
}

void gear::setPosition(double xi, double yi, double thetai)
{
	x = xi;
	y = yi;
	theta = thetai;
}


int gear::getN() const
{
	return N;
}

void gear::draw()
{
	double d_angle = 0;
	double width = 10;
	double angle = 0;

	// circle	
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	int nSector = (int)(2 * Pi * R / 2);
	d_angle = 2 * Pi / nSector;
	for (int i = 0; i < nSector; i++)
		glVertex2d(x + (R + 1) * cos(i * d_angle), y + (R + 1) * sin(i * d_angle));
	glEnd();

	// teeth	
	glColor3ub(r, g, b);
	glBegin(GL_QUADS);
	d_angle = 2 * Pi / N;
	for (int i = 0; i < N; i++)
	{
		angle = d_angle * i + theta;
		glVertex2d(x + (R + width) * cos(angle) - width / 2 * sin(angle),
			y + (R + width) * sin(angle) + width / 2 * cos(angle));
		glVertex2d(x + (R + width) * cos(angle) - (-width) / 2 * sin(angle),
			y + (R + width) * sin(angle) + (-width) / 2 * cos(angle));
		glVertex2d(x - (-width) / 2 * sin(angle), y + (-width) / 2 * cos(angle));
		glVertex2d(x - width / 2 * sin(angle), y + width / 2 * cos(angle));
	}
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < N; i++)
	{
		angle = d_angle * i + theta;
		glVertex2d(x + (R + width) * cos(angle) - width / 2 * sin(angle),
			y + (R + width) * sin(angle) + width / 2 * cos(angle));
		glVertex2d(x + (R + width) * cos(angle) - (-width) / 2 * sin(angle),
			y + (R + width) * sin(angle) + (-width) / 2 * cos(angle));
		glVertex2d(x - (-width) / 2 * sin(angle), y + (-width) / 2 * cos(angle));
		glVertex2d(x - width / 2 * sin(angle), y + width / 2 * cos(angle));
	}
	glEnd();

	// circle	
	glColor3ub(r, g, b);
	glBegin(GL_POLYGON);
	d_angle = 2 * Pi / nSector;
	for (int i = 0; i < nSector; i++)
		glVertex2d(x + R * cos(i * d_angle), y + R * sin(i * d_angle));
	glEnd();

	// axis	
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	nSector = (int)(2 * Pi * 5 / 1);
	d_angle = 2 * Pi / nSector;
	for (int i = 0; i < nSector; i++)
		glVertex2d(x + 5 * cos(i * d_angle), y + 5 * sin(i * d_angle));
	glEnd();
}