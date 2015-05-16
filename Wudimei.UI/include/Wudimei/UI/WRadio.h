#ifndef WRADIO_H
#define WRADIO_H

#include "WBox.h"
#include "WGroupBox.h"

namespace Wudimei
{
  namespace UI{
    class DLL_EXPORT WRadio : public WBox
    {
        public:
            WRadio();
            WRadio(LPCTSTR text);
            WRadio(LPCTSTR text,WBox *parent);
            WRadio(LPCTSTR text,WBox *parent,HMENU menuOrControlID );

            virtual ~WRadio();

            void check();
            void uncheck();
            bool checked();
        protected:
        private:
            void prepareRadio();
    };
  }
}
#endif // WRADIO_H
