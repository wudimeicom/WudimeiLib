#ifndef WLISTBOX_H
#define WLISTBOX_H
#include "WBox.h"

namespace Wudimei{
    namespace UI{
        class DLL_EXPORT WListBox:public WBox
        {
            public:
                WListBox();
                virtual ~WListBox();
                void addOption(LPCTSTR text);
                void insertOption(int index,LPCTSTR text);
                int getSelectedIndex(void);
                void removeOption(int index);
                int* getSelectedItems(void);
                int getSelectedNumber(void);
                LPCTSTR getOptionText(int index);
            protected:
            private:
                void prepareListBox(void);
                int *selectedItems;
                TCHAR *optionText;
        };
    }
}
#endif // WLISTBOX_H
