#include "../include/Wudimei/UI/WSlider.h"
#include <windows.h>
#include <commctrl.h>

namespace Wudimei
{
  namespace UI{

    WSlider::WSlider()
    {
        this->prepareSlider();
    }

    WSlider::WSlider(int orientation,int min,int max,int value){
        this->orientation =orientation;
        this->min = min;
        this->max = max;
        this->value = value;
        this->prepareSlider();
    }

     void WSlider::create(){
        WBox::create();

        this->setRange( this->min,this->max);
        this->setValue(this->value);
     }

     void WSlider::prepareSlider(){
        this->boxClassName = TRACKBAR_CLASS;
        this->dwStyle = WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_TOOLTIPS ;
        if( this->orientation == WSlider::VERTICAL )
        {
            this->dwStyle |= TBS_VERT;
        }
        this->lineSize =0;
        this->pageSize =0;
     }

    void WSlider::setRange(int min,int max){
        SendMessage(boxHandle, TBM_SETRANGE,(WPARAM) TRUE, (LPARAM) MAKELONG(min, max));
    }

    void WSlider::setValue(int value){
        SendMessage(boxHandle, TBM_SETPOS, (WPARAM) TRUE, (LPARAM) value);
    }

    int WSlider::getValue(){
        value = SendMessage(boxHandle, TBM_GETPOS, (WPARAM) 0, (LPARAM) 0);
        return value;
    }

    void WSlider::setLineSize(int size){
        SendMessage(boxHandle,TBM_SETLINESIZE,(WPARAM)0,(LPARAM)size);
    }

    void WSlider::setPageSize(int size){
        SendMessage(boxHandle,TBM_SETPAGESIZE,(WPARAM)0,(LPARAM)size);
    }

    WSlider::~WSlider()
    {
        //dtor
    }

  }
}
