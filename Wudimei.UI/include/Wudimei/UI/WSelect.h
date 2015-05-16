#ifndef WSELECT_H
#define WSELECT_H
#include "UI.h"
#include "WBox.h"

namespace Wudimei{
    namespace UI{

        class DLL_EXPORT WSelect:public WBox
        {
            public:
                WSelect();

                WSelect(LPCTSTR text);
                WSelect(LPCTSTR text,WBox *parent);
                WSelect(LPCTSTR text,WBox *parent,HMENU menuOrControlID );
                void addOption(LPCTSTR optionText);
                int getSelectedIndex(void);
                LPCTSTR getSelectedText(void);
                LPCTSTR getOptionText(int index);
                int getNumberOfOptions(void);
                void insertOption(int index,LPCTSTR optionText);
                void removeOption(int index);
                void removeAllOptions(void);
                virtual ~WSelect();
            protected:
            private:
                void prepareSelect(void);
                TCHAR *optionText;
        };
    }
}

#endif // WSELECT_H
