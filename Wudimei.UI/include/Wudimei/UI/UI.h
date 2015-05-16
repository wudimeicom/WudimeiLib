#ifndef __MAIN_H__
#define __MAIN_H__


#ifndef WINVER  // 指定要求的最低平台是 Windows Vista。
#define WINVER 0x0501  // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif
//

//define WINVER 0x0500 Windows 2000; 0x0501（用于 Windows XP）、0x0502（用于 Windows Server 2003）、0x0600（用于 Windows Vista）和 0x0601（用于 Windows 7）。


#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif


#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
