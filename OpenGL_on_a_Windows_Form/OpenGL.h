#pragma once

#include "ViewManager.h"

using namespace System::Windows::Forms;

namespace OpenGLForm
{
	//public ref class COpenGL : public System::Windows::Forms::NativeWindow
	public ref class COpenGL : public System::Windows::Forms::Panel
	{
	public:
		COpenGL::COpenGL(Form^ parentForm, GLsizei iXloc, GLsizei iYloc, GLsizei iWidth, GLsizei iHeight)
		{
			this->Top = iYloc;
			this->Left = iXloc;
			this->Width = iWidth;
			this->Height = iHeight;
			//this->Cursor = System::Windows::Forms::Cursors::Cross;  // change the way the cursor looks inside panel
			//this->Location = System::Drawing::Point(iXloc, iYloc);  // different way of setting location of panel

			//this->MouseEnter += gcnew System::EventHandler(this, &COpenGL::COpenGL_MouseEnter);
			//this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &COpenGL::COpenGL_OnKeyboard);
			//this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &COpenGL::COpenGL_MouseWheel);
			//this->MouseLeave += gcnew System::EventHandler(this, &COpenGL::COpenGL_MouseLeave);
			
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &COpenGL::COpenGL_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &COpenGL::COpenGL_MouseUp);
			//this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &COpenGL::COpenGL_MouseMove);

			// Specify the form as the parent so that we can access the parent's functions
			this->Parent = parentForm;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			this->CreateParams->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if (m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}

			theManager = new ViewManager();
		}

		System::Void Render(System::Void)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
			glLoadIdentity();									// Reset the current modelview matrix

			theManager->draw();
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		ViewManager* theManager;

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			this->Width = width;
			this->Height = height;
			if (height == 0) {										// Prevent A Divide By Zero By
				height = 1;										// Making Height Equal One
			}
			GLfloat aspect = (GLfloat)width / (GLfloat)height;

			glViewport(0, 0, width, height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			gluOrtho2D(0.0, width, 0.0, height);


			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}

	private:
		HDC m_hDC;
		HGLRC m_hglrc;

	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
			delete theManager;
		}

		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
				1,											// Version Number
				PFD_DRAW_TO_WINDOW |						// Format Must Support Window
				PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
				PFD_DOUBLEBUFFER,							// Must Support Double Buffering
				PFD_TYPE_RGBA,								// Request An RGBA Format
				16,											// Select Our Color Depth
				0, 0, 0, 0, 0, 0,							// Color Bits Ignored
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				16,											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// Main Drawing Layer
				0,											// Reserved
				0, 0, 0										// Layer Masks Ignored
			};

			GLint  iPixelFormat;

			// get the device context's best, available pixel format match 
			if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}

			return 1;
		}

		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(1.0f, 1.0f, 1.0f, 0.5f);			// Grey background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
			return TRUE;										// Initialisation went ok
		}

	private: System::Void COpenGL_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void COpenGL_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	};
}