#ifndef WTRAYICON_H
#define WTRAYICON_H

#include "WBox.h"
#include <ShellAPI.h>

#define WM_WudimeiTray WM_USER+1
//using namespace WudimeiUI;

/*
 case WM_WudimeiTray:
        {
            if(wParam == IDI_ICON1){
                if(lParam == WM_LBUTTONDOWN){
                   //tray->deleteIcon();
                   tray->showInfo( TEXT("点了点"),TEXT("欢迎点"));
                   myForm->show();
                    return TRUE;
                }
            }


        }
        break;*/

namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WTrayIcon:public WBox
    {
        public:
            WTrayIcon();
            WTrayIcon(UINT _iconID);
            WTrayIcon(UINT _iconID,WBox *parent);
            virtual ~WTrayIcon();
            void prepareTrayIcon();
            void showInfo( LPCTSTR title, LPCTSTR content);
            void addIcon(LPCTSTR tip);
            void deleteIcon();

            NOTIFYICONDATA nid;
            UINT iconID;
            WBox *parent;
            UINT info_timeout;

        protected:
        private:
    };

  }
}
#endif // WTRAYICON_H
