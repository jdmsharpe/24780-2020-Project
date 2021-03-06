#include "ViewManager.h"

// For optimizer
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <math.h>
#include <string>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265
#endif

using namespace std;

//vector<Node> Nodes;
//vector <Node> theNodes;
//vector <Node> optimizedGears;
//vector <Node> tempNodes;
//vector <gear> theGears;
vector <gear> Gears;
vector <gear> optimizedGears;
vector <gear> tempGears;
bool read = true;
bool notoptimized = true;
bool optimized = false;
int ini_size_theGears = 0;
int size_theGears;

ViewManager::ViewManager() {}

vector<gear> ViewManager::setinitposition()
{
	for (int i = 0; i < theGears.size(); i++)
	{
		double x1 = theGears[i].getX();
		double y1 = theGears[i].getY();
		double r1 = theGears[i].getRadius();
		theGears[i].setX(r1);
		theGears[i].setY(r1);
	}
	
	return theGears;
}

vector<gear> ViewManager::optimize(std::vector<gear> Gears)
{
	int signx, signy;
	for (int i = 0; i < Gears.size(); i++)
	{
		for (int j = 0; j < Gears.size(); j++)
		{
			if (j > Gears.size())
			{
				j = 0;
			}
			double x1 = Gears[i].getX();
			double y1 = Gears[i].getY();
			double r1 = Gears[i].getRadius();
			double x2 = Gears[j].getX();
			double y2 = Gears[j].getY();
			double r2 = Gears[j].getRadius();

			while (pow((pow((x2 - x1), 2) + pow((y2 - y1), 2)), 0.5) < (r1 + r2))
			{
				if (i == j)
				{
					break;
				}
				else
				{
					int randomx = (rand() % 10);
					int randomy = (rand() % 10);
					if (randomx % 2 == 0)
					{
						signx = 1;
					}
					else
					{
						signx = -1;
					}
					if (randomy % 2 == 0)
					{
						signy = 1;
					}
					else
					{
						signy = -1;
					}

					x1 = x1 + signx * randomx;
					y1 = y1 + signy * randomy;

					if ((x1 - r1) < 0 || (y1 - r1) < 0)
					{
						//signx = 1;
						//signy = 1;
						/*x1 = WINDOW_WIDTH/2;
						y1 = WINDOW_HEIGHT/2;*/
						x1 = r1;
						y1 = r1;
					}
					if ((x1 + r1) > materialWidth || (y1 + r1) > materialHeight || (y1 - r1) < -materialHeight)
					{
						//signx = -1;
						//signy = -1;
						/*x1 = WINDOW_WIDTH/2;
						y1 = WINDOW_HEIGHT/2;*/
						x1 = r1;
						y1 = r1;
					}
					//x1 = x1 + signx * randomx;
					//y1 = y1 + signy * randomy;
					Gears[i].setX(x1);
					Gears[i].setY(y1);
				}
			}
		}

	}

	return Gears;
}

vector<gear> ViewManager::center(std::vector <gear> Gears)
{
	for (int i = 0; i < Gears.size(); i++)
	{
		double x = Gears[i].getX();
		double y = Gears[i].getY();
		double r = Gears[i].getRadius();
		if ((x - r) < 0 || (y - r) < 0 || (x + r) > materialWidth || (y + r) > materialHeight || (y - r) < -materialHeight)
		{
			Gears[i].setX(r + 10);
			Gears[i].setY(r + 10);
		}
	}
	return Gears;
}

bool ViewManager::checkintersection(std::vector <gear> Gears)
{
	bool check;
	bool allchecks = true;
	for (int i = 0; i < Gears.size(); i++)
	{
		for (int j = 0; j < Gears.size(); j++)
		{
			if (j > Gears.size())
			{
				j = 0;
			}
			if (j != i)
			{
				double x1 = Gears[i].getX();
				double y1 = Gears[i].getY();
				double r1 = Gears[i].getRadius();
				double x2 = Gears[j].getX();
				double y2 = Gears[j].getY();
				double r2 = Gears[j].getRadius();
				if (pow((pow((x2 - x1), 2) + pow((y2 - y1), 2)), 0.5) >= (r1 + r2))
				{
					check = true;
				}
				else
				{
					check = false;
					allchecks = false;
				}
			}


		}

	}

	return allchecks;

}



void ViewManager::draw() // Only for testing
{
	// Draw outline of the material
	drawMaterial();

	


	size_theGears = theGears.size();
	if (ini_size_theGears != size_theGears)
	{
		notoptimized = true;
	}
	else
	{
		notoptimized = false;
	}
	ini_size_theGears = size_theGears;

	if (notoptimized)
	{
		theGears = this->setinitposition();
		theGears = this->optimize(theGears);
		optimized = this->checkintersection(theGears);
		while (!optimized)
		{

			optimized = this->checkintersection(theGears);
			if (optimized)
			{
				notoptimized = false;
				break;
			}

			theGears = this->optimize(theGears);

		}
	}


	for (int k = 0; k < theGears.size(); k++)
	{
	
		// set color
		glColor3f(1.0f, 0.0f, 0.0f);

		int i;
		
		float r0, r1, r2;
		float angle, da;
		float u, v, len;

		r0 = theGears[k].getInner_radius();
		r1 = theGears[k].getOuter_radius() - theGears[k].getTD() / 2.0;
		r2 = theGears[k].getOuter_radius() + theGears[k].getTD() / 2.0;

		// specify center of gear object
		setObjectCenter(theGears[k].getX(), theGears[k].getY());
		//double x = theGears[k].getX();
		//double y = theGears[k].getY();
		double teeth = theGears[k].getT();

		da = 2.0 * M_PI / teeth / 4.0;

		//glShadeModel(GL_FLAT);

		//glNormal3f(0.0, 0.0, 1.0);

		/* draw front face */
		glBegin(GL_QUAD_STRIP);
		for (i = 0; i <= teeth; i++) {
			angle = i * 2.0 * M_PI / teeth;
			makeVertex(r0 * cos(angle), r0 * sin(angle));
			makeVertex(r1 * cos(angle), r1 * sin(angle));
			if (i < teeth) {
				makeVertex(r0 * cos(angle), r0 * sin(angle));
				makeVertex(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da));
			}
		}
		glEnd();

		/* draw front sides of teeth */
		glBegin(GL_QUADS);
		da = 2.0 * M_PI / teeth / 4.0;
		for (i = 0; i < teeth; i++) {
			angle = i * 2.0 * M_PI / teeth;

			makeVertex(r1 * cos(angle), r1 * sin(angle));
			makeVertex(r2 * cos(angle + da), r2 * sin(angle + da));
			makeVertex(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da));
			makeVertex(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da));
			/* for (int i = 0; i < 100; ++i) {
				 glVertex3f(outer_radius * (cos(rad(i)) + (rad(i) * sin(rad(i)))), outer_radius * (sin(rad(i)) - (rad(i) * cos(rad(i)))), 0);
			 }*/
		}
		glEnd();

		//glNormal3f(0.0, 0.0, -1.0);


		/* draw inside radius cylinder */
		glBegin(GL_QUAD_STRIP);
		for (i = 0; i <= teeth; i++) {
			angle = i * 2.0 * M_PI / teeth;
			//glNormal3f(-cos(angle), -sin(angle), 0.0);
			makeVertex(r0 * cos(angle), r0 * sin(angle));
			makeVertex(r0 * cos(angle), r0 * sin(angle));
		}
		glEnd();



		if (theGears[k].getHubShape() == 2)
		{
			/* draw front face */
			glBegin(GL_QUAD_STRIP);
			//glBegin(GL_QUADS);
			for (i = 0; i <= teeth; i++) {
				//glColor3f(0, 0.1, 0);
				angle = i * 2.0 * M_PI / teeth;
				makeVertex( r0 * cos(angle),  r0 * sin(angle));
				makeVertex( r1 * cos(angle),  r1 * sin(angle));
				if (i < teeth) {
					makeVertex( r0 * cos(angle),  r0 * sin(angle));
					makeVertex( r1 * cos(angle + 3 * da),  r1 * sin(angle + 3 * da));
				}
			}
			glEnd();

			/* draw front sides of teeth */
			glBegin(GL_QUADS);
			da = 2.0 * M_PI / teeth / 4.0;
			for (i = 0; i < teeth; i++) {
				angle = i * 2.0 * M_PI / teeth;
				//glColor3f(0, 0.1, 0);
				makeVertex( r1 * cos(angle),  r1 * sin(angle));
				makeVertex( r2 * cos(angle + da),  r2 * sin(angle + da));
				makeVertex( r2 * cos(angle + 2 * da),  r2 * sin(angle + 2 * da));
				makeVertex( r1 * cos(angle + 3 * da),  r1 * sin(angle + 3 * da));
				/* for (int i = 0; i < 100; ++i) {
					 glVertex3f(outer_radius * (cos(rad(i)) + (rad(i) * sin(rad(i)))), outer_radius * (sin(rad(i)) - (rad(i) * cos(rad(i)))), 0);
				 }*/
			}
			glEnd();


			glBegin(GL_POLYGON);
			for (int i = 0; i < 64; i++)
			{
				double angle = (double)i * M_PI / 32.0;
				double cx =  cos(angle) * (double)r0;
				double cy =   sin(angle) * (double)r0;
				//glColor3f(0, 0.1, 0);
				makeVertex(cx, cy);
			}
			glEnd();
			float b =  theGears[k].getHubD1();
			float l =  theGears[k].getHubD2();
			glColor3f(1, 1, 1);
			glBegin(GL_QUADS);
			glColor3f(1, 1, 1);
			//int b = 0.5;// theGears[k].getHubD1();
			//int l = 0.5;// theGears[k].getHubD2();
			makeVertex(  -b / 2,  - l / 2);
			makeVertex(  b / 2,  - l / 2);
			makeVertex(  b / 2,  l / 2);
			makeVertex( - b / 2,  l / 2);
			

			glEnd();
		
		}


		if (theGears[k].getHubShape() == 0)
		{
			/* draw front face */
			glBegin(GL_QUAD_STRIP);
			//glBegin(GL_QUADS);
			for (i = 0; i <= teeth; i++) {
				//glColor3f(0, 0.1, 0);
				angle = i * 2.0 * M_PI / teeth;
				makeVertex(r0 * cos(angle), r0 * sin(angle));
				makeVertex(r1 * cos(angle), r1 * sin(angle));
				if (i < teeth) {
					makeVertex(r0 * cos(angle), r0 * sin(angle));
					makeVertex(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da));
				}
			}
			glEnd();

			/* draw front sides of teeth */
			glBegin(GL_QUADS);
			da = 2.0 * M_PI / teeth / 4.0;
			for (i = 0; i < teeth; i++) {
				angle = i * 2.0 * M_PI / teeth;
				//glColor3f(0, 0.1, 0);
				makeVertex(r1 * cos(angle), r1 * sin(angle));
				makeVertex(r2 * cos(angle + da), r2 * sin(angle + da));
				makeVertex(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da));
				makeVertex(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da));
				/* for (int i = 0; i < 100; ++i) {
					 glVertex3f(outer_radius * (cos(rad(i)) + (rad(i) * sin(rad(i)))), outer_radius * (sin(rad(i)) - (rad(i) * cos(rad(i)))), 0);
				 }*/
			}
			glEnd();


			glBegin(GL_POLYGON);
			for (int i = 0; i < 64; i++)
			{
				double angle = (double)i * M_PI / 32.0;
				double cx = cos(angle) * (double)r0;
				double cy = sin(angle) * (double)r0;
				//glColor3f(0, 0.1, 0);
				makeVertex(cx, cy);
			}
			glEnd();
			

		}

	}


}