#ifndef WBMP_H
#define WBMP_H
#include "WBox.h"

namespace Wudimei
{
  namespace UI{
    class DLL_EXPORT WBmp:public WBox
    {
        public:
            WBmp();
            WBmp(LPCTSTR path);
            void loadImageFile(LPCTSTR path);
            virtual void create();
            virtual ~WBmp();
        protected:
            void prepareBmp(void);
            TCHAR* path;
        private:

    };
  }
}
#endif // WBMP_H
