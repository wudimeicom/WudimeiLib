
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
#include <Wudimei/UI/WTextfield.h>
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
    static WLabel *lblUsername;
    static WLabel *lblPassword;
    static WTextfield *txtUsername;
    static WTextfield *txtPassword;
    static WButton *btnLogin;
    static WButton *btnReset;
    static WString *msg = new WString();

    switch (message) {
     case WM_PAINT:
         hDc = BeginPaint(hwnd,&Ps);
        EndPaint(hwnd,&Ps);
        return 0 ;
     case WM_CREATE:
        {
            //get the form instance by form name
            myForm  =(MyForm*)WBox::boxes->getValue( TEXT("LoginForm") );
            myForm->boxHandle =hwnd;

            lblTitle =new WLabel(TEXT("Please Login 请登录")  );
            lblTitle->setBounds(10,10,200,20);//left,right,width,top
            myForm->add(lblTitle);//add to myForm and show

            lblUsername = new WLabel(TEXT("User Name:")  );
            lblUsername->setBounds(10,40,100,25);
            myForm->add(lblUsername);

            lblPassword = new WLabel(TEXT("  Password:")  );
            lblPassword->setBounds(10,75,100,25);
            myForm->add(lblPassword);

            txtUsername = new WTextfield(TEXT("wudimei.com"));
            txtUsername->setBounds(120,40,100,25);
            myForm->add(txtUsername);

            txtPassword = new WTextfield(TEXT("123456"));
            txtPassword->setBounds(120,75,100,25);
            myForm->add(txtPassword);

            btnLogin = new WButton(TEXT("Login"));
            btnLogin->setBounds(20,110,60,25);
            btnLogin->setControlID(10001); // the control id is for event handle,see below "case WM_COMMAND"
            myForm->add( btnLogin );

            btnReset = new WButton( TEXT("Reset") );
            btnReset->setBounds(120,110,60,25);
            btnReset->setControlID(10002);
            myForm->add(btnReset);

        }

    return 0;
    break;

    case WM_COMMAND:
       switch(LOWORD(wParam))
       {
       case 10001:
          msg->format(_T("you enter:\n username:%s\n password:%s\n"),txtUsername->getText(),txtPassword->getText() );
          MessageBox(hwnd,msg->str,TEXT("hi"),MB_OK);
        break;
       case 10002:
           txtUsername->setText(_T(""));
           txtPassword->setText(_T(""));
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
    form->setText( TEXT("Please Login") );//title
    form->setName( TEXT("LoginForm") );//the form name "LoginForm" is for global accessing
    form->create();

    return myapp.run();
}
