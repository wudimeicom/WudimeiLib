#include "../include/Wudimei/UI/WButton.h"
#include "../include/Wudimei/UI/WApp.h"
namespace Wudimei
{
  namespace UI{


    WButton::WButton()
    {
        this->prepareButton();
    }

    WButton::WButton(LPCTSTR text):WControl(text){
        this->prepareButton();
    }

    WButton::WButton(LPCTSTR text,WBox *parent):WControl(text,parent ){
        this->prepareButton();
    }

    WButton::WButton(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WControl(text,parent ,menuOrControlID){
        this->prepareButton();
    }

    void WButton::prepareButton(){
        this->boxClassName = TEXT("BUTTON");
        this->dwStyle = WS_CHILD|WS_VISIBLE|BS_FLAT ;
    }

    WButton::~WButton()
    {
        //dtor
    }
  }
}
