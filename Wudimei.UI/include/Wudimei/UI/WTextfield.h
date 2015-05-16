#ifndef WTEXTFIELD_H
#define WTEXTFIELD_H

#include "WBox.h"

namespace Wudimei
{
  namespace UI{
    class DLL_EXPORT WTextfield : public WBox
    {
        public:
            WTextfield();

            WTextfield(LPCTSTR text);
            WTextfield(LPCTSTR text,WBox *parent);
            WTextfield(LPCTSTR text,WBox *parent,HMENU menuOrControlID );
            void copy(void);
            void cut(void);
            void clear(void);
            void paste(void);
            void getSelectedRange(int *startPos,int *endPos);
            void setSelectedRange( int startPos,int endPos);
            void replace(LPCTSTR replacement);
            virtual ~WTextfield();
        protected:
        private:
            void prepareTextfield(void);
    };
  }
}
#endif // WTEXTFIELD_H
