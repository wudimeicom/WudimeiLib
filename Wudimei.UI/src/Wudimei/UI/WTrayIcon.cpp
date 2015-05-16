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
        nid.cbSize = sizeof(NOTIFYICONDATA);     //��ʼ���ṹ�Ĵ�С
        nid.hWnd = this->parent->boxHandle;// hwndDlg;                         //ָ������������Ϣ�ľ��
        nid.uID = this->iconID;                     //ָ������ͼ���ID
        nid.uFlags = NIF_ICON  | NIF_MESSAGE | NIF_TIP;  //�趨�ṹ����Ч��λ��
                 //NIF_ICON:     ָ��hIcon����Ч�ģ��������趨�Զ���ϵͳ����ͼ������
                 //NIF_MESSAGE:  ָ��uCallbackMessage����Ч�ģ����ڳ��������������ͼ�����Ϣ����Ҫ�Զ���һ����Ϣ
                   //NIF_TIP:      ָ��szTip����Ч�ģ������ǵ�����ƶ���ͼ����ʱ����ʾ��ʾ��Ϣ
        nid.uCallbackMessage = WM_WudimeiTray;     //�Զ������Ϣ������һ��ʼ������һ���Զ�����Ϣ //#define WM_IAWENTRAY  WM_USER+5
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
