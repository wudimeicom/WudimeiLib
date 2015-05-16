#include "../include/Wudimei/UI/WLabel.h"


namespace Wudimei
{
  namespace UI{
    WLabel::WLabel()
    {
        this->prepareLabel();
    }


    WLabel::WLabel(LPCTSTR text):WBox(text){
        this->prepareLabel();
    }
    WLabel::WLabel(LPCTSTR text,WBox *parent):WBox(text,parent ){
        this->prepareLabel();
    }
    WLabel::WLabel(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WBox(text,parent ,menuOrControlID){
        this->prepareLabel();
    }
    void WLabel::prepareLabel(){
        this->boxClassName = TEXT("STATIC");
        this->dwStyle = WS_CHILD|WS_VISIBLE|SS_LEFT ;
    }
    WLabel::~WLabel()
    {

    }
  }
}
