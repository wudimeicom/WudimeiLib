#include "../include/Wudimei/UI/WTextfield.h"

namespace Wudimei
{
  namespace UI{

    WTextfield::WTextfield()
    {
        this->prepareTextfield();
    }

    WTextfield::WTextfield(LPCTSTR text):WBox(text){
        this->prepareTextfield();
    }
    WTextfield::WTextfield(LPCTSTR text,WBox *parent):WBox(text,parent ){
        this->prepareTextfield();
    }
    WTextfield::WTextfield(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WBox(text,parent ,menuOrControlID){
        this->prepareTextfield();
    }

    void WTextfield::prepareTextfield(void){
         this->boxClassName = TEXT("edit");
        this->dwStyle = WS_CHILD | WS_VISIBLE | WS_BORDER ;
    }

    void WTextfield::copy(void){
        SendMessage(boxHandle,WM_COPY,0,0);
    }

    void WTextfield::cut(void){
        SendMessage(boxHandle,WM_CUT,0,0);
    }

    void WTextfield::clear(void){
        SendMessage(boxHandle,WM_CLEAR,0,0);
    }

    void WTextfield::paste(void){
        SendMessage(boxHandle,WM_PASTE,0,0);
    }
    void WTextfield::getSelectedRange(int *startPos,int *endPos){
        SendMessage(boxHandle,EM_GETSEL,(WPARAM)startPos,(LPARAM)endPos);
    }
    void WTextfield::setSelectedRange( int startPos,int endPos){
        SendMessage(boxHandle,EM_SETSEL,(WPARAM)startPos,(LPARAM)endPos);
    }

    void WTextfield::replace(LPCTSTR replacement){
        SendMessage(boxHandle,EM_REPLACESEL,0,(LPARAM)replacement );
    }


    WTextfield::~WTextfield()
    {
        //dtor
    }
  }
}
