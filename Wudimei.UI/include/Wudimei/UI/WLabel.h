#ifndef CLABEL_H
#define CLABEL_H

#include "WBox.h"

#include "./UI.h"

namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WLabel : public WBox
    {
        public:
            WLabel();
            WLabel(LPCTSTR text);
            WLabel(LPCTSTR text,WBox *parent);
            WLabel(LPCTSTR text,WBox *parent,HMENU menuOrControlID );

            virtual ~WLabel();
        protected:
        private:
            void prepareLabel();
    };
  }
}

#endif // CLABEL_H
