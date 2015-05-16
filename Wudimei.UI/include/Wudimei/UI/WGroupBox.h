#ifndef WGROUPBOX_H
#define WGROUPBOX_H

#include "WBox.h"

namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WGroupBox : public WBox
    {
        public:
            WGroupBox();
            WGroupBox(LPCTSTR text);
            WGroupBox(LPCTSTR text,WBox *parent);
            WGroupBox(LPCTSTR text,WBox *parent,HMENU menuOrControlID );

            virtual ~WGroupBox();
        protected:
        private:
            void prepareGroupBox(void);
    };
  }
}

#endif // WGROUPBOX_H
