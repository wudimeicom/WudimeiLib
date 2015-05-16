#ifndef WAPP_H
#define WAPP_H
#include <windows.h>
#include "./UI.h"

namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WApp
    {
        public:
            WApp();
            virtual ~WApp();
            int run(void);
            static void storeMainArgs(HINSTANCE hInstance2, HINSTANCE hPrevInstance2,PSTR szCmdLine2, int iCmdShow2);
            MSG msg;

            static HINSTANCE hInstance;
            static HINSTANCE hPrevInstance;
            static PSTR szCmdLine;
            static int iCmdShow;

        protected:
        private:
    };
  }
}

#endif // WAPP_H
