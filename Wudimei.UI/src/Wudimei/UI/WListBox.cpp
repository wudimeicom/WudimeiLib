#include "../include/Wudimei/UI/WListBox.h"

namespace Wudimei{
    namespace UI{
        WListBox::WListBox()
        {
            this->prepareListBox( );
        }

        void WListBox::addOption(LPCTSTR text){
            SendMessage( boxHandle,LB_ADDSTRING,0,(LPARAM)text);
        }

        void WListBox::insertOption(int index,LPCTSTR text){
            SendMessage( boxHandle,LB_INSERTSTRING,index,(LPARAM)text);
        }

        int WListBox::getSelectedIndex(void){
            return SendMessage( boxHandle ,LB_GETCURSEL,0,0);
        }

        void WListBox::removeOption(int index){
            SendMessage(boxHandle,LB_DELETESTRING,(WPARAM)index,0);
        }

        int* WListBox::getSelectedItems(void){
            int selectedCount = this->getSelectedNumber();
            int oldLen =sizeof(selectedItems)/sizeof(int);
            if( oldLen<selectedCount )
            {
                delete[] selectedItems;
                selectedItems = new int[selectedCount];
            }
            SendMessage(boxHandle,LB_GETSELITEMS,(WPARAM)selectedCount,(LPARAM)selectedItems);
            return selectedItems;
        }

        int WListBox::getSelectedNumber(void){
            return SendMessage(boxHandle, LB_GETSELCOUNT , 0,0);
        }

        LPCTSTR WListBox::getOptionText(int index){

            SendMessage(boxHandle,LB_GETTEXT,index,(LPARAM)optionText);
            return optionText;
        }

        WListBox::~WListBox()
        {

        }

        void WListBox::prepareListBox(void){
            this->boxClassName = TEXT("ListBox");
            this->dwStyle = WS_CHILD|WS_VISIBLE |WS_BORDER |WS_VSCROLL|LBS_EXTENDEDSEL ;
            selectedItems=new int[1] ;
            optionText = new TCHAR[256];
            ZeroMemory((LPVOID)optionText,sizeof(optionText));
        }
    }
}
