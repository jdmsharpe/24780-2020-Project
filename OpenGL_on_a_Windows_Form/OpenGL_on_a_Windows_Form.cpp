// OpenGL_on_a_Windows_Form.cpp : main project file.

#include "stdafx.h"
#include "GearWorksGUI.h"
#include <iostream>

using namespace OpenGL_on_a_Windows_Form;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew GearWorksGUI());
	return 0;
}



