
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <math.h>
#include <string>
#include <vector>
#include <filesystem> 
#include <windows.h>  
#include "DrawingUtilNG.h"
#include "fssimplewindow.h"
#include "StringPlus.h"
#include "Node.h"
#include "manager.h"


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
	tempNodes = aManager.setinitposition(theNodes);
	//optimizedNodes = tempNodes;
	optimizedNodes = aManager.optimize(tempNodes);
	int itr = 0;
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
		itr++;
		/*if (itr > 5)
		{
			break;
		}*/
	}

	aManager.draw(optimizedNodes);

	//for (int i = 0; i < optimizedNodes.size(); i++)
	//{
	//	optimizedNodes[i].draw(optimizedNodes[i],0);
	//}

	FsSwapBuffers();
	FsPollDevice();

	cout << "\t\t Press ENTER to close console" << endl;

	while (getchar() != '\n');
	getchar();
}


