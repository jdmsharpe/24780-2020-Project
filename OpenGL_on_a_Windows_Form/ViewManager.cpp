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



using namespace std;

vector<Node> Nodes;

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
				double xCoord, yCoord, zCoord, rad;
				getline(inFile, currLine);
				while (!inFile.eof() && currLine.find("End Circles:") == string::npos)
				{
					currStream.str(currLine);
					currStream >> label >> xCoord >> yCoord >> zCoord >> rad;
					currStream.clear();
					Node newNode(label, xCoord * 20, yCoord * 20, zCoord, rad);
					readNodes.push_back(newNode);
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
	return readNodes;
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

vector<Node> ViewManager::optimize()
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

vector<Node> ViewManager::center()
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

bool ViewManager::checkintersection()
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
bool read = true;

void ViewManager::draw() // Only for testing
{
	if (read)
	{
		this->fileread();
		read = false;
	}



	for (int i = 0; i < Nodes.size(); i++)
	{
		/*Nodes[i].draw(Nodes[i], 0);*/
		int size = 2;
		double halfSize = size * sqrt(2.);

		glBegin(GL_QUADS);

		double screenX, screenY, r;
		screenX = Nodes[i].getX() + 0;
		screenY = -Nodes[i].getY() + WINDOW_HEIGHT;
		r = Nodes[i].getRadius();


		glVertex2f(screenX - halfSize, screenY);
		glVertex2f(screenX, screenY + halfSize);
		glVertex2f(screenX + halfSize, screenY);
		glVertex2f(screenX, screenY - halfSize);
		glEnd();


		const double pi = 3.1415927;

		glBegin(GL_LINE_LOOP);

		for (int i = 0; i < 64; i++)
		{
			double angle = (double)i * pi / 32.0;
			double x_new = (double)screenX + cos(angle) * (double)r;
			double y_new = (double)screenY + sin(angle) * (double)r;

			glColor3d(0.5, 0.8, 0.7);
			glVertex2d(x_new, y_new);

		}
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
	glEnd();											// Done drawing the pyramid
}