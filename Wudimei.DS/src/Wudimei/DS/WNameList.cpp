

#include "../include/Wudimei/DS/WNameList.h"
#include <Windows.h>
#include <TCHAR.h>
namespace Wudimei
{

  namespace DS{

    WNameList::WNameList(){
        head = NULL;
    }

    void WNameList::set(LPCTSTR name , LPVOID value ){
        bool found = false;
        if( name == NULL )
        {
            return ;
        }
        if( _tcslen( name ) <1 )
        {
            return;
        }
        //MessageBox(NULL, name, _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
        //MessageBox(NULL, _T("ds1"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
        struct WNameListNode *p=head,*prev=head;
        while(p  != NULL )
        {
            if( _tcsicmp( p->name,name ) == 0 )
            {
                p->value = value;
                found = true;
            }
            prev=p;
            p=p->next;
        }
        //MessageBox(NULL, _T("ds2"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
        if( found == false )
        {
            struct WNameListNode *newNode = (struct WNameListNode *)malloc(sizeof(struct WNameListNode));
            newNode->name = name;
            newNode->value = value;
            newNode->next = NULL;
            if( head == NULL )
            {
                head = newNode;
            }
            else{
               prev->next = newNode;
            }
        }
        //MessageBox(NULL, _T("ds3"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
    }

    LPVOID WNameList::getValue(LPCTSTR name){
        bool found = false;
        struct WNameListNode *p=head;
        while(p != NULL )
        {
            if( _tcsicmp( p->name,name ) == 0 )
            {
                return p->value;
            }
            p=p->next;
        }
        return NULL;
    }


    void WNameList::remove(LPCTSTR name){
        struct WNameListNode *p=head , *prev=head;
        while(p != NULL )
        {
            if( _tcsicmp( p->name,name ) == 0 )
            {
                if( p == head )
                {
                    head = p->next;
                    free(p);
                    return;
                }

                prev->next =p->next;
                free(p);
                return;
            }
            prev = p;
            p=p->next;
        }
    }

    void WNameList::showAll(){
        struct WNameListNode *p=head;
        TCHAR *str = new TCHAR[4096];
        _tcscpy_s( str,4096, TEXT("All Node Names: \r\n"));

        if(head != NULL)
        {
            while(p != NULL )
            {
                _tcscat( str,p->name);
                _tcscat( str, TEXT(" , "));

                p=p->next;
            }
        }
        MessageBox(NULL,str ,TEXT("WNameList::showAll()"),MB_OK);
        //free(str);
    }

    int WNameList::length(){
        int len=0;
        struct WNameListNode *p=head;
        while(p != NULL )
        {
            len++;
            p=p->next;
        }
        return len;
    }

  }
}
