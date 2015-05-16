#include <Wudimei/UI/WTrayIcon.h>
#include <Wudimei/UI/WApp.h>
#include <ShellAPI.h>
namespace Wudimei
{
  namespace UI{

    WTrayIcon::WTrayIcon()
    {
        this->prepareTrayIcon();
    }

    WTrayIcon::WTrayIcon(UINT _iconID){
        this->iconID = _iconID;
        this->prepareTrayIcon();
    }

    WTrayIcon::WTrayIcon(UINT _iconID,WBox *parent){
        this->iconID = _iconID;
        this->parent = parent;
        this->prepareTrayIcon();

    }

    WTrayIcon::~WTrayIcon()
    {
        //dtor
    }

    void WTrayIcon::prepareTrayIcon(){
        BOOL debug = FALSE;
        this->info_timeout = 5000;
        //this->alert( TEXT("prpTrayIcon 01", debug ));
        nid.cbSize = sizeof(NOTIFYICONDATA);     //初始化结构的大小
        nid.hWnd = this->parent->boxHandle;// hwndDlg;                         //指定接收托盘消息的句柄
        nid.uID = this->iconID;                     //指定托盘图标的ID
        nid.uFlags = NIF_ICON  | NIF_MESSAGE | NIF_TIP;  //设定结构里有效的位置
                 //NIF_ICON:     指定hIcon是有效的，（这里设定自定义系统托盘图标必须的
                 //NIF_MESSAGE:  指定uCallbackMessage是有效的，用于程序接收来自托盘图标的消息，需要自定义一个消息
                   //NIF_TIP:      指定szTip是有效的，功能是当鼠标移动到图标上时，显示提示信息
        nid.uCallbackMessage = WM_WudimeiTray;     //自定义的消息，我在一开始定义了一个自定义消息 //#define WM_IAWENTRAY  WM_USER+5
        //this->alert( TEXT("prpTrayIcon 02", debug ));
        nid.hIcon = LoadIcon( WApp::hInstance, MAKEINTRESOURCE(this->iconID));
        //this->alert( TEXT("prpTrayIcon 03", debug ));
    }

    void WTrayIcon::showInfo( LPCTSTR title, LPCTSTR content){
        nid.uFlags  = NIF_ICON  | NIF_MESSAGE | NIF_TIP | NIF_INFO;
        nid.uTimeout = this->info_timeout;
        nid.dwInfoFlags = NIIF_NONE;


        lstrcpy(nid.szInfo,   content);
        lstrcpy(nid.szInfoTitle,   title);

        Shell_NotifyIcon(NIM_MODIFY, &nid);

    }

    void WTrayIcon::addIcon(LPCTSTR tip){
        lstrcpy(nid.szTip,   tip);
        Shell_NotifyIcon(NIM_ADD, &nid);
    }

    void WTrayIcon::deleteIcon(){
        Shell_NotifyIcon(NIM_DELETE, &nid);
    }
  }
}
