#ifndef OS_H
#define OS_H

#if defined(_WIN32) || defined(_WIN64)
    #define _OS_WIN_
#endif
#if defined(unix) || defined(__unix) || defined(__unix__) || defined(__linux__) || defined(linux) || defined(__linux)
    #define _OS_UNIX_
#endif
#if defined(__APPLE__) || defined(__MACH__)
    #define _OS_MAC
#endif

#endif // OS_H

