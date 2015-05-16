#ifndef WTEXTAREA_H
#define WTEXTAREA_H

#include "WBox.h"
#include "WTextfield.h"
namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WTextarea : public WBox
    {
        public:
            WTextarea();
            WTextarea(LPCTSTR text);
            WTextarea(LPCTSTR text,WBox *parent);
            WTextarea(LPCTSTR text,WBox *parent,HMENU menuOrControlID );
            void copy(void);
            void cut(void);
            void clear(void);
            void paste(void);
            void getSelectedRange(int *startPos,int *endPos);
            void setSelectedRange( int startPos,int endPos);
            void replace(LPCTSTR replacement);

            int getLineCount(void);
            int getLineOffset(int line);
            int getLineLength(int line);
            LPCTSTR getLine(int line);//error
            virtual ~WTextarea();
        protected:
        private:
            void prepareTextarea();
            TCHAR* lineText;
    };
  }
}
#endif // WTEXTAREA_H
