
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
#include <Wudimei/UI/WSelect.h>
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
    static WSelect *sel;
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
            myForm  =(MyForm*)WBox::boxes->getValue( TEXT("MyForm1") );
            myForm->boxHandle =hwnd;

            lblTitle =new WLabel(TEXT("Select your gender")  );
            lblTitle->setBounds(10,10,200,20);//left,right,width,top
            myForm->add(lblTitle);//add to myForm and show

            sel = new WSelect(_T("hi"));
            sel->setBounds(10,50,100,25);
            myForm->add(sel);

            sel->addOption(_T("male & female"));
            sel->removeAllOptions();
            sel->addOption(_T("male"));
            sel->addOption(_T("female"));
            sel->addOption(_T("male 2 femal"));
            sel->insertOption(1,_T("orange"));
            sel->insertOption(3,_T("banana"));
            sel->removeOption(4);


            btnOk = new WButton(TEXT("Ok"));
            btnOk->setBounds(20,100,60,25);
            btnOk->setControlID(10001); // the control id is for event handle,see below "case WM_COMMAND"
            myForm->add( btnOk );

        }

    return 0;
    break;

    case WM_COMMAND:
       switch(LOWORD(wParam))
       {
       case 10001:
            msg->format(_T("you choose:\n index:%d \n text: %s"),sel->getSelectedIndex(), sel->getSelectedText( ) );
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
