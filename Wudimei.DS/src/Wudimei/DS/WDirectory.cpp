#include <Wudimei/DS/WDirectory.h>
#include <tchar.h>

namespace Wudimei{
    namespace DS{

        WDirectory::WDirectory(WString path2):path(path2)
        {
            //ctor
        }

        WDirectory::~WDirectory()
        {
            //dtor
        }

        bool WDirectory::exists(){

            if (_access(path.c_str() , 06) == -1)
            {
                return false;
            }
            else{
                return true;
            }
        }

        WString WDirectory::appendCSlashes(WString path2){
            if ( path2.at( path2.length()-1)  != '\\')
            {
                path2 += _T("\\");
            }
            return path2;
        }

        bool WDirectory::chdir(WString path2 ){
            if (_chdir(path2.c_str()) != 0)
            {
                return false;
            }
            path = path2;
            return true;
        }

        void WDirectory::list( WLinkList *fileList  ){
            if( exists() == false ){
                return ;
            }
            path = appendCSlashes(path);
            if( chdir(path)== false){
                return ;
            }
            _finddata_t fileinfo;
            memset(&fileinfo, 0x0, sizeof(fileinfo));


            intptr_t iFind = _findfirst("*", &fileinfo);
            if (iFind == -1)
            {
                //cerr << "error: function _findfirst failed." << endl;
                //exit(-1);
                return ;
            }


          //  string filePath(dir + fileinfo.name);

            //cout << "name2: " <<fileinfo.name << endl;
            WString *tmp = new WString(fileinfo.name);
            int index=0;
            //(*fileList)[index]= tmp ;
            (*fileList).add((LPVOID)tmp);

            while (_findnext(iFind, &fileinfo) == 0)
            {
                //filePath = dir + fileinfo.name;
                //cout << "name: " << fileinfo.name << endl;
                tmp =new WString( fileinfo.name);
                //(*fileList).push_back( tmp );

                index++;
                //(*fileList)[index]= tmp ;
                (*fileList).add((LPVOID)tmp);
            }

            _findclose(iFind);

        }

    }
}
