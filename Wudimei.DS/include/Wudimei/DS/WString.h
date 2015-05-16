#ifndef WSTRING_H
#define WSTRING_H


#include "./DS.h"

/*
to use wide charset.please place the tow line to the very begining of main.cpp,or set it to the codeblocks
#define UNICODE
#define _UNICODE

 WString yqr("yqr—Ó");
    //WString yqr2("yqr—Ó");
    LPCTSTR yqr2=TEXT("yqr—Ó2");
    if( yqr.equals( yqr2 ) ){
        cout<<"the same"<<endl;
    }
*/

namespace Wudimei{
    namespace DS{


        class DLL_EXPORT WString{
        public:
            WString(void);
            WString(TCHAR *str);
            WString(LPCTSTR str2);

#ifdef UNICODE
            WString(char *str);
#endif
            virtual ~WString();
            int length();
            void assign(TCHAR *str2);
            void append(TCHAR *str2);
            void prepareString(void);

            void format(LPCTSTR format,...); //%s %ls
            WString subString(int start,int length);
            WString operator+(WString str2);
            WString operator+(LPCTSTR str2);
            WString operator+=(WString str2);
            WString operator+=(LPCTSTR str2);
            WString operator=(LPCTSTR str2);
            WString operator=(WString str2);
            bool equals(LPCTSTR str2);
            bool equals(WString str2);
            const char * c_str();

            TCHAR at(int index);
            TCHAR *str;
        protected:
            void adjustSpace(int tstrLen);
           static const int blockSize= 256;//memory block size(bytes)
           int blockNumber ;
        private:

        };

    }
}

#endif // WSTRING_H
