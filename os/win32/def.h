#ifndef __WIN32_H__
#define __WIN32_H__

#ifdef _WIN32

#include <windows.h>

#define _WIN32_INPUT_BUFFER 128

#define ENABLE_QUICK_EDIT_MODE 0x0040
#define ENABLE_EXTENDED_FLAGS 0x0080

HANDLE hStdin; // Input buffer handle
DWORD cNumRead, fdwMode, i; // Number of records read, window mode and event counter
INPUT_RECORD irInBuf[_WIN32_INPUT_BUFFER]; // Buffer to read into

#endif

#endif
