#ifndef WCONTROL_H
#define WCONTROL_H
#include <Wudimei/UI/WBox.h>
namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WControl:public WBox
    {
        public:
            WControl();
            WControl(LPCTSTR text);
            WControl(LPCTSTR text,WBox *parent);
            WControl(LPCTSTR text,WBox *parent,HMENU menuOrControlID );
            virtual ~WControl();
            void setControlID(int controlID );
        protected:
        private:
    };

  }
}
#endif // WCONTROL_H
