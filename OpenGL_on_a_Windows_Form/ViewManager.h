#pragma once

#include <string>
#include <vector>

#include "Node.h"
#include "StringPlus.h"

#define WINDOW_WIDTH 800 // (!) Update me
#define WINDOW_HEIGHT 600

enum UnitSystem { imperial = 0, metric = 1 };

class GearGenerator; // (!) Remove and replace with include

class ViewManager
{
private:
	std::vector<GearGenerator> theGears;

	int panChange;
	double zoomFactor;

	// Do we need the following?
	int shapeColor;  // H value for slider color (S = 1, V = 1)
	int nodeColor;  // H value for node color (S = 1, V = 1)
	int lineWidth;
	bool showNodes;
	bool isFilled;

	int xOrigin, yOrigin; // screen coords of model coords 0,0
	int prevLocX, prevLocY; // for zoom and pan, and for node edit
	double viewScale; // must be greater than zero

	UnitSystem unitSys;

public:
	ViewManager();

	bool manage();

	void getScreenCoords(double modelX, double modelY,
		double& screenX, double& screenY);
	// given model coordinates, function calculates screen coordinates
	// converting for translation and scale

	void getModelCoords(double& modelX, double& modelY,
		double screenX, double screenY);
	// given screen coordinates, function calculates model coordinates
	// converting for translation and scale

	void screenVertex(double modelX, double modelY);
	// given model coordinates, function adds a vertex on screen
	// after converting for translation and scale



	//Optimizer
	std::vector<Node> fileread();
	std::vector<Node> optimize(std::vector <Node> Nodes);
	std::vector<Node> center(std::vector <Node> Nodes);
	bool checkintersection(std::vector<Node> Nodes);
	void draw(std::vector<Node> Nodes);
	// End Optimizer

private:
	void load();
	// asks for a filename and loads a file into model

	void save();
	// asks for a filename and loads a file into model

	void centerOnScreen();
	// sets view parameters so that the model is centered on screen
};