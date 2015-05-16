#include "../include/Wudimei/UI/WDateTimePicker.h"
#include <commctrl.h>
namespace Wudimei
{
  namespace UI{

    WDateTimePicker::WDateTimePicker()
    {
        this->prepareDateTimePicker();
    }

    void WDateTimePicker::prepareDateTimePicker(){

        this->boxClassName = DATETIMEPICK_CLASS;
        this->setText( TEXT("DateTime"));
        this->dwStyle = WS_BORDER|WS_CHILD|WS_VISIBLE|DTS_SHOWNONE|DTS_UPDOWN;
    }

    void WDateTimePicker::toTimePicker(){
        this->dwStyle = WS_BORDER|WS_CHILD|WS_VISIBLE| DTS_TIMEFORMAT|DTS_UPDOWN;
    }

    SYSTEMTIME WDateTimePicker::getDateTime(){
        DateTime_GetSystemtime(
                      this->boxHandle,
                      &sysTime
                    );
        return sysTime;
    }

    void WDateTimePicker::setRange(SYSTEMTIME minDT, SYSTEMTIME  maxDT){
        SYSTEMTIME lpSysTimeArray[2];
        lpSysTimeArray[0] = minDT;
        lpSysTimeArray[1] = maxDT;
        DWORD flags =0;
        if( minDT.wYear != 0 )
        {
            flags |= GDTR_MIN;
        }
        if( maxDT.wYear != 0 )
        {
            flags |= GDTR_MAX;
        }
        DateTime_SetRange(
          this->boxHandle,
          flags,
          lpSysTimeArray
        );
    }

   BOOL  WDateTimePicker::setDateTime(SYSTEMTIME sysTime){
        DWORD flag;
        if( sysTime.wYear == 0 )
        {
            flag = GDT_NONE;
        }
        else{
            flag = GDT_VALID;
        }
       return DateTime_SetSystemtime(
          this->boxHandle,
           flag,
          &sysTime
        );
    }

    WDateTimePicker::~WDateTimePicker()
    {
        //dtor
    }
  }
}
