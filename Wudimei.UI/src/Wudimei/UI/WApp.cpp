#ifndef WApp_CPP
#define WApp_CPP

#include "../include/Wudimei/UI/WApp.h"

namespace Wudimei
{
  namespace UI{

    HINSTANCE WApp::hInstance=NULL;
    HINSTANCE WApp::hPrevInstance=NULL;
    PSTR WApp::szCmdLine = NULL;
    int WApp::iCmdShow=0;

    WApp::WApp()
    {
        //ctor
    }

    WApp::~WApp()
    {
        //dtor
    }
     int WApp::run(void){
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return msg.wParam;
     }

     void WApp::storeMainArgs(HINSTANCE hInstance2, HINSTANCE hPrevInstance2,PSTR szCmdLine2, int iCmdShow2)
     {
        WApp::hInstance = hInstance2;
        WApp::hPrevInstance = hPrevInstance2;
        WApp::szCmdLine = szCmdLine2;
        Wudimei::UI::WApp::iCmdShow = iCmdShow2;

     }
  }
}
#endif
