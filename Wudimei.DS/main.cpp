


#include "include/Wudimei/DS/DS.h"
#include "include/Wudimei/DS/WNameList.h"
#include "include/Wudimei/DS/WMath.h"
#include "include/Wudimei/DS/WString.h"
#include "include/Wudimei/DS/WVector.h"
#include "include/Wudimei/DS/WDirectory.h"
#include "include/Wudimei/DS/WLinkList.h"




//#include  "include/WNameList.h"
//#include "src/WButton.cpp"
//#include "src/Box.cpp"
/*
ע��:����µ����Ҫclean��rebuitһ�¡�
name:һ��ʵ��һ��name,��name=>ʵ�����棬��������,������ʵ��set��ɾ��,get
LPCTSTR name;
WBox *box;

*/


extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:


            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
