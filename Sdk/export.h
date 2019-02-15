#ifndef EXPORT_H
#define EXPORT_H

#ifdef SDK_LIBRARY_EXPORT
#define SDKSHARED_EXPORT __declspec(dllexport)
#else
#define SDKSHARED_EXPORT __declspec(dllimport)
#endif


#endif // EXPORT_H
