#include "ViewManager.h"

// For optimizer
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <math.h>
#include <string>
#include <vector>
//#include <gl\gl.h> 
//#include <gl\glu.h> 
#include "Node.h"
#include "ViewManager.h"

#ifndef M_PI
#define M_PI 3.14159265
#endif


using namespace std;

vector<Node> Nodes;
vector <Node> theNodes;
vector <Node> optimizedNodes;
vector <Node> tempNodes;
vector <gear> theGears;
bool read = true;
bool notoptimized = true;
bool optimized = false;

ViewManager::ViewManager()
{
}



vector<Node> ViewManager::fileread()
{
	vector<Node> readNodes;
	string currLine;
	stringstream currStream;
	string inFileName = "Circle.fem";
	ifstream inFile;
	inFile.open(inFileName);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			getline(inFile, currLine);

			if (currLine.find("Circles:") != string::npos)
			{
				string label;
				double xCoord, yCoord, zCoord, rad, irad, T, TD;
				getline(inFile, currLine);
				while (!inFile.eof() && currLine.find("End Circles:") == string::npos)
				{
					currStream.str(currLine);
					currStream >> label >> xCoord >> yCoord >> zCoord >> rad >> irad >> T >> TD;
					currStream.clear();
					Node newNode(label, xCoord * 20, yCoord * 20, zCoord, rad);
					gear newGear(label, xCoord * 20, yCoord * 20, zCoord, rad, irad, T, TD);
					//readNodes.push_back(newNode);
					Nodes.push_back(newNode);
					theGears.push_back(newGear);
					getline(inFile, currLine);
				}
			}
		}
		cout << "File Reading Done....." << endl;
	}
	else
	{
		cout << "Was not able to open " << inFileName << " for input. " << endl;
	}

	inFile.close();
	return Nodes;
}

vector<Node> ViewManager::setinitposition()
{
	for (int i = 0; i < Nodes.size(); i++)
	{
		double x1 = Nodes[i].getX();
		double y1 = Nodes[i].getY();
		double r1 = Nodes[i].getRadius();
		Nodes[i].setX(r1);
		Nodes[i].setY(r1);
	}
	
	return Nodes;
}

vector<Node> ViewManager::optimize(std::vector <Node> Nodes)
{
	int signx, signy;
	for (int i = 0; i < Nodes.size(); i++)
	{
		for (int j = 0; j < Nodes.size(); j++)
		{
			if (j > Nodes.size())
			{
				j = 0;
			}
			double x1 = Nodes[i].getX();
			double y1 = Nodes[i].getY();
			double r1 = Nodes[i].getRadius();
			double x2 = Nodes[j].getX();
			double y2 = Nodes[j].getY();
			double r2 = Nodes[j].getRadius();

			while (pow((pow((x2 - x1), 2) + pow((y2 - y1), 2)), 0.5) < (r1 + r2))
			{
				if (i == j)
				{
					break;
				}
				else
				{
					int randomx = 3 * (rand() % 10);
					int randomy = 3 * (rand() % 10);
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
					if ((x1 + r1) > WINDOW_WIDTH || (y1 + r1) > WINDOW_HEIGHT || (y1 - r1) < -WINDOW_HEIGHT)
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
					Nodes[i].setX(x1);
					Nodes[i].setY(y1);
				}
			}
		}

	}

	return Nodes;
}

vector<Node> ViewManager::center(std::vector <Node> Nodes)
{
	for (int i = 0; i < Nodes.size(); i++)
	{
		double x = Nodes[i].getX();
		double y = Nodes[i].getY();
		double r = Nodes[i].getRadius();
		if ((x - r) < 0 || (y - r) < 0 || (x + r) > WINDOW_WIDTH || (y + r) > WINDOW_HEIGHT || (y - r) < -WINDOW_HEIGHT)
		{
			Nodes[i].setX(r + 10);
			Nodes[i].setY(r + 10);
		}
	}
	return Nodes;
}

bool ViewManager::checkintersection(std::vector <Node> Nodes)
{
	bool check;
	bool allchecks = true;
	for (int i = 0; i < Nodes.size(); i++)
	{
		for (int j = 0; j < Nodes.size(); j++)
		{
			if (j > Nodes.size())
			{
				j = 0;
			}
			if (j != i)
			{
				double x1 = Nodes[i].getX();
				double y1 = Nodes[i].getY();
				double r1 = Nodes[i].getRadius();
				double x2 = Nodes[j].getX();
				double y2 = Nodes[j].getY();
				double r2 = Nodes[j].getRadius();
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

//void ViewManager::draw(vector<Node> Nodes)
//{
//
//	for (int i = 0; i < Nodes.size(); i++)
//	{
//		Nodes[i].draw(Nodes[i], 0);
//	}
//}


void ViewManager::draw() // Only for testing
{
	if (read)
	{
		this->fileread();
		read = false;
	}

	if (notoptimized)
	{
		tempNodes = this->setinitposition();
		optimizedNodes = this->optimize(tempNodes);
		while (!optimized)
		{

			optimized = this->checkintersection(optimizedNodes);
			if (optimized)
			{
				notoptimized = false;
				break;
			}
			else
			{
				tempNodes = optimizedNodes;
			}

			optimizedNodes = this->optimize(tempNodes);
		
		}
	}

	for (int i = 0; i < optimizedNodes.size(); i++)
	{
		theGears[i].setPosition(optimizedNodes[i].getX(), optimizedNodes[i].getY(), 0);
		/*Nodes[i].draw(Nodes[i], 0);*/
		int size = 2;
		double halfSize = size * sqrt(2.);
		double x_test = optimizedNodes[i].getX();
		double y_test = optimizedNodes[i].getY();
		/*glBegin(GL_QUADS);*/
		glColor3f(1.0f, 1.0f, 1.0f);
		double screenX, screenY, r;
		screenX = optimizedNodes[i].getX() + 0;
		screenY = -optimizedNodes[i].getY() + WINDOW_HEIGHT;
		r = optimizedNodes[i].getRadius();


	/*	glVertex2f(screenX - halfSize, screenY);
		glVertex2f(screenX, screenY + halfSize);
		glVertex2f(screenX + halfSize, screenY);
		glVertex2f(screenX, screenY - halfSize);
		glEnd();*/


		const double pi = 3.1415927;

		glBegin(GL_LINE_LOOP);
		glColor3f(1.0f, 1.0f, 1.0f);
		for (int i = 0; i < 64; i++)
		{
			double angle = (double)i * pi / 32.0;
			double x_new = (double)screenX + cos(angle) * (double)r;
			double y_new = (double)screenY + sin(angle) * (double)r;

			glColor3d(0.5, 0.8, 0.7);
			glVertex2d(x_new, y_new);

		}
		glEnd();
	}
	
	for (int k = 0; k < theGears.size(); k++)
	{
		int i;
		float r0, r1, r2;
		float angle, da;
		float u, v, len;

		r0 = theGears[k].getInner_radius();
		r1 = theGears[k].getOuter_radius() - theGears[k].getTD() / 2.0;
		r2 = theGears[k].getOuter_radius() + theGears[k].getTD() / 2.0;
		double x = theGears[k].getX();
		double y = theGears[k].getY();
		double teeth = theGears[k].getT();

		da = 2.0 * M_PI / teeth / 4.0;

		//glShadeModel(GL_FLAT);

		glNormal3f(0.0, 0.0, 1.0);

		/* draw front face */
		glBegin(GL_QUAD_STRIP);
		for (i = 0; i <= teeth; i++) {
			angle = i * 2.0 * M_PI / teeth;
			glVertex3f(x + r0 * cos(angle), y + r0 * sin(angle), 0);
			glVertex3f(x + r1 * cos(angle), y + r1 * sin(angle), 0);
			if (i < teeth) {
				glVertex3f(x + r0 * cos(angle), y + r0 * sin(angle), 0);
				glVertex3f(x + r1 * cos(angle + 3 * da), y + r1 * sin(angle + 3 * da), 0);
			}
		}
		glEnd();

		/* draw front sides of teeth */
		glBegin(GL_QUADS);
		da = 2.0 * M_PI / teeth / 4.0;
		for (i = 0; i < teeth; i++) {
			angle = i * 2.0 * M_PI / teeth;

			glVertex3f(x + r1 * cos(angle), y + r1 * sin(angle), 0);
			glVertex3f(x + r2 * cos(angle + da), y + r2 * sin(angle + da), 0);
			glVertex3f(x + r2 * cos(angle + 2 * da), y + r2 * sin(angle + 2 * da), 0);
			glVertex3f(x + r1 * cos(angle + 3 * da), y + r1 * sin(angle + 3 * da), 0);
			/* for (int i = 0; i < 100; ++i) {
				 glVertex3f(outer_radius * (cos(rad(i)) + (rad(i) * sin(rad(i)))), outer_radius * (sin(rad(i)) - (rad(i) * cos(rad(i)))), 0);
			 }*/
		}
		glEnd();

		glNormal3f(0.0, 0.0, -1.0);


		/* draw inside radius cylinder */
		glBegin(GL_QUAD_STRIP);
		for (i = 0; i <= teeth; i++) {
			angle = i * 2.0 * M_PI / teeth;
			glNormal3f(-cos(angle), -sin(angle), 0.0);
			glVertex3f(x + r0 * cos(angle), y + r0 * sin(angle), 0);
			glVertex3f(x + r0 * cos(angle), y + r0 * sin(angle), 0);
		}
		glEnd();
	}
	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -10.0f);						// Move left 1.5 units and into the screen 6.0
	//glBegin(GL_TRIANGLES);								// Start drawing a triangle
	//glColor3f(1.0f, 1.0f, 1.0f);						// Red
	//glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of triangle (front)
	//glColor3f(0.0f, 1.0f, 0.0f);						// Green
	//glVertex3f(-1.0f, -1.0f, 1.0f);					// Left of triangle (front)
	//glColor3f(0.0f, 0.0f, 1.0f);						// Blue
	//glVertex3f(1.0f, -1.0f, 1.0f);					// Right of triangle (front)
	//glColor3f(1.0f, 0.0f, 0.0f);						// Red
	//glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of triangle (right)
	//glColor3f(0.0f, 0.0f, 1.0f);						// Blue
	//glVertex3f(1.0f, -1.0f, 1.0f);					// Left of triangle (right)
	//glColor3f(0.0f, 1.0f, 0.0f);						// Green
	//glVertex3f(1.0f, -1.0f, -1.0f);					// Right of triangle (right)
	//glColor3f(1.0f, 0.0f, 0.0f);						// Red
	//glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of triangle (back)
	//glColor3f(0.0f, 1.0f, 0.0f);						// Green
	//glVertex3f(1.0f, -1.0f, -1.0f);					// Left of triangle (back)
	//glColor3f(0.0f, 0.0f, 1.0f);						// Blue
	//glVertex3f(-1.0f, -1.0f, -1.0f);					// Right of triangle (back)
	//glColor3f(1.0f, 0.0f, 0.0f);						// Red
	//glVertex3f(0.0f, 1.0f, 0.0f);					// Top Of triangle (left)
	//glColor3f(0.0f, 0.0f, 1.0f);						// Blue
	//glVertex3f(-1.0f, -1.0f, -1.0f);					// Left of triangle (left)
	//glColor3f(0.0f, 1.0f, 0.0f);						// Green
	//glVertex3f(-1.0f, -1.0f, 1.0f);					// Right of triangle (left)
											// Done drawing the pyramid
}