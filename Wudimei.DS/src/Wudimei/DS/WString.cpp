#include "../include/Wudimei/DS/WString.h"
#include "../include/Wudimei/DS/WMath.h"
#include <tchar.h>
#include <stdio.h>

namespace Wudimei{
    namespace DS{



        WString::~WString()
        {
            //dtor
        }

        WString::WString(void){
            this->prepareString();
        }

        WString::WString(TCHAR *str){
            this->prepareString();
            assign(str);
        }

        WString::WString(LPCTSTR str2){
            this->prepareString();
            assign((TCHAR*)str2);
        }
 #ifdef UNICODE
        WString::WString(char *str ){
            this->prepareString();

            TCHAR *newStr=new TCHAR[strlen(str)+1];
            MultiByteToWideChar(CP_ACP, 0, str, -1, newStr, strlen(str)+1);
        }
#endif // UNICODE
        void WString::prepareString(void){
            str =new TCHAR[1];
            str[0] = '\0';
            blockNumber =0;
        }

        void WString::format(LPCTSTR format,...){
            const size_t numChs = _tcslen((TCHAR*)format)*4;
            TCHAR *tmp =new TCHAR[numChs];
            const int lastChar = numChs-1;
            va_list args;
            va_start(args,format);
            _vsntprintf(tmp,numChs-1,format,args);
            va_end(args);
            tmp[lastChar]=TEXT('\0');
            assign(tmp);
            delete tmp;
        }

        WString WString::subString(int start,int length){
            WString newStr;
            TCHAR *text = new TCHAR[length+1];
            int j=0;
            for(int i=0;i< this->length(); i++ )
            {
                if(i>=start && i<start+length)
                {
                    text[j++]= this->str[i];
                }
            }
            text[length]='\0';
            newStr.assign(text);
            delete text;
            return newStr;
        }

        WString WString::operator+(WString str2){
            WString str3;
            str3.assign(this->str);
            str3.append(str2.str);
            return str3;
        }

        WString WString::operator+(LPCTSTR str2){
            WString str3;
            str3.assign(this->str);
            str3.append((TCHAR*)str2 );
            return str3;
        }

        WString WString::operator+=(WString str2){
           this->append(str2.str);
           return *this;
        }

        WString WString::operator+=(LPCTSTR str2){
            this->append((TCHAR*)str2);
            return *this;
        }
        WString WString::operator=(LPCTSTR str2){
            WString str3;
            str3.assign((TCHAR*)str2);
            return str3;
        }

        WString WString::operator=(WString str2){
            WString str3;
            str3.assign(str2.str);
            return str3;
        }

        void WString::adjustSpace(int tstrLen){

            int newBlockNum = WMath::ceil( 1.0*(tstrLen+1)/WString::blockSize);
            if( newBlockNum > this->blockNumber )
            {
                this->blockNumber = newBlockNum;
                delete[] str;
                str = new TCHAR[newBlockNum*WString::blockSize];
            }
        }

        void WString::assign(  TCHAR *str2){
            int len = _tcslen(str2);
            this->adjustSpace(len);
            _tcscpy(str,str2);
        }

        void WString::append(TCHAR *str2 ){

            TCHAR *oldStr=new TCHAR[this->length()+1];
            memset(oldStr,0,sizeof(oldStr));
            _tcscpy(oldStr ,str);

            int len = this->length() + _tcslen(str2) ;
            this->adjustSpace(len);
            _tcscpy(str ,oldStr);
            _tcscat(str,str2);

            delete  oldStr;

        }

        int WString::length(){
           if( str == nullptr)
           {
               return 0;
           }
           else{
                return _tcslen(str);
           }
        }

        TCHAR WString::at(int index){
           WString sub= subString(index,1);
            return sub.str[0];
        }

        bool WString::equals(LPCTSTR str2){
            if( _tcscmp(str,str2)==0){
                return true;
            }
            else{
                return false;
            }
        }

        bool WString::equals(WString str2){
            if( _tcscmp(str,str2.str)==0){
                return true;
            }
            else{
                return false;
            }
        }
        //_tcscmp()
        const char * WString::c_str(){
#ifdef UNICODE
                int len = 2*wcslen(str);//CString,TCHAR汉字算一个字符，因此不用普通计算长度
                char* chStr = new char[len+1];
                wcstombs(chStr,str,len+1);//转换成功返回为非负值
                return chStr;
#else
                return str;
#endif // UNICODE
        }
    }
}
