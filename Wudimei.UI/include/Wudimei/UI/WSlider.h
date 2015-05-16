#ifndef WSLIDER_H
#define WSLIDER_H
#include "WBox.h"

namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WSlider:public WBox
    {
        public:
            WSlider();
            WSlider(int orientation,int min,int max,int value);
            virtual ~WSlider();
            virtual void create();
            void prepareSlider();
            void setRange(int min,int max);
            void setValue(int value);
            int getValue();
            void setLineSize(int size);
            void setPageSize(int size);

            int orientation;
            int min;
            int max;
            int value;
            int lineSize;
            int pageSize;
            static const int HORIZONTAL=0;
            static const int VERTICAL=1;
        protected:
        private:
    };

  }
}

#endif // WSLIDER_H
