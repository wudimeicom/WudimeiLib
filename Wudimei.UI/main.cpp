
#include "include/Wudimei/UI/UI.h"



#include "include/Wudimei/UI/WApp.h"
#include "include/Wudimei/UI/WBox.h"
#include "include/Wudimei/UI/WControl.h"
#include "include/Wudimei/UI/WButton.h"
#include "include/Wudimei/UI/WForm.h"
#include "include/Wudimei/UI/WTextfield.h"
#include "include/Wudimei/UI/WTextarea.h"
#include "include/Wudimei/UI/WGroupBox.h"
#include "include/Wudimei/UI/WRadio.h"
#include "include/Wudimei/UI/WLabel.h"
#include "include/Wudimei/UI/WCheckbox.h"
#include "include/Wudimei/UI/WSelect.h"
#include "include/Wudimei/UI/WListBox.h"
#include "include/Wudimei/UI/WImageList.h"
#include "include/Wudimei/UI/WListView.h"
#include "include/Wudimei/UI/WSlider.h"
#include "include/Wudimei/UI/WDateTimePicker.h"
#include "include/Wudimei/UI/WTrayIcon.h"




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
