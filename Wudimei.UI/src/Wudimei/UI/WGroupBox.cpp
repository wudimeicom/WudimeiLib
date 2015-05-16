#include "../include/Wudimei/UI/WGroupBox.h"

namespace Wudimei
{
  namespace UI{
    WGroupBox::WGroupBox()
    {
        this->prepareGroupBox();
    }

    WGroupBox::WGroupBox(LPCTSTR text):WBox(text){
        this->prepareGroupBox();
    }

    WGroupBox::WGroupBox(LPCTSTR text,WBox *parent):WBox(text,parent ){
        this->prepareGroupBox();
    }

    WGroupBox::WGroupBox(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WBox(text,parent ,menuOrControlID){
        this->prepareGroupBox();
    }

    void WGroupBox::prepareGroupBox(void){
        this->boxClassName = TEXT("BUTTON");
        this->dwStyle = WS_VISIBLE | WS_CHILD|BS_GROUPBOX ;
    }

    WGroupBox::~WGroupBox()
    {
        //dtor
    }
  }
}
