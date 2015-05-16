#ifndef BOX_H
#define BOX_H
#include <windows.h>
#include "./UI.h"
#include <tchar.h>
#include <Wudimei/DS/WNameList.h>
using namespace Wudimei::DS;
namespace Wudimei
{
  namespace UI{


     class DLL_EXPORT WBox
    {
        public:
            WBox(void);
            WBox(LPCTSTR text);
            WBox(LPCTSTR text,WBox *parent );
            WBox(LPCTSTR text,WBox *parent,HMENU menuOrControlID );

            virtual ~WBox();
            void prepareBox();
            void setWidth(int width);
            int getWidth();
            void setHeight(int height);
            int getHeight();
            void setLeft(int left);
            int getLeft();
            void setTop( int top );
            int getTop();
            void setBounds(int left, int top, int width, int height);
            void setLocation(int left,int top);
            void setSize(int width,int height);
            virtual void create();
            void setText( LPCTSTR text );
            void setText( TCHAR* text );
            void add(WBox *box );
            int getBoxNumber(void);
            void setName(LPCTSTR name );
            void show(void);
            void hide(void);
            BOOL isVisible(void);
            void setEnable(BOOL enable);
            BOOL isEnabled(void);
            void alert(LPCTSTR msg);
            void alert(LPCTSTR msg,BOOL show);
            LPCTSTR getName();
            LPCTSTR getText();
            DWORD dwExStyle;
            HWND boxHandle;
            //HWND parentBoxHandle;
            WBox *parent;
            LPCTSTR boxClassName;
            HMENU menuHandle;

            DWORD dwStyle;
            HINSTANCE instanceHandle;
            LPVOID lpParam;

            static int boxNumberSequence;
            static WNameList *boxes;
            WNameList *children;
        protected:
            int width;
            int height;
            int left;
            int top;
            LPCTSTR text;
            LPCTSTR name;//for seeking
            void _setBounds(void);
        private:
    };
  }
}
#endif // BOX_H


/*
WBox *b = new WBox();
        b->setWidth(200);
        b->setHeight(50);
        b->setLeft(20);
        b->setTop(50);
        b->dwExStyle =0;
        b->boxClassName = TEXT("BUTTON");
        b->text = TEXT("open打开");
        b->dwStyle = WS_CHILD|WS_VISIBLE|BS_FLAT ;
        b->parentBoxHandle =hwndDlg;
        b->menuHandle = (HMENU)10001;//控件的ID
        b->instanceHandle = hInst;
        b->lpParam = NULL;
        b->create();
*/
