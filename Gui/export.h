#ifndef EXPORT_H
#define EXPORT_H

#ifdef GUI_LIBRARY_EXPORT
#define GUISHARED_EXPORT __declspec(dllexport)
#else
#define GUISHARED_EXPORT __declspec(dllimport)
#endif


#endif // EXPORT_H
