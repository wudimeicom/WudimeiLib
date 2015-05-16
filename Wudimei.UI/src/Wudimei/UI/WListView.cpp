#include "../include/Wudimei/UI/WListView.h"
#include <commctrl.h>

namespace Wudimei
{
  namespace UI{

        WListView::WListView()
        {
            this->prepareListView();
        }

        WListView::~WListView()
        {
            //dtor
        }

        void WListView::addColumn(LPCTSTR text,int width){
            LVCOLUMN col;
            col.mask = LVCF_TEXT|LVCF_WIDTH|LVCF_FMT|LVCF_SUBITEM;
            col.fmt = LVCFMT_CENTER;

            col.cx= width;
            col.pszText = (LPTSTR)text;
            col.cchTextMax= width;
            col.iSubItem=this->columnIndex;
            ListView_InsertColumn( boxHandle, this->columnIndex,(const LVITEM FAR*)&col);
            this->columnIndex++;
            //col.cx=20;
        }

        void WListView::addColumn(LPCTSTR text){
            this->addColumn(text,this->defaultColumnWidth);
        }

        BOOL WListView::removeColumn( int columnIndex){
            return ListView_DeleteColumn(boxHandle,columnIndex);
        }

        void WListView::addItem(void){
            LVITEM lvi = {0};
            lvi.iItem = this->itemIndex++ ;
            lvi.iSubItem=0;
            lvi.pszText = _T("");
            lvi.mask = LVIF_TEXT;
            ListView_InsertItem( boxHandle , (const LVITEM FAR*)&lvi );
        }

        void WListView::addImageItem(int nImageIndex){
            LVITEM lvi = {0};
            lvi.iItem = this->itemIndex++ ;
            lvi.iSubItem=0;
            lvi.pszText = _T("");

            lvi.mask = LVIF_TEXT|LVIF_IMAGE;
            lvi.iImage = nImageIndex;
            ListView_InsertItem( boxHandle , (const LVITEM FAR*)&lvi );
        }

        BOOL WListView::removeItem(int itemIndex){
            return ListView_DeleteItem(boxHandle,itemIndex);
        }

        BOOL WListView::removeAllItems(void){
            return ListView_DeleteAllItems(boxHandle);
        }

        void WListView::setSubItemText(int itemIndex,int subItemIndex, LPCTSTR text){
            ListView_SetItemText( boxHandle ,itemIndex,subItemIndex,(LPTSTR)text);
        }

        LPCTSTR WListView::getSubItemText(int itemIndex,int subItemIndex ){
            ListView_GetItemText(  boxHandle ,itemIndex,subItemIndex,(LPTSTR)subItemText,sizeof( subItemText));
            return subItemText;
        }

        UINT WListView::getSelectedCount(void){
            return ListView_GetSelectedCount(boxHandle);
        }

        void WListView::prepareListView(void){
            InitCommonControls();
            this->boxClassName = WC_LISTVIEW;
            this->dwStyle = WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_SHOWSELALWAYS |  LVS_REPORT |LVS_EDITLABELS|LVS_AUTOARRANGE|LVS_EX_CHECKBOXES;

            this->columnIndex =0;
            this->itemIndex=0;
            this->defaultColumnWidth = 100;

            subItemText = new TCHAR[1042];
            ZeroMemory((LPVOID)subItemText,sizeof(subItemText));
        }

        void WListView::setImageList(WImageList *standardImgList ,WImageList * smallImgList ){
            this->standardImgList = standardImgList;
            this->smallImgList = smallImgList;
            ListView_SetImageList(boxHandle, this->standardImgList->getImageList(), LVSIL_NORMAL);
            ListView_SetImageList(boxHandle, this->smallImgList->getImageList(), LVSIL_SMALL);
        }

        void WListView::setListViewStyle(const int style){
            DWORD dwView=LVS_ICON;// LVS_LIST;// LVS_ICON;
            switch( style )
            {
            case  SHOW_DETAILS:
                dwView = LVS_REPORT;
                break;
            case  SHOW_ICON:
                dwView = LVS_ICON;
                break;
            case  SHOW_LIST:
                dwView = LVS_LIST;
                break;
            case  SHOW_SMALLICON:
                dwView=LVS_SMALLICON;
                break;
            case  SHOW_TILE:
                dwView= LVS_ICON;
                break;
            }


            DWORD dwStyle = GetWindowLong(boxHandle, GWL_STYLE);
            if ((dwStyle & LVS_TYPEMASK) != dwView)
            {
                SetWindowLong(boxHandle,GWL_STYLE,(dwStyle & ~LVS_TYPEMASK) | dwView);
            }
        }
  }
}
