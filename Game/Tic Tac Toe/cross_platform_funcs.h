#ifndef _Liron486_SlEEP_FUNC_HPP_
#define _Liron486_SlEEP_FUNC_HPP_

#ifdef __linux
#include <unistd.h>
#elif __unix
#include <unistd.h>
#elif __posix
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#elif _WIN64
#include <windows.h>
#endif

namespace liron486
{
inline void MySleep(int sleepMs)
{
#ifdef __linux
    usleep(sleepMs * 1000);
#elif __unix
    usleep(sleepMs * 1000);
#elif __posix
    usleep(sleepMs * 1000);
#elif _WIN32
    Sleep(sleepMs);
#elif _WIN64
    Sleep(sleepMs);
#endif
}

inline void ClearScreen()
{
#ifdef __linux
    system("clear");
#elif __unix
    system("clear");
#elif __posix
    system("clear");
#elif _WIN32
    system("cls");
#elif _WIN64
    system("cls");
#endif
}

} // namespace liron486

#endif // _Liron486_SlEEP_FUNC_HPP_
