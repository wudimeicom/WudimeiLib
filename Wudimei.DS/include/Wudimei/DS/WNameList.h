#ifndef WNAMELIST_H
#define WNAMELIST_H


#include "./DS.h"

namespace Wudimei
{

  namespace DS{

    struct WNameListNode{
        LPCTSTR name;
        LPVOID value;
        struct WNameListNode *next;
    };

    class DLL_EXPORT WNameList{
    public:
        WNameList();
        void set(LPCTSTR name , LPVOID value );
        void showAll();
        void remove(LPCTSTR name);
        LPVOID getValue(LPCTSTR name);
        struct WNameListNode *head;
        int length();
    };

  }
}

#endif // WNAMELIST_H




/*
WNameList *namelist = new WNameList();
    namelist->set( TEXT("zsf"),TEXT("������"));
    namelist->set(TEXT("yqr"),TEXT("������"));
    namelist->set(TEXT("ls"),TEXT("����"));
    namelist->set( TEXT("zsf2"),TEXT("������2"));
    namelist->set( TEXT("zsf2"),TEXT("������222222"));
    namelist->remove(TEXT("zsf2"));
    namelist->showAll();
    //MessageBox(NULL, (LPCTSTR)namelist->getValue("zsf23"),TEXT("hi"),MB_OK);

    */
/*
struct WNameListNode *p=namelist->head;
    while( p!=NULL )
    {
        MessageBox(NULL, p->name,TEXT("hi"),MB_OK);
        p=p->next;
    }
    */
