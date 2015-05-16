#include <Wudimei/UI/WControl.h>

namespace Wudimei
{
  namespace UI{

WControl::WControl()
{
    //ctor
}

WControl::WControl(LPCTSTR text):WBox(text){

}

WControl::WControl(LPCTSTR text,WBox *parent):WBox(text,parent){

}

WControl::WControl(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WBox(text,parent,menuOrControlID){

}


WControl::~WControl()
{
    //dtor
}
void WControl::setControlID(int controlID ){
    this->menuHandle = (HMENU)controlID;
}

  }
}
