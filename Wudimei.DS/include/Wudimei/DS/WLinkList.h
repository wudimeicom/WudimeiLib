/**

WLinkList wl;
    wl.add((LPVOID)123);
    wl.add((LPVOID)456);
    wl.add((LPVOID)789);
    cout<<(int)wl.getValue(0)<<endl;
    cout<<(int)wl.getValue(1)<<endl;
    cout<<"len:"<<wl.length()<<endl;
   // wl.setValue(1,(LPVOID)789);
    cout<<"item 1: "<<(int)wl.getValue(1)<<endl;
   // wl.remove(1);
    cout<<"len:"<<wl.length()<<endl;


    struct WLinkListNode  *p=wl.head;
    p = wl.getNode(1);
    while( p != NULL){
        cout<<"val:"<<(int)p->value<<endl;
        p =p->next;
    }
    */
#ifndef WLINKLIST_H_INCLUDED
#define WLINKLIST_H_INCLUDED

#include "./DS.h"

namespace Wudimei
{

  namespace DS{

    struct WLinkListNode{
        LPVOID value;
        struct WLinkListNode *next;
    };

    class DLL_EXPORT WLinkList{
    public:
        WLinkList();
        /*
        void set(LPCTSTR name , LPVOID value );
        void showAll();
        void remove(LPCTSTR name);
        LPVOID getValue(LPCTSTR name);*/
         void  add( LPVOID value );
        LPVOID  getValue(int index);
        struct WLinkListNode * getNode(int index);
        void  setValue(int index,LPVOID value );
        void  remove(int index);

        struct WLinkListNode *head;
        int length();
    };

  }
}

#endif // WLINKLIST_H_INCLUDED
