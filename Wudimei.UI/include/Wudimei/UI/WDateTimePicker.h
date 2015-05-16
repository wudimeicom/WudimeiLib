#ifndef WDATETIMEPICKER_H
#define WDATETIMEPICKER_H
#include "WBox.h"

namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WDateTimePicker:public WBox
    {
        public:
            WDateTimePicker();
            virtual ~WDateTimePicker();
            SYSTEMTIME getDateTime();
            void setRange(SYSTEMTIME min, SYSTEMTIME  max);
            BOOL setDateTime(SYSTEMTIME sysTime);
            void toTimePicker();
        protected:
            void prepareDateTimePicker();
        private:
            SYSTEMTIME sysTime;
    };
  }
}
#endif // WDATETIMEPICKER_H
