#ifndef WCheckbox_H
#define WCheckbox_H

#include "WBox.h"
#include "WGroupBox.h"

namespace Wudimei
{
  namespace UI{
    class DLL_EXPORT WCheckbox : public WBox
    {
        public:
            WCheckbox();
            WCheckbox(LPCTSTR text);
            WCheckbox(LPCTSTR text,WBox *parent);
            WCheckbox(LPCTSTR text,WBox *parent,HMENU menuOrControlID );

            virtual ~WCheckbox();

            void check();
            void uncheck();
            bool checked();
        protected:
        private:
            void prepareCheckbox();
    };
  }
}
#endif // WRADIO_H
