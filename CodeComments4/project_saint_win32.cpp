/*****************************************************
 * Project_Saint Source Code
 * Platform: Win32 
 * Date: June 24nd, 2017.
 * Objective: 
 * Create and Open Main Project_Saint Win32 Window. (Display White Screen)
 *
 * ******    NOTE   ******************************************************** 
 * Use of PatBlt function introduced
 * Error LNK2019 resolution:
 * PatBlt requires a library gdi32.lib
 * Modify project_saint\misc\build.bat line:
 * cl /Zi ..\project_saint\code\project_saint_win32.cpp user32.lib gdi32.lib
 * 
 * https://hero.handmade.network/forums/code-discussion/t/611-day_11,__error_lnk2019:_unresolved_external_symbol
 *
 * **************************************************************************
 *
 * Main Resource: https://developer.microsoft.com/en-us/windows/desktop/develop
 * ****************************************************/

#include <windows.h> 
//This is header file (.h extension) It contains Windows specific declarations


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);
// An application-defined function that processes messages sent to a window.

// The user-provided entry point for a graphical Windows-based application
int CALLBACK WinMain
		(HINSTANCE hInstance,
		 HINSTANCE hPrevInstance,
		 LPSTR lpCmdLine,
		 int  nCmdShow
		) 
 {
	//TCHAR A Win32 character string that can be used to describe ANSI, DBCS, or Unicode strings. 
	static TCHAR szAppName[] =TEXT ("Program_Window");

	// A Windows window is identified by a "window handle" ( HWND )
	HWND 		hwnd;

	// Contains message information from the Window's message queue.
	MSG  		msg;

	//A structure which contains the window class attributes that must be registered
	WNDCLASS	wndclass; 

	wndclass.style 		= CS_OWNDC|CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc 	= WndProc ;
	wndclass.cbClsExtra 	= 0 ;
	wndclass.cbWndExtra 	= 0 ;
	wndclass.hInstance 	= hInstance ;
	wndclass.hIcon 		= LoadIcon (NULL, IDI_APPLICATION) ;
	wndclass.hCursor 	= LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground 	= NULL ;
	wndclass.lpszMenuName 	= NULL ;
	wndclass.lpszClassName 	= szAppName ;
        
	// RegisterClass Function - 
	// Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.
	if(!RegisterClass (&wndclass))
	{
		MessageBox (NULL, TEXT("A fatal error has occurred!"), //A message box for the error case
				szAppName, MB_ICONERROR);
		return 0;
	}
        
	// Creates an overlapped, pop-up, or child window with an extended window style; 
	// otherwise, this function is identical to the CreateWindow function.
	hwnd = CreateWindowEx (
			0,                              	// Extended window styles (not used)
			szAppName,             			// window class name
			TEXT ("Project_Saint_Win32"), 		// window caption
			WS_OVERLAPPEDWINDOW | WS_VISIBLE, 	// window style
			CW_USEDEFAULT, 				// initial x position
			CW_USEDEFAULT, 				// initial y position
			CW_USEDEFAULT, 				// initial x size
			CW_USEDEFAULT, 				// initial y size
			NULL, 					// parent window handle
			NULL, 					// window menu handle
			hInstance, 				// program instance handle
			NULL					// A pointer to a value to be passed to the window                		         			          // through the CREATESTRUCT structure
			) ; // creation parameters
        if(!hwnd)
	{
		MessageBox (NULL, TEXT("A fatal error has occurred!"), //A message box for the error case
				szAppName, MB_ICONERROR);
		return 0;
	}

        // Sets the specified window's show state
	ShowWindow (hwnd, nCmdShow) ;
        // nCmdShow controls how the window is to be shown. 
	// Minimized, Hidden or Maximized
         
	UpdateWindow (hwnd);
        //The UpdateWindow function updates the client area of the specified window by sending a WM_PAINT message 
	//to the window if the window's update region is not empty. 
	//The function sends a WM_PAINT message directly to the window procedure of the specified window, 
	//bypassing the application queue. 
	//If the update region is empty, no message is sent.
	
	//GetMessage Function - Retrieves a message from the calling thread's message queue. 
	//The function dispatches incoming sent messages until a posted message is available for retrieval.
	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg) ;
		// Translates virtual-key messages into character messages. 
		// The character messages are posted to the calling thread's message queue, 
		// to be read the next time the thread calls the GetMessage or PeekMessage function.


		DispatchMessage (&msg) ;
		// Dispatches a message to a window procedure. 
		// It is typically used to dispatch a message retrieved by the GetMessage function.
	}
	return msg.wParam ; //Additional information about the message. 
			    //The exact meaning depends on the value of the message member.

}// End WinMain Function


// Your application-defined function that processes messages sent to a window. 
// The WNDPROC type defines a pointer to this callback function
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
        
	//Signed result of message processing
	LRESULT 	Result = 0; 
	switch(message)
	{
		case WM_PAINT: //The WM_PAINT message is sent when the system or another application 
			       //makes a request to paint a portion of an application's window
		{

			// Applies to: desktop apps only
			// Creates a Graphics::Graphics object that is associated with a specified device context       
			HDC 		hdc;

			// The PAINTSTRUCT structure contains information for an application. 
			// This information can be used to paint the client area of a window owned by that application.
			PAINTSTRUCT 	ps;
	
			// RECT structure defines the coordinates of the upper-left and lower-right corners rectangle 
			// In this case we use it for the client area rectangle of our window
			RECT		rect;
	
		hdc = BeginPaint(hwnd, &ps);
		// The BeginPaint function prepares the specified window for painting and 
		// fills a PAINTSTRUCT structure with information about the painting.
		
		GetClientRect(hwnd, &rect);
		// Retrieves the coordinates of a window's client area. 
		// The client coordinates specify the upper-left and lower-right corners of the client area. 
		// Because client coordinates are relative to the upper-left corner of a window's client area, 
		// the coordinates of the upper-left corner are (0,0)

		// The PatBlt function paints the specified rectangle using the brush that is currently selected 
		// into the specified device context. 
		// The brush color and the surface color or colors are combined by using the specified raster operation.
		   int XLeft = ps.rcPaint.left;   //The x-coordinate, in logical units, 
		                                   //of the upper-left corner of the rectangle to be filled
		   int YLeft = ps.rcPaint.top;    //The y-coordinate, in logical units, 
		   				   //of the upper-left corner of the rectangle to be filled.
                   int Width = ps.rcPaint.right - ps.rcPaint.left; //Width of Application Window
		   int Height = ps.rcPaint.bottom -ps.rcPaint.top; //Height of window
		   PatBlt(
				 hdc,
				 XLeft,
				 YLeft,
				 Width,
				 Height,
				 WHITENESS
			 );
		// We are not writing text to the client area anymore
		// DrawText(hdc, TEXT("Hello World from Windows!"), -1, &rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);

		// The EndPaint function marks the end of painting in the specified window. 
		// This function is required for each call to the BeginPaint function, 
		// but only after painting is complete.
		EndPaint(hwnd, &ps);
		return (0);
		}
		
		// The following cases are Window Notification Messages
		// They are sent when the status of the active window, in this our application window
		// is about to be changed in some way.
		// These cases are included for possible future implementation. 

		case WM_DESTROY:  // Sent when a window is being destroyed
		                  // It is sent to the window procedure of the window being destroyed 
				  // after the window is removed from the screen.
		{
		// Indicates to the system that a thread has made a request to terminate (quit). 
		// It is typically used in response to a WM_DESTROY message.	
		PostQuitMessage(0);
		return(0);
		}
		case WM_SIZE:
		{
			//Sent to a window after its size has changed

		return(0);	
		}
		case WM_CLOSE:
		{
                        //Sent as a signal that a window or an application should terminate

		return(0);
		}
		case WM_ACTIVATEAPP:
		{
                        //Sent when a window belonging to a different application than the active window 
			//is about to be activated. 
			//The message is sent to the application whose window is being activated 
			//and to the application whose window is being deactivated.    

		return(0);
		}
		default:
		{	
			//Calls the default window procedure to provide default processing for any window messages 
			//that an application does not process. 
			//This function ensures that every message is processed. 
			//DefWindowProc is called with the same parameters received by the window procedure
			Result = DefWindowProc(hwnd, message, wParam,lParam);
		}break;
	}
	return(Result);

}// End WndProc Function
/************************************************************************************************
 *
 * Step-by-step links
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms633548(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms632600(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms632680(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/dd145167(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms644936(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms644955(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms644934(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms644958(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms632590(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms633573(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms536160(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/dd162768(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/dd162897(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms633572(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/dd183362(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms633503(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/dd162498(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/dd162598(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms632620(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms644945(v=vs.85).aspx
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms644945(v=vs.85).aspx
 * Window Notifications
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ff468922(v=vs.85).aspx
 *
 *
 *
 * **********************************************************************************************/
