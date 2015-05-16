#include "../include/Wudimei/UI/WRadio.h"

namespace Wudimei
{
  namespace UI{

    WRadio::WRadio()
    {
        this->prepareRadio();
    }

    WRadio::WRadio(LPCTSTR text):WBox(text){
        this->prepareRadio();
    }

    WRadio::WRadio(LPCTSTR text,WBox *parent):WBox(text,parent ){
        this->prepareRadio();
    }

    WRadio::WRadio(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WBox(text,parent ,menuOrControlID) {
        this->prepareRadio();
        this->setText( text );
    }



    WRadio::~WRadio()
    {
        //dtor
    }
    void WRadio::prepareRadio(){
        this->boxClassName = TEXT("BUTTON");
        this->dwStyle = WS_VISIBLE | WS_CHILD|BS_AUTORADIOBUTTON ;
    }

    void WRadio::check(){
        SendMessage( this->boxHandle, BM_SETCHECK,BST_CHECKED,0);//lparam no used
    }

    void WRadio::uncheck(){
       SendMessage( this->boxHandle, BM_SETCHECK,BST_UNCHECKED,0);
    }

    bool WRadio::checked(){
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
