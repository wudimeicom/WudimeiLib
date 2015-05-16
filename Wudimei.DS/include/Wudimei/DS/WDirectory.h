/**
usage:

 WVector<WString*> files(100);
    WDirectory wdir("D:\\");
    //WString *yqr=new WString("sfsa—Ó«Ï»Ÿ");
   //files[0] =yqr;

    wdir.list(&files);
    for(int i=0;i<files.size();i++){
       // cout<<"d"<<i<<"  ";
        if( nullptr != files[i] )
        {
            cout<<  files[i]->str  <<endl;
        }

    }

    */

#ifndef WDIRECTORY_H
#define WDIRECTORY_H
#include "./DS.h"

#include <io.h>
#include <direct.h>
#include <Wudimei/DS/WString.h>
#include <Wudimei/DS/WLinkList.h>
#include <iostream>
using namespace std;
namespace Wudimei{
    namespace DS{



class DLL_EXPORT WDirectory
{
    public:
        WDirectory(WString path2);
        virtual ~WDirectory();
        bool exists();
        WString  appendCSlashes(WString path2);
        bool chdir(WString path2 );
        void list( WLinkList *fileList);

        WString path;
    protected:
    private:
};



    }
}

#endif // WDIRECTORY_H
