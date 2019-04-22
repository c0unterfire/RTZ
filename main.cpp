#include "veracrypt.h"
#include "USBDrive.h"

PWSTR g_pszAppName;
#define WND_CLASS_NAME TEXT("ReturnToZero")

boolean InitWindowClass()
{
	WNDCLASSEX wndClass;

	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wndClass.hInstance = reinterpret_cast<HINSTANCE>(GetModuleHandle(0));
	wndClass.lpfnWndProc = reinterpret_cast<WNDPROC>(WinProcCallback);
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wndClass.hbrBackground = CreateSolidBrush(RGB(192, 192, 192));
	wndClass.hCursor = LoadCursor(0, IDC_ARROW);
	wndClass.lpszClassName = WND_CLASS_NAME;
	wndClass.lpszMenuName = NULL;
	wndClass.hIconSm = wndClass.hIcon;
	
	if (!RegisterClassEx(&wndClass))
	{
		return false;
	}
	return true;
}

int wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	int nArgC = 0;
	PWSTR* ppArgV = CommandLineToArgvW(pCmdLine, &nArgC);
	g_pszAppName = ppArgV[0];
	enabled = readRegistry(true);

	CreateThread(
		NULL,                   // default security attributes
		0,                      // use default stack size  
		(LPTHREAD_START_ROUTINE)checkIfEnabled,       // thread function name
		0,	// argument to thread function 
		0,	// use default creation flags 
		0);	// returns the thread identifier 

	if (!InitWindowClass())
	{
		return -1;
	}

	HWND hWnd = CreateWindowEx(
		WS_EX_CLIENTEDGE | WS_EX_APPWINDOW,
		WND_CLASS_NAME,
		g_pszAppName,
		WS_OVERLAPPEDWINDOW, // style
		CW_USEDEFAULT, 0,
		640, 480,
		NULL, NULL,
		hPrevInstance,
		NULL);

	if (hWnd == NULL)
	{
		return -1;
	}

	MessagePump(hWnd);
}