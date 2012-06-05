//////////////////////////////////////////////////////
//                    树状数组 v1.0                 //
///////////////////Documentation//////////////////////
//                                                  //
// 维护一个序列，支持 logn 的修改和 logn 的部分和   //
//                                                  //
// 1. resize():   修改序列长度并全部重置为 0;       //
// 2. change():   修改序列某个位置的值;             //
// 3. alter():    增加某个位置元素的值;             // 
// 4. getsum():   获取序列的前 n 项和;              // 
// 5. getpart():  获取序列一个左闭右开区间的部分和; // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template<int SZ>
class TArray {
    
    int     sum[SZ + 2];
    int     val[SZ + 2];
    int     size;

    static int lowbit( int x ) { return  x & ( x ^ ( x - 1 ) ); }

public:
       
    void resize( int sz ) {
        memset( this, 0, sizeof( *this ) );
        size = sz + 1;
    }
    
    void alter( int pos, int num ) {
        val[++pos] += num;
        while( pos <= size ) {
            sum[pos] += num;
            pos += lowbit( pos );
        }
    }
    
    void change( int pos, int num ) {
        num -= val[pos + 1];
        alter( pos, num ); 
    }

    int getsum( int pos ) const {
        int ans = 0;
        for( ++pos; pos > 0; pos -= lowbit( pos ) )
            ans += sum[pos];
        return  ans;
    }
    
    int getpart( int left, int right ) {
        return  getsum( right ) - getsum( left );
    } 

};

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

int main() {
    
    TArray<10>  array;
    
    array.resize( 10 );

    for( int i = 0; i < 10; ++i )
        array.change( i, i ); 
        
    for( int i = 0; i < 10; ++i )
        cout << array.getsum( i ) << endl; 

    array.change( 2, 10 );
    
    for( int i = 0; i < 10; ++i )
        cout << array.getsum( i ) << endl; 
    
    system( "pause" ); 
    
    
} 
