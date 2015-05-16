#ifndef WIMAGELIST_H
#define WIMAGELIST_H
#include <windows.h>

#include "./UI.h"
#include <commctrl.h>
#include "WBox.h"
//using namespace WudimeiUI;
namespace Wudimei
{
  namespace UI{
    class DLL_EXPORT WImageList
    {
        public:
            WImageList();
            WImageList(int width,int height);
            WImageList(LPCTSTR szIconSize);//_T("standard") _T("small")

            void prepareImageList(int width,int height);
            HIMAGELIST getImageList(void);
            void loadIcon(int iconId );
            void  loadIcon(int iconId ,HINSTANCE hInst );
            virtual ~WImageList();

        protected:
        private:
            HICON hIconItem;
            HIMAGELIST hImageList;
    };
  }
}
#endif // WIMAGELIST_H
