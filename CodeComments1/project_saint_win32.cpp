/*****************************************************
 * Project_Saint Source Code
 * Platform: Win32 
 * Date: June 22nd, 2017.
 * Objective: 
 * Create a Message Box displaying "Hello World!" and titled "Project_Saint"
 * 
 * ****************************************************/

#include <windows.h> 
//This is header file (.h extension) It contains Windows specific declarations


int CALLBACK
	WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	MessageBox(0,"Hello World!", "Project_Saint",
			MB_OK|MB_ICONINFORMATION);
	return(0);
}

/*******************************************************
 * Step-by-Step comments
 *
 * #include <windows.h> is a master include file that includes
 * other Windows header files. 
 * See more information here: 
 * https://www.tutorialspoint.com/cprogramming/c_header_files.htm
 *  
 * Read up about functions first before looking at the next part
 * https://www.tutorialspoint.com//cprogramming/c_functions.htm
 *
 * int CALLBACK WinMain(...) this means that WinMain is a function that is
 * CALLed BACK from other functions at other levels of the windows operating system
 * It's final return type is of type integer 
 *
 * You should now be comfortable enough to view the Microsoft Documentation on the code
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms633559(v=vs.85).aspx
 *
 * MSDN documentation for the MessageBox function
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms645505(v=vs.85).aspx
 * 
 * ********************************************************/
