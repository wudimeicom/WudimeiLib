#include <Wudimei/UI/WBmp.h>

namespace Wudimei
{
  namespace UI{
    WBmp::WBmp()
    {
        this->prepareBmp();
    }

    WBmp::WBmp(LPCTSTR path){
        this->prepareBmp();
        //this->path = path;
        //_tcscpy(this->path,path);
        _tcscpy_s( this->path,256,path);
    }

    void WBmp::prepareBmp(void){
        this->path = new TCHAR[256];
        ZeroMemory(  this->path,sizeof(this->path));
        this->boxClassName = TEXT("Static");
        this->dwStyle = WS_CHILD | WS_VISIBLE | SS_BITMAP ;
    }

    void WBmp::loadImageFile(LPCTSTR path){
        HBITMAP hBmp = (HBITMAP)LoadImage(NULL,path,IMAGE_BITMAP,0,0,LR_LOADFROMFILE| LR_DEFAULTSIZE);
        SendMessage( boxHandle, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM) hBmp);
    }

    void WBmp::create(){
        WBox::create();
       // MessageBox(NULL,this->path,_T("a"),MB_OK);
        this->loadImageFile(this->path);
    }
    WBmp::~WBmp()
    {
        //dtor
    }
  }
}
