#include <windows.h>  
#include "DrawingUtilNG.h"
#include "fssimplewindow.h"
#include "StringPlus.h"
#include "Node.h"
#include "ViewManager.h"


using namespace std;
ViewManager aManager;

int main(void)
{
	bool optimized = false;
	srand(time(NULL));
	vector <Node> theNodes;
	vector <Node> optimizedNodes;
	vector <Node> tempNodes;
	int panChange = 8;
	float zoomFactor = 1.1;

	FsOpenWindow(16, 16, WINDOW_WIDTH, WINDOW_HEIGHT, 1, "Alpha Code");
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	int leftButton, middleButton, rightButton, mouseEvent;
	int locX, locY;


	double ScreenX, ScreenY, x, y;
	FsPollDevice();

	mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, locX, locY);
	ScreenX = locX;
	ScreenY = locY;

	theNodes = aManager.fileread();

	Node aNode;

	FsSwapBuffers();
	FsPollDevice();
	tempNodes = aManager.center(theNodes);

	optimizedNodes = aManager.optimize(tempNodes);

	while (!optimized)
	{

		optimized = aManager.checkintersection(optimizedNodes);
		if (optimized)
		{
			break;
		}
		else
		{
			tempNodes = optimizedNodes;
		}

		optimizedNodes = aManager.optimize(tempNodes);

	}

	aManager.draw(optimizedNodes);

	for (int i = 0; i < optimizedNodes.size(); i++)
	{
		optimizedNodes[i].draw(optimizedNodes[i], 0);
	}

	FsSwapBuffers();
	FsPollDevice();

	cout << "\t\t Press ENTER to close console" << endl;

	while (getchar() != '\n');
	getchar();
}