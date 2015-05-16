#ifndef WBUTTON_H
#define WBUTTON_H
#include <Wudimei/UI/WBox.h>
#include <Wudimei/UI/WControl.h>
//using namespace WudimeiUI;
namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WButton :public WControl
    {
        public:
            WButton();
            WButton(LPCTSTR text);
            WButton(LPCTSTR text,WBox *parent);
            WButton(LPCTSTR text,WBox *parent,HMENU menuOrControlID );
            virtual ~WButton();
        protected:
        private:
            void prepareButton();

    };
  }
}
#endif // WBUTTON_H


/*
WButton *b = new WButton();
        b->setWidth(200);
        b->setHeight(50);
        b->setLeft(20);
        b->setTop(50);
        b->text = TEXT("open打开2");
        b->parentBoxHandle =hwndDlg;
        b->menuHandle = (HMENU)10001;//控件的ID
        b->instanceHandle = hInst;
        b->create();
*/
