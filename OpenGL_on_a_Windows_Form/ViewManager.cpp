#include "ViewManager.h"

// For optimizer
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <math.h>

std::vector<Node> ViewManager::fileread()
{
	std::vector<Node> readNodes;
	std::string currLine;
	std::stringstream currStream;
	std::string inFileName = "Circle.fem";
	std::ifstream inFile;
	inFile.open(inFileName);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			std::getline(inFile, currLine);

			if (currLine.find("Circles:") != std::string::npos)
			{
				std::string label;
				double xCoord, yCoord, zCoord, rad;
				getline(inFile, currLine);
				while (!inFile.eof() && currLine.find("End Circles:") == std::string::npos)
				{
					currStream.str(currLine);
					currStream >> label >> xCoord >> yCoord >> zCoord >> rad;
					currStream.clear();
					label = StringPlus::trim(label);
					Node newNode(label, xCoord * 20, yCoord * 20, zCoord, rad);
					readNodes.push_back(newNode);
					getline(inFile, currLine);
				}
			}
		}
		std::cout << "File Reading Done....." << std::endl;
	}
	else
	{
		std::cout << "Was not able to open " << inFileName << " for input. " << std::endl;
	}

	inFile.close();
	return readNodes;
}

std::vector<Node> ViewManager::optimize(std::vector<Node> Nodes)
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
					int randomx = 5 * (rand() % 10);
					int randomy = 5 * (rand() % 10);
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
						x1 = WINDOW_WIDTH / 2;
						y1 = WINDOW_HEIGHT / 2;
					}
					if ((x1 + r1) > WINDOW_WIDTH || (y1 + r1) > WINDOW_HEIGHT)
					{
						//signx = -1;
						//signy = -1;
						x1 = WINDOW_WIDTH / 2;
						y1 = WINDOW_HEIGHT / 2;
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

std::vector<Node> ViewManager::center(std::vector<Node> Nodes)
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

bool ViewManager::checkintersection(std::vector<Node> Nodes)
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

void ViewManager::draw(std::vector<Node> Nodes)
{

	for (int i = 0; i < Nodes.size(); i++)
	{
		Nodes[i].draw(Nodes[i], 0);
	}
}