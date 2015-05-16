/**
!! this source code has not implements file!!

template class with typename can not be export,
it can be export with realy parameter,such as WVector<int> or WVector<double>
eg:
 WVector<struct TDXDailyItem> arr(20); //need first interge argument.


 WVector<WString*> files(100);
    WDirectory wdir("D:\\");
    //WString *yqr=new WString("sfsa—Ó«Ï»Ÿ");
   //files[0] =yqr;


2. may be you have to test the null pointer.

    wdir.list(&files);
    for(int i=0;i<files.size();i++){
        cout<<"d"<<i<<"  ";
        if( nullptr != files[i] )
        {
            cout<<  files[i]->str  <<endl;
        }

    }
*/
#ifndef WVECTOR_H
#define WVECTOR_H
#include "./DS.h"

//using namespace std;


namespace Wudimei
{
namespace DS
{


template <typename Object>
class WVector
{
public:
    explicit WVector( int initSize = 0 )
        : theSize( initSize ), theCapacity( initSize + SPARE_CAPACITY )
    {
        objects = new Object[ theCapacity ];
    }

    WVector( const WVector & rhs ) : objects( NULL )
    {
        operator=( rhs );
    }

    ~WVector( )
    {
        delete [ ] objects;
    }

    const WVector & operator= ( const WVector & rhs )
    {
        if( this != &rhs )
        {
            delete [ ] objects;
            theSize = rhs.size( );
            theCapacity = rhs.theCapacity;

            objects = new Object[ capacity( ) ];
            for( int k = 0; k < size( ); k++ )
                objects[ k ] = rhs.objects[ k ];
        }
        return *this;
    }

    void resize( int newSize )
    {
        if( newSize > theCapacity )
            reserve( newSize * 2 + 1 );
        theSize = newSize;
    }

    void reserve( int newCapacity )
    {
        if( newCapacity < theSize )
            return;

        Object *oldArray = objects;

        objects = new Object[ newCapacity ];
        for( int k = 0; k < theSize; k++ )
            objects[ k ] = oldArray[ k ];

        theCapacity = newCapacity;

        delete [ ] oldArray;
    }


    Object & operator[]( int index )
    {
        return objects[ index ];
    }

    const Object & operator[]( int index ) const
    {
        return objects[ index ];
    }

    bool empty( ) const
    {
        return size( ) == 0;
    }

    int size( ) const
    {
        return theSize;
    }

    int capacity( ) const
    {
        return theCapacity;
    }

    void push_back( const Object & x )
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }

    void pop_back( )
    {
        theSize--;
    }

    const Object & back ( ) const
    {
        return objects[ theSize - 1 ];
    }

    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin( )
    {
        return &objects[ 0 ];
    }

    const_iterator begin( ) const
    {
        return &objects[ 0 ];
    }

    iterator end( )
    {
        return &objects[ size( ) ];
    }

    const_iterator end( ) const
    {
        return &objects[ size( ) ];
    }

    enum { SPARE_CAPACITY = 16 };

private:
    int theSize;
    int theCapacity;
    Object * objects;
};


}
}

#endif // WVECTOR_H
