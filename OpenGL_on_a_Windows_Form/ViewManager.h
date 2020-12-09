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

#include "gear.h"
#include "Exporter.h"

enum UnitSystem { inch = 0, millimeter = 1 };

class ViewManager
{
private:

	int panChange;
	double zoomFactor;
	double viewScale; // must be greater than zero

	struct gearType {
		double pitch, module;
		double pressureAngle;
		int teeth;
		int qty;
		double hubD1, hubD2;
		HubShape hub;
		UnitSystem units;
		std::string label;
	};

	std::vector<gearType> gearSpecifications;

	std::vector<gear> theGears;

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
	// define object location
	double objectX, objectY;

	Exporter exporter;

public:

	// addGear returns -1 if this is a new gear, else returns index of gear in vector 
	int addGear(double pitch, double pressureAngle, int teeth, int qty, HubShape hub, 
		double hubD1 = 0, double hubD2 = 0, UnitSystem units = inch) {
		gearType thisGear;
		// the specified gear is english
		if (units == inch) {
			thisGear.pitch = pitch;
			thisGear.module = 1 / (pitch * 25.4);
			// hub dimensions already in inches
			thisGear.hubD1 = hubD1;
			thisGear.hubD2 = hubD2;
		}
		// the specififed gear is metric (pitch input is actually module in [1/mm])
		else {
			thisGear.module = pitch;
			thisGear.pitch = 25.4 / pitch;
			// convert hub dimensions to inches
			thisGear.hubD1 = hubD1 / 25.4;
			thisGear.hubD2 = hubD2 / 25.4;
		}
		thisGear.pressureAngle = pressureAngle;
		thisGear.teeth = teeth;
		thisGear.qty = qty;
		thisGear.hub = hub;
		thisGear.units = units;
		thisGear.label = makeLabel(thisGear);


		// add the gear to specification vector only if it is not already there
		int gearIndex = gearExists(thisGear);
		if (gearIndex == -1)
			gearSpecifications.push_back(thisGear);
		else 
			gearSpecifications.at(gearIndex).qty++;
		// create gear object always
		gear thisGearForReal(thisGear.label, 2, 2, thisGear.pitch, pressureAngle, teeth, hub, thisGear.hubD1, thisGear.hubD2);
		theGears.push_back(thisGearForReal);

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
					gearSpecifications.at(i).hubD2 == thisGear.hubD2 &&
					gearSpecifications.at(i).units == thisGear.units) {
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
		gearType thisGear = gearSpecifications.at(index);
		
		// determine how many gears are going to be change
		// + if adding, - if removing
		int changeQty = qty - thisGear.qty;
		
		// adding gears
		while (changeQty > 0) {
			gear thisGearForReal(thisGear.label, 0, 0, thisGear.pitch,
				thisGear.pressureAngle, thisGear.teeth, thisGear.hub, thisGear.hubD1, thisGear.hubD2);
			theGears.push_back(thisGearForReal);
			changeQty--;
		}

		// removing gears
		int i = 0; 
		std::string a, b;
		while (changeQty < 0) {
			a = theGears.at(i).getLabel();
			b = thisGear.label;
			if (a == b) {
				int x = 5;
			}
			if (theGears.at(i).getLabel() == thisGear.label) {
				theGears.erase(theGears.begin() + i);
				changeQty++;
			}
			i++;
		}

		// update gear specification vector with new qty
		gearSpecifications.at(index).qty = qty;
	}

	std::string makeLabel(gearType thisGear) {
		std::stringstream label;
		if (thisGear.units == inch) {
			label << "P: ";
			label << thisGear.pitch;
		}
		else {
			label << "M: ";
			label << thisGear.module;
		}
		label << " PA: ";
		label << thisGear.pressureAngle;
		label << " T: ";
		label << thisGear.teeth;
		label << " Hub: ";
		switch (thisGear.hub) {
		case 0:
			label << "None";
			break;
		case 1:
			label << "Circle, Ø: ";
			if (thisGear.units == inch)
				label << thisGear.hubD1;
			else
				label << thisGear.hubD1 * 25.4;
			break;
		case 2:
			label << "Rectangle, W: ";
			if (thisGear.units == inch)
				label << thisGear.hubD1;
			else
				label << thisGear.hubD1 * 25.4;
			label << " H: ";
			if (thisGear.units == inch)
				label << thisGear.hubD2;
			else
				label << thisGear.hubD2 * 25.4;
			break;
		}
		return label.str();
	}

	std::string getLabel(int index) {
		return gearSpecifications.at(index).label;
	}

	std::vector<gear> getGearVector() {
		return theGears;
	}

	std::pair<double, double> getMaterialDimensions() {
		return { materialWidth, materialHeight };
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
		x += objectX;// *conversion;
		y += objectY;// *conversion;
		// apply scaling
		x *= conversion;
		y *= conversion;
		// move relative to origin of material
		x += originX;
		y += originY;
		// draw vertex

		glVertex2d(x, y);
	}


	// define the center of the object to be drawn, x and y in inches
	void setObjectCenter(double x, double y) {
		this->objectX = x;
		this->objectY = y;
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
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex2d(lx, by);
		glVertex2d(lx, ty);
		glVertex2d(rx, ty);
		glVertex2d(rx, by);
		glEnd();
	}

	void Export(std::string filename) {
		exporter.exportSVG(*this, filename);
	}

	//Optimizer
	std::vector<gear> setinitposition();
	std::vector<gear> optimize(std::vector<gear> Gears);
	std::vector<gear> center(std::vector<gear> Gears);
	bool checkintersection(std::vector<gear> Gears);
	// End Optimizer

	void draw();
};

#endif
