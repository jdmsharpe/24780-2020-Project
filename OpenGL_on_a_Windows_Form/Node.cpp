#include "Node.h"
#include "DrawingUtilNG.h"
//#include "ysglfontdata.h"
#include "ViewManager.h"
#include <vector>
//#include <gl\gl.h> 
//#include <gl\glu.h> 


using namespace std;



Node::Node(const string& aLabel, double xCoord, double yCoord, double zCoord, double defl)
{
	label = aLabel;
	x = xCoord; y = yCoord; z = zCoord;
	Radius = defl;
}


void Node::draw(Node node, bool showLabel)
{
	int size = 2;
	double halfSize = size * sqrt(2.);

	glBegin(GL_QUADS);

	double screenX, screenY, r;
	screenX = node.getX() + 0;
	screenY = -node.getY() + WINDOW_HEIGHT;
	r = node.getRadius();


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

	//glEnd();


	/*if (showLabel) {
		glRasterPos2i(screenX + 2 * size, screenY + 2 * size + 10);
		YsGlDrawFontBitmap6x10(label.c_str());
	}*/

}

