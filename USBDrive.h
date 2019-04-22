#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>
#include <dbt.h> 
#include <vector> 

#define REGISTRY_DISK_ENUM L"SYSTEM\\CurrentControlSet\\Services\\Disk\\Enum" 
#define REGISTRY_RTZ L"SOFTWARE\\RTZ" 
#define DRIVE_PREFIX "\\\\.\\%c:"
#define RADIX 10
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

char FirstDriveFromMask(ULONG unitmask);
void MessagePump(HWND hWnd);
void executeCommand(char* cmdPath, char* command);
boolean checkAuthorization(WCHAR* driveIdentifier);
void registerUSBDrives(WCHAR* driveIdentifier);
boolean readRegistry(boolean getWhiteList);
DWORD WINAPI checkIfEnabled();
void clearWhiteListVector();
void GetWhiteListDrives(HKEY hKey);

extern boolean enabled;

boolean DoRegisterDeviceInterfaceToHwnd(
	IN GUID InterfaceClassGuid,
	IN HWND hWnd,
	OUT HDEVNOTIFY *hDeviceNotify
);
void deviceArrival(int wParam, PDEV_BROADCAST_DEVICEINTERFACE lParam);
INT_PTR WINAPI WinProcCallback(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam
);