#ifndef WFORM_H
#define WFORM_H
#include "WBox.h"
//using namespace WudimeiUI;
namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WForm:public WBox
    {
        public:
            WForm();
            virtual ~WForm();
            void create();
            static LRESULT CALLBACK handle_event(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
            WNDCLASS windowClass;
            //MSG msg;
        protected:

        private:
    };
  }
}
#endif // WFORM_H
