#ifndef __MAIN_H__
#define __MAIN_H__


#ifndef WINVER  // ָ��Ҫ������ƽ̨�� Windows Vista��
#define WINVER 0x0501  // ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif
//

//define WINVER 0x0500 Windows 2000; 0x0501������ Windows XP����0x0502������ Windows Server 2003����0x0600������ Windows Vista���� 0x0601������ Windows 7����


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
