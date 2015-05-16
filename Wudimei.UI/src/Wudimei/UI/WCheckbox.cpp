#include "../include/Wudimei/UI/WCheckbox.h"

namespace Wudimei
{
  namespace UI{

    WCheckbox::WCheckbox()
    {
        this->prepareCheckbox();
    }

    WCheckbox::WCheckbox(LPCTSTR text):WBox(text){
        this->prepareCheckbox();
    }

    WCheckbox::WCheckbox(LPCTSTR text,WBox *parent):WBox(text,parent ){
        this->prepareCheckbox();
    }

    WCheckbox::WCheckbox(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WBox(text,parent ,menuOrControlID) {
        this->prepareCheckbox();
    }


    WCheckbox::~WCheckbox()
    {
        //dtor
    }
    void WCheckbox::prepareCheckbox(){
        this->boxClassName = TEXT("BUTTON");
        this->dwStyle = WS_VISIBLE | WS_CHILD|BS_AUTOCHECKBOX ;
    }

    void WCheckbox::check(){
        SendMessage( this->boxHandle, BM_SETCHECK,BST_CHECKED,0);//lparam no used
    }

    void WCheckbox::uncheck(){
       SendMessage( this->boxHandle, BM_SETCHECK,BST_UNCHECKED,0);
    }

    bool WCheckbox::checked(){
        if( SendMessage(this->boxHandle, BM_GETCHECK,0,0) == BST_CHECKED )
        {
            return true;
        }
        else{
            return false;
        }
    }
  }
}
