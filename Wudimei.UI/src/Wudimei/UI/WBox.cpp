#ifndef BOX_CPP
#define BOX_CPP


#include "../include/Wudimei/UI/WBox.h"
#include "../include/Wudimei/UI/WApp.h"
namespace Wudimei
{
  namespace UI{
    int WBox::boxNumberSequence=25000;
    WNameList* WBox::boxes =new WNameList();

    WBox::WBox(void)
    {

        this->prepareBox();

        this->parent = (WBox*)NULL;
        //this->parent->boxHandle = NULL;
    }

    WBox::WBox(LPCTSTR text){
        this->prepareBox();
        this->setText( text );
        this->parent = (WBox*)NULL;
        //this->parent->boxHandle = NULL;
    }

    WBox::WBox(LPCTSTR text,WBox *parent){
        this->prepareBox();
        this->setText( text );
        this->parent = parent;
    }

    WBox::WBox(LPCTSTR text,WBox *parent,HMENU menuOrControlID ){
        this->prepareBox();
        this->setText( text );
        this->parent = parent;
        this->menuHandle = menuOrControlID;
    }

    void WBox::prepareBox(){
        this->width =0;
        this->height =0;
        this->top =0;
        this->left =0;


        this->dwExStyle =0;
        this->instanceHandle = WApp::hInstance;
        children = new WNameList();
        this->boxHandle = NULL; //没写上这个认不了了,初始值是随机的
        this->name = NULL; //没初始化产生了不少bug，费了时间，成员变量得初始化
        this->text = NULL;
    }

    WBox::~WBox()
    {
        //dtor
    }

    void WBox::setName(LPCTSTR name ){
        if( name != NULL )
        {
            WBox::boxes->set(name ,(LPVOID)this );
            this->name = name;
        }
    }

    void WBox::setText( TCHAR* text ){
        this->setName((LPCTSTR)text);
    }

    LPCTSTR WBox::getName(){
        return this->name;
    }

    void WBox::alert(LPCTSTR msg){
        MessageBox( NULL, msg, TEXT("title"),MB_OK);
    }

    void WBox::alert(LPCTSTR msg,BOOL show){
        if( show == TRUE )
        {
            this->alert( msg );
        }
    }

    void WBox::create(){
        HWND p=NULL;
        if( parent != (WBox*)NULL )
        {
            p=parent->boxHandle;
        }

        if( p == NULL )
        {
            MessageBox(NULL,TEXT("box parent is null!"),TEXT("hello"),MB_OK);
        }


            boxHandle =CreateWindow(boxClassName,
            text,
            dwStyle,
            left,
            top,
            width,
            height,
                   p,
                   menuHandle,           //控件ID
                   instanceHandle, //实例句柄
                   lpParam);

        ShowWindow(boxHandle,SW_SHOW);
    }

    void WBox::setWidth(int width){
        this->width = width;
        this->_setBounds();
    }

    int WBox::getWidth(){
        return this->width;
    }

    void WBox::setHeight(int height){
        this->height = height;
        this->_setBounds();
    }

    int WBox::getHeight(){
        return this->height;

    }

    void WBox::setLeft(int left){
        this->left = left;
        this->_setBounds();
    }

    int WBox::getLeft(){
        return this->left;
    }

    void WBox::setTop( int top ){
        this->top = top;
        this->_setBounds();
    }

    int WBox::getTop(){
        return this->top;
    }

    void WBox::setBounds(int left, int top, int width, int height){
        this->left = left;
        this->top = top;
        this->width = width;
        this->height = height;
        this->_setBounds();
    }

    void WBox::setLocation(int left,int top){
        this->left = left;
        this->top = top;
        this->_setBounds();
    }

    void WBox::setSize(int width,int height){
        this->width = width;
        this->height = height;
        this->_setBounds();
    }

    void WBox::_setBounds(void){
        if( this->boxHandle != NULL )
        {
            SetWindowPos(this->boxHandle,HWND_TOP,this->left,this->top,this->width,this->height,SWP_SHOWWINDOW);
        }
    }

    void WBox::setText( LPCTSTR text ){
        this->text = text;
        if( this->boxHandle != NULL )
        {
            SetWindowText(this->boxHandle,text);
        }
    }

    LPCTSTR WBox::getText(){
        if( this->boxHandle != NULL )
        {
            LPTSTR str=new TCHAR[1024];
            GetWindowText(  this->boxHandle, str,1024);
            this->text = (LPCTSTR)str;
        }

        return this->text;

    }

    void WBox::add(WBox *box ){
        if( box->menuHandle == NULL )
        {
            WBox::boxNumberSequence++;
            box->menuHandle = (HMENU)WBox::boxNumberSequence;
        }
        if( box->parent == NULL )
        {
            box->parent = this;
        }
        if( box->boxHandle == NULL )
        {
            box->create();
        }
        //MessageBox(NULL, _T("createWindow"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
        if( box->getName()!= NULL )
        {
            //MessageBox(NULL, box->getName(), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
            this->children->set( box->getName(),(LPVOID)box);
            //MessageBox(NULL, _T("createWindow a2"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
        }
        else{
           char  *tmp =new char[30];
           _itoa_s((int)box->menuHandle, tmp,30,10);
           //MessageBox(NULL, _T("createWindow b"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
           this->children->set( (LPCTSTR)tmp,(LPVOID)box);
           //MessageBox(NULL, _T("createWindow c"), _T("Error!"),MB_ICONEXCLAMATION | MB_OK);
        }
    }

    int WBox::getBoxNumber(void){
        return (int)this->menuHandle;
    }

    void WBox::show(void){
        ShowWindow(boxHandle,SW_SHOWNORMAL);
    }

    void WBox::hide(void){
        ShowWindow(boxHandle,SW_HIDE);
    }

    BOOL WBox::isVisible(void){
        return IsWindowVisible(boxHandle);
    }

    void WBox::setEnable(BOOL enable){
        EnableWindow(boxHandle,enable);
    }

    BOOL WBox::isEnabled(void){
        return IsWindowEnabled(boxHandle);
    }


  }
}
#endif
