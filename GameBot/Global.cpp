#include<afxwin.h>
#include "Global.h"
static const unsigned __int64 epoch = 116444736000000000L;

/**
* timezone information is stored outside the kernel so tzp isn't used anymore.
*/


int gettimeofday(struct timeval * tp,void * tzp)
{
	FILETIME    file_time;
	SYSTEMTIME  system_time;
	ULARGE_INTEGER ularge;

	GetSystemTime(&system_time);
	SystemTimeToFileTime(&system_time, &file_time);
	ularge.LowPart = file_time.dwLowDateTime;
	ularge.HighPart = file_time.dwHighDateTime;

	tp->tv_sec = (long) ((ularge.QuadPart - epoch) / 10000000L);
	tp->tv_usec = (long) (system_time.wMilliseconds * 1000);

	return 0;
}