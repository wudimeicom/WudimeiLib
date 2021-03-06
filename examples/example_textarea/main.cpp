
#ifndef WINVER  // 指定要求的最低平台是 Windows Vista。
#define WINVER 0x0501  // 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#include <windows.h>
#include <stdio.h>
#include "resource.h"
#include <TCHAR.h>
#include <Wudimei/DS/WString.h>
#include <Wudimei/UI/WApp.h>
#include <Wudimei/UI/WForm.h>
#include <Wudimei/UI/WLabel.h>
#include <Wudimei/UI/WTextarea.h>
#include <Wudimei/UI/WButton.h>

using namespace Wudimei::DS;
using namespace Wudimei::UI;

//--------------------class MyForm start--------------------
class MyForm:public WForm
{
    public:
        MyForm();
        virtual ~MyForm();
        static LRESULT CALLBACK handle_event(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    protected:
    private:
};


MyForm::MyForm()
{
    windowClass.lpfnWndProc =   handle_event;
}

MyForm::~MyForm()
{
}

LRESULT CALLBACK MyForm::handle_event(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){

    HDC hDc ;
    PAINTSTRUCT Ps ;

    //define the controls
    static MyForm *myForm;
    static WLabel *lblTitle;
    static WButton *btnOk;
    static WTextarea *ta;
    static WString *msg = new WString();
    static WString *tmp = new WString();
    switch (message) {
     case WM_PAINT:
         hDc = BeginPaint(hwnd,&Ps);
        EndPaint(hwnd,&Ps);
        return 0 ;
     case WM_CREATE:
        {
            //get the form instance by form name
            myForm  =(MyForm*)WBox::boxes->getValue( TEXT("MyForm1") );
            myForm->boxHandle =hwnd;

            lblTitle =new WLabel(TEXT("enter something")  );
            lblTitle->setBounds(10,10,200,20);//left,right,width,top
            myForm->add(lblTitle);//add to myForm and show

            ta =new WTextarea( TEXT("name: Yang Qing-rong\r\nWebsite: http://wudimei.com")  );
            ta->setBounds( 10,40,250,180 );
            ta->menuHandle = (HMENU)10003;//控件的ID
            //ta->setName(TEXT("content"));
            myForm->add(ta);

            ta->setSelectedRange(5,10);//Yang
            ta->replace(_T("杨"));

            btnOk = new WButton(TEXT("Ok"));
            btnOk->setBounds(20,250,60,25);
            btnOk->setControlID(10001); // the control id is for event handle,see below "case WM_COMMAND"
            myForm->add( btnOk );

        }

    return 0;
    break;

    case WM_COMMAND:
       switch(LOWORD(wParam))
       {
       case 10001:
            msg->format(_T("line count:%d\n%ls "),
                        ta->getLineCount(),
                        ta->getText()
                        );
            MessageBox(hwnd,msg->str,TEXT("hi"),MB_OK);
        break;

       }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
//--------------------class MyForm end--------------------

HINSTANCE hInst=NULL;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR szCmdLine, int iCmdShow)
{
    WApp::storeMainArgs(hInstance,hPrevInstance,szCmdLine,iCmdShow );
    WApp myapp;


    MyForm *form = new MyForm();
    form->setBounds( 100,100,600,480);//left,top,width,height
    form->setText( TEXT("http://wudimei.com/") );//title
    form->setName( TEXT("MyForm1") );//the form name "LoginForm" is for global accessing
    form->create();

    return myapp.run();
}
