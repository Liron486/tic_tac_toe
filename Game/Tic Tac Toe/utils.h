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

#include <thread>
#include <string>


namespace Liron486
{
inline bool compareChars(const char& a, const char& b)
{
    return (std::tolower(a) == std::tolower(b));
}

inline bool compareStrings(const std::string& first, const std::string& second)
{
    return std::equal(first.begin(), first.end(), second.begin(), compareChars);
}

inline void MySleep(int sleepMs)
{
    auto time = std::chrono::milliseconds(sleepMs);
    std::this_thread::sleep_for(time);
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
