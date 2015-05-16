#include "../include/Wudimei/UI/WTextarea.h"

namespace Wudimei
{
  namespace UI{
    WTextarea::WTextarea()
    {
        this->prepareTextarea();
    }

    WTextarea::WTextarea(LPCTSTR text):WBox(text){
        this->prepareTextarea();
    }
    WTextarea::WTextarea(LPCTSTR text,WBox *parent):WBox(text,parent ){
        this->prepareTextarea();
    }
    WTextarea::WTextarea(LPCTSTR text,WBox *parent,HMENU menuOrControlID ):WBox(text,parent ,menuOrControlID){
        this->prepareTextarea();
    }

    void WTextarea::prepareTextarea(){
        this->boxHandle = NULL;
        this->boxClassName = TEXT("edit");
        this->dwStyle = WS_CHILD | WS_VISIBLE | WS_BORDER | WS_HSCROLL |
         WS_VSCROLL | ES_MULTILINE | ES_AUTOHSCROLL |
         ES_AUTOVSCROLL ;
        //MessageBox(NULL, _T("textarea1"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
        lineText = new TCHAR[2048];
        //lineText[0]='\0';
        ZeroMemory((LPVOID)lineText,sizeof(TCHAR)*2048);
        //MessageBox(NULL, _T("textarea2"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
    }

    void WTextarea::copy(void){
        SendMessage(boxHandle,WM_COPY,0,0);
    }

    void WTextarea::cut(void){
        SendMessage(boxHandle,WM_CUT,0,0);
    }

    void WTextarea::clear(void){
        SendMessage(boxHandle,WM_CLEAR,0,0);
    }

    void WTextarea::paste(void){
        SendMessage(boxHandle,WM_PASTE,0,0);
    }

    void WTextarea::getSelectedRange(int *startPos,int *endPos){
        SendMessage(boxHandle,EM_GETSEL,(WPARAM)startPos,(LPARAM)endPos);
    }

    void WTextarea::setSelectedRange( int startPos,int endPos){
        SendMessage(boxHandle,EM_SETSEL,(WPARAM)startPos,(LPARAM)endPos);
    }

    void WTextarea::replace(LPCTSTR replacement){
        SendMessage(boxHandle,EM_REPLACESEL,(WPARAM)0,(LPARAM)replacement );
    }

    int WTextarea::getLineCount(void){
        return (int)SendMessage(boxHandle,EM_GETLINECOUNT,0,0);
    }

    int WTextarea::getLineOffset(int line){
        return (int)SendMessage(boxHandle,EM_LINEINDEX,(WPARAM)line,0);
    }

    int WTextarea::getLineLength(int line){
        return (int)SendMessage(boxHandle,EM_LINELENGTH,(WPARAM)line,0);
    }

    LPCTSTR WTextarea::getLine(int line){
        SendMessage(boxHandle,EM_GETLINE,(WPARAM)line,(LPARAM)lineText);
        return (LPCTSTR)lineText;
    }

    WTextarea::~WTextarea()
    {
        //dtor
    }
  }
}
