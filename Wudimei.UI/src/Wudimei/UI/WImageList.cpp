#include "../include/Wudimei/UI/WImageList.h"
#include "../include/Wudimei/UI/WApp.h"

namespace Wudimei
{
  namespace UI{
    WImageList::WImageList(int width,int height)
    {
        this->prepareImageList(width,height);
    }

    WImageList::WImageList(LPCTSTR szIconSize){
        if( _tcscmp(szIconSize,_T("standard")) == 0 )
        {
            this->prepareImageList(GetSystemMetrics(SM_CXICON), GetSystemMetrics( SM_CYICON));
        }
        else{
            this->prepareImageList(GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON));
        }
    }

    WImageList::WImageList(){
        this->prepareImageList(GetSystemMetrics(SM_CXICON), GetSystemMetrics( SM_CYICON));
    }

    void WImageList::prepareImageList(int width,int height){
        hImageList = ImageList_Create(width, height, ILC_MASK, 1, 1);

    }

    void WImageList::loadIcon(int iconId ){
        this->loadIcon(iconId,WApp::hInstance);
    }

    void WImageList::loadIcon(int iconId ,HINSTANCE hInst ){
        HICON hIconItem;
        hIconItem = LoadIcon (hInst, MAKEINTRESOURCE( iconId));
        //ASSERT(hImageList != NULL );
        ImageList_AddIcon(hImageList, hIconItem);
        DestroyIcon(hIconItem);
    }

    HIMAGELIST WImageList::getImageList(void){
        return hImageList;
    }

    WImageList::~WImageList()
    {
        //dtor
    }
  }
}
