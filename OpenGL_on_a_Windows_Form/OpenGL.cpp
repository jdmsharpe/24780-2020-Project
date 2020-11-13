#include "stdafx.h"
#include "OpenGLViewer.h"   // did not want to create #include loop by putting this in OpenGL.h
#include "OpenGL.h"

System::Void OpenGLForm::COpenGL::COpenGL_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{

	// casting class variable Parent as OpenGLViewer so that I can refer to its public members and functions
	((OpenGL_on_a_Windows_Form::OpenGLViewer^)Parent)->userFeedback->Text = "mouse " + e->Button.ToString() 
		+ "down on OpenGL Panel (" + e->X.ToString()
		+ ", " + e->Y.ToString() + ")";
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
		((OpenGL_on_a_Windows_Form::OpenGLViewer^)Parent)->playInsideSound();
	else if (e->Button == System::Windows::Forms::MouseButtons::Middle)
		((OpenGL_on_a_Windows_Form::OpenGLViewer^)Parent)->playOutsideSound();
	else
		((OpenGL_on_a_Windows_Form::OpenGLViewer^)Parent)->playThirdSound();

}
System::Void OpenGLForm::COpenGL::COpenGL_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{

	//MessageBox::Show("Just pushed mouse down on OpenGL");
	((OpenGL_on_a_Windows_Form::OpenGLViewer^)Parent)->userFeedback->Text = " - - -";

}
