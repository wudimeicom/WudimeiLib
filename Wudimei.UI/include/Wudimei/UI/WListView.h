#ifndef WLISTVIEW_H
#define WLISTVIEW_H

#include <Wudimei/UI/WBox.h>

#include "./UI.h"
#include "WImageList.h"
namespace Wudimei
{
  namespace UI{

    class DLL_EXPORT WListView:public WBox
    {
        public:
            WListView();
            virtual ~WListView();
            void prepareListView(void);
            void addColumn(LPCTSTR text);
            void addColumn(LPCTSTR text,int width);
           BOOL removeColumn( int columnIndex);
            void addItem(void);
            void addImageItem(int nImageIndex);
            BOOL removeItem(int itemIndex);
           BOOL removeAllItems(void);
            void setSubItemText( int itemIndex,int subItemIndex,LPCTSTR text);
            LPCTSTR  getSubItemText(int itemIndex,int subItemIndex );
            UINT getSelectedCount(void);
            void setImageList(WImageList *standardImgList ,WImageList * smallImgList);
            void setListViewStyle(const int style);
            static const int SHOW_DETAILS=1;
            static const int SHOW_ICON=2;
            static const int SHOW_LIST=3;
            static const int SHOW_SMALLICON=4;
            static const int SHOW_TILE=5;
            int defaultColumnWidth ;
        protected:
            int columnIndex;
            int itemIndex;
            WImageList *smallImgList;
            WImageList *standardImgList;
        private:
            LPCTSTR subItemText;
    };

  }
}
#endif // WLISTVIEW_H
