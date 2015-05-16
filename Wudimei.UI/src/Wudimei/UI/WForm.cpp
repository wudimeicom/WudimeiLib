#include "../include/Wudimei/UI/WForm.h"
#include "../include/Wudimei/UI/WApp.h"
namespace Wudimei
{
  namespace UI{

    WForm::WForm()
    {
        //ctor
        this->dwStyle = WS_OVERLAPPEDWINDOW;
        this->dwExStyle = 0;//WS_EX_CLIENTEDGE;
        this->boxClassName = TEXT("WudimeiUI");
        this->menuHandle = NULL;
        this->lpParam = NULL;

        windowClass.style = CS_HREDRAW | CS_VREDRAW;
        windowClass.lpfnWndProc =  (WNDPROC)handle_event;
        windowClass.cbClsExtra = 0;
        windowClass.cbWndExtra = 0;
        windowClass.hInstance = instanceHandle;
        windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        windowClass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
        windowClass.lpszMenuName = NULL;
        windowClass.lpszClassName = TEXT("WudimeiUI");

    }

    WForm::~WForm()
    {
        //dtor
    }
    void WForm::create(){

        HWND p=NULL;
        if( parent != NULL )
        {
            p=parent->boxHandle;
        }

        /* window class reigstration */
        if( !RegisterClass(&windowClass) )
        {
            MessageBox(NULL, _T("WForm:unable to register class!"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
            return  ;
        }


    /*
        boxHandle = CreateWindowEx(
        dwExStyle,
        TEXT("WudimeiUI"),
        text,
        dwStyle,
        left,
        top,
        width,
        height,
        NULL,//parentHwnd
        menuHandle,
        instanceHandle,
        lpParam
        );*/
        boxHandle = CreateWindow(TEXT("WudimeiUI"), text, WS_OVERLAPPEDWINDOW,
			left,
        top,
        width,
        height,
			NULL, menuHandle, instanceHandle, lpParam);

        if(boxHandle == NULL)
        {
            MessageBox(NULL, _T("WForm Creation Failed!"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
            return  ;
        }

        ShowWindow(boxHandle, WApp::iCmdShow);
        UpdateWindow(boxHandle);
    }

    LRESULT CALLBACK WForm::handle_event(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){

        HDC hdc ;
        PAINTSTRUCT ps ;

        switch (message) {

         case WM_PAINT:        //处理WM_PAINT消息
            hdc = BeginPaint(hwnd,&ps); //获取设备环境句柄,重绘时需要这两句，要不然全空白了
            EndPaint(hwnd,&ps); //释放资源
            return 0 ;

        case WM_CREATE:

            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        }
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
  }
}
