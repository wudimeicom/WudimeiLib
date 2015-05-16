
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
#include <Wudimei/UI/WButton.h>
#include <Wudimei/UI/WGroupBox.h>
#include <Wudimei/UI/WRadio.h>

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
    static WGroupBox *gb;
    static WRadio *r1;
    static WRadio *r2;
    static WRadio *r3;
    static WButton *btnOk;

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

            lblTitle =new WLabel(TEXT("Where are you ?")  );
            lblTitle->setBounds(10,10,200,20);//left,right,width,top
            myForm->add(lblTitle);//add to myForm and show

            gb = new WGroupBox(TEXT("Please Choose Cities") , myForm ,  (HMENU)10002 );
            gb->setBounds( 10,50,180,100 );
            gb->setName(TEXT("cities"));//control name
            myForm->add(gb);

            r1 = new WRadio( TEXT("china shanghai") );
            r1->setBounds( 10,20,160,20 );
            r1->setName(TEXT("r1"));
            gb->add( r1 );

            r2 = new WRadio(TEXT("china beijing"));
            r2->setBounds( 10,40,160,20 );
            r2->setName(TEXT("r2"));
            gb->add( r2 );

            r3 = new WRadio( TEXT("china tibet")  ) ;
            r3->setBounds( 10,60,160,20 );
            r3->setName(TEXT("r3"));
            gb->add( r3 );

            btnOk = new WButton(TEXT("Ok"));
            btnOk->setBounds(20,180,60,25);
            btnOk->setControlID(10001); // the control id is for event handle,see below "case WM_COMMAND"
            myForm->add( btnOk );


        }

    return 0;
    break;

    case WM_COMMAND:
       switch(LOWORD(wParam))
       {
       case 10001:
           msg->format(_T("no select"));
           if( r1->checked()){
              msg->format(_T("shangHai"));
           }
           if( r2->checked()){
              msg->format(_T("beijing, text:%s"), r2->getText() );
           }
           if( r3->checked()){
              msg->format(_T("tibet, text:%s"),r3->getText() );
           }
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
    form->setText( TEXT("Please Login") );//title
    form->setName( TEXT("LoginForm") );//the form name "LoginForm" is for global accessing
    form->create();

    return myapp.run();
}
