#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#ifdef _WIN32
#include <windows.h>
#endif

#include <winuser.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include <string>
#include <sstream>
#include <vector>

#include "Node.h"
#include "gear.h"

#define WINDOW_WIDTH 775
#define WINDOW_HEIGHT 675

enum UnitSystem { imperial = 0, metric = 1 };

class ViewManager
{
private:

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

	struct gearType {
		double pitch;
		double pressureAngle;
		int teeth;
		int qty;
		double hubD1, hubD2;
		HubShape hub;
	};

	std::vector<gearType> gearSpecifications;

	std::vector<gear> theGears;

public:
	// defines the relationship of pixels/distance[in]
	double conversion;
	// define window size
	double windowWidth;
	double windowHeight;
	// define material size
	double materialWidth;
	double materialHeight;
	// define origin
	double originX, originY;

	ViewManager();
	
	bool manage();

	// addGear returns -1 if this is a new gear, else returns index of gear in vector 
	int addGear(double pitch, double pressureAngle, int teeth, int qty, HubShape hub, 
		double hubD1 = 0, double hubD2 = 0) {
		gearType thisGear;
		thisGear.pitch = pitch;
		thisGear.pressureAngle = pressureAngle;
		thisGear.teeth = teeth;
		thisGear.qty = qty;
		thisGear.hub = hub;
		thisGear.hubD1 = hubD1;
		thisGear.hubD2 = hubD2;
		// add the gear only if it is not already in the list
		gear thisGearForReal("hi", 300, 300, pitch, pressureAngle, teeth, hub, hubD1);
		theGears.push_back(thisGearForReal);

		int gearIndex = gearExists(thisGear);
		if (gearIndex == -1) 
			gearSpecifications.push_back(thisGear);
		else 
			gearSpecifications.at(gearIndex).qty++;
		return gearIndex;
	}

	// check if 'thisGear' is already a member of the gearSpecifications vector. If so return index, else -1
	int gearExists(gearType thisGear) {
		// don't check if there are no gears in the vector
		if (gearSpecifications.size() > 0) {
			// check each gear in the vector, stoping if there is a match
			for (int i = 0; i < gearSpecifications.size(); i++) {
				// check if all the properties are the same
				if (gearSpecifications.at(i).pitch == thisGear.pitch &&
					gearSpecifications.at(i).pressureAngle == thisGear.pressureAngle &&
					gearSpecifications.at(i).teeth == thisGear.teeth &&
					gearSpecifications.at(i).hub == thisGear.hub &&
					gearSpecifications.at(i).hubD1 == thisGear.hubD1 &&
					gearSpecifications.at(i).hubD2 == thisGear.hubD2) {
					return i;
				}
			}
		}
		return -1;
	}

	int gearEntries() {
		return gearSpecifications.size();
	}

	int getQTY(int i){
		return gearSpecifications.at(i).qty;
	}

	void setQTY(int index, int qty) {
		gearSpecifications.at(index).qty = qty;
	}

	std::string getLabel(int index) {
		std::stringstream label;
		label << "P: ";
		label << gearSpecifications.at(index).pitch;
		label << " PA: ";
		label << gearSpecifications.at(index).pressureAngle;
		label << " T: ";
		label << gearSpecifications.at(index).teeth;
		label << " Hub: ";
		switch (gearSpecifications.at(index).hub) {
		case 0:
			label << "None";
			break;
		case 1:
			label << "Circle, �: ";
			label << gearSpecifications.at(index).hubD1;
			break;
		case 2:
			label << "Rectangle, W: ";
			label << gearSpecifications.at(index).hubD1;
			label << " H: ";
			label << gearSpecifications.at(index).hubD2;
			break;
		}
		return label.str();
	}

	void defineMaterial(double windowWidth, double windowHeight, double materialWidth, double materialHeight) {
		// set public ViewManager variables
		this->windowWidth = windowWidth;
		this->windowHeight = windowHeight;
		this->materialHeight = materialHeight;
		this->materialWidth = materialWidth;
		// determine ratio of material and window
		double screenRatio = windowHeight / windowWidth;
		double materialRatio = materialHeight / materialWidth;
		// apply a margin of pixels so nothing goes to the edge of the screen
		int margin = 10;
		// the screen is relatively taller than the material
		// width is the constrained dimension
		if (screenRatio > materialRatio) {
			conversion = (windowWidth - 2 * margin) / materialWidth; // pixels/in
		}
		// the screen is relatively wider than the material
		// height is the constrained dimension
		else {
			conversion = (windowHeight - 2 * margin) / materialHeight; // pixels/in
		}
	}

	// take an input of positions in inches and draw on screen
	// makes necessary conversions for origin, scaling, etc
	void makeVertex(double x, double y) {
		// we should probably draw the gears always centered about 0,0
		// and apply the translation here to move them to the correct spot. 

		// scale point
		// apply translation
		// draw 

		glVertex2d(x, y);
	}

	void drawMaterial() {
		// center of material
		int cx = windowWidth / 2;
		int cy = windowHeight / 2;
		// define the 4 corners of the material
		int lx = cx - (materialWidth / 2) * conversion;
		int rx = cx + (materialWidth / 2) * conversion;
		int by = cy - (materialHeight / 2) * conversion;
		int ty = cy + (materialHeight / 2) * conversion;
		// update origin values
		this->originX = lx;
		this->originY = by;
		
		glLineWidth(3);
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2d(lx, by);
		glVertex2d(lx, ty);
		glVertex2d(rx, ty);
		glVertex2d(rx, by);
		glEnd();
	}

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
	//std::vector<Node> setinitposition(std::vector<Node> Nodes);
	//std::vector<Node> optimize(std::vector <Node> Nodes);
	//std::vector<Node> center(std::vector <Node> Nodes);
	//bool checkintersection(std::vector<Node> Nodes);
	//void draw(std::vector<Node> Nodes);
	std::vector<gear> setinitposition();
	std::vector<gear> optimize(std::vector<gear> Gears);
	std::vector<gear> center(std::vector<gear> Gears);
	bool checkintersection(std::vector<gear> Gears);
	//void draw();
	// End Optimizer

	void draw(); // Only for testing

private:
	void load();
	// asks for a filename and loads a file into model

	void save();
	// asks for a filename and loads a file into model

	void centerOnScreen();
	// sets view parameters so that the model is centered on screen
};

#endif
