
#include "../include/Wudimei/DS/WLinkList.h"
#include <Windows.h>
#include <TCHAR.h>
namespace Wudimei
{

  namespace DS{

    WLinkList::WLinkList(){
        head = NULL;
    }

    void WLinkList::add( LPVOID value ){

        struct WLinkListNode *p=head,*prev=head;
        while(p  != NULL )
        {
            prev=p;
            p=p->next;
        }

        struct WLinkListNode *newNode = (struct WLinkListNode *)malloc(sizeof(struct WLinkListNode));

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

    LPVOID WLinkList::getValue(int index){

        struct WLinkListNode *p=head;
        int i=0;
        while(p != NULL )
        {
            if( i==index )
            {
                return p->value;
            }
            p=p->next;
            i++;
        }
        return NULL;
    }


    struct WLinkListNode * WLinkList::getNode(int index){
        struct WLinkListNode *p=head;
        int i=0;
        while(p != NULL )
        {
            if( i==index )
            {
                return p;
            }
            p=p->next;
            i++;
        }
        return nullptr;
    }

    void WLinkList::setValue(int index,LPVOID value ){

        struct WLinkListNode *p=head;
        int i=0;
        while(p != NULL )
        {
            if( i==index )
            {
                p->value=value;
            }
            p=p->next;
            i++;
        }

    }

    void WLinkList::remove(int index){
        struct WLinkListNode *p=head , *prev=head;
        int i=0;
        while(p != NULL )
        {
            if( i==index )
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
            i++;
        }
    }

    int WLinkList::length(){
        int len=0;
        struct WLinkListNode *p=head;
        while(p != NULL )
        {
            len++;
            p=p->next;
        }
        return len;
    }


  }
}
