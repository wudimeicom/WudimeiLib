#include "../include/Wudimei/UI/WSelect.h"

//http://blog.csdn.net/qiurisuixiang/article/details/6746234
namespace Wudimei{
    namespace UI{

         WSelect::WSelect()
        {
            this->prepareSelect();
        }

        WSelect::WSelect(LPCTSTR text):WBox(text){
            this->prepareSelect();
        }
        WSelect::WSelect(LPCTSTR text,WBox *parent):WBox(text,parent ){
            this->prepareSelect();
        }
        WSelect::WSelect(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WBox(text,parent ,menuOrControlID){
            this->prepareSelect();
        }

        void WSelect::prepareSelect(void){
            this->boxClassName = TEXT("combobox");
            this->dwStyle = CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE ;

            optionText=new TCHAR[256];
           // optionText[2]='\0';
            ZeroMemory(optionText,sizeof(optionText));
        }

        void WSelect::addOption(LPCTSTR optionText){
            SendMessage(boxHandle,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) optionText);
        }

        int WSelect::getSelectedIndex(void){
            int idx = SendMessage(boxHandle, (UINT) CB_GETCURSEL, (WPARAM) 0, (LPARAM) 0);
            return idx;
        }

        LPCTSTR WSelect::getOptionText(int index){

            if( CB_ERR == SendMessage(boxHandle, (UINT)CB_GETLBTEXT,(WPARAM) index, (LPARAM)optionText) )
            {
                return NULL;
            }
            //MessageBox(NULL,optionText,_T("a"),MB_OK);
            return optionText;
        }

        LPCTSTR WSelect::getSelectedText(void){
            int idx = this->getSelectedIndex();
            return this->getOptionText(idx);
        }

        int WSelect::getNumberOfOptions(void){
            UINT uCount = SendMessage(boxHandle, CB_GETCOUNT, 0, 0);
            return (int)uCount;
        }

        void WSelect::insertOption(int index,LPCTSTR optionText){
            SendMessage(boxHandle , CB_INSERTSTRING, index, (LPARAM)optionText);

        }

        void WSelect::removeOption(int index){
            SendMessage(boxHandle , CB_DELETESTRING, index, 0);
        }

        void WSelect::removeAllOptions(void){
            SendMessage(boxHandle , CB_RESETCONTENT, 0, 0);
        }

        WSelect::~WSelect()
        {
            //dtor
        }
    }
}

