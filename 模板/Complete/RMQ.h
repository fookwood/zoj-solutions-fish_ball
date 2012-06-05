////////////////////////////////////////////////////
//           区间最值查询(RMQ)模板 v1.0           //
///////////////////Documentation////////////////////
//                                                //
//                   模板参数                     //
//  1. T:  序列元素类型;                          //
//  2. Op: 序列元素比较函数，默认为最小优先;      //
//                                                //
//                     方法                       //
//  1. RMQ(T* A, int N): 构造 RMQ，O(NlogN)       //
//         A 为序列头指针，N 为序列长度;          //
//  2. int operator() (int x, int y): O(1)        //
//         查询 [x,y] 内的最值，返回最值下标;     //
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

template <class T, class Op = less<T> >
class RMQ {
    
    int     size;
    int     depth;
    T**     table;
    int**   pos_table;
    
public:
    
    RMQ( T* A, int sz ) : size( sz ) {
        depth = 1;
        while( sz >>= 1 )
            depth += 1;
        table = new T*[depth];
        pos_table = new int*[depth];
        table[0] = new T[size];
        pos_table[0] = new int[size];
        for( int i = 0; i < size; ++i ) {
            table[0][i] = A[i];
            pos_table[0][i] = i;
        }
        for( int i = 1; i < depth; ++i ) {
            int step = 1 << ( i - 1 );
            int len = size - step * 2 + 1;
            table[i] = new T[len];
            pos_table[i] = new int[len];
            for( int j = 0; j < len; ++j ) {
                if( Op()( table[i-1][j], table[i-1][j+step] ) ) {
                    table[i][j] = table[i-1][j];
                    pos_table[i][j] = pos_table[i-1][j];
                }
                else {
                    table[i][j] = table[i-1][j+step];
                    pos_table[i][j] = pos_table[i-1][j+step];
                }
            }
        }
    }
    
    int operator () ( int x, int y ) const {
        if( x == y )    return  x; 
        if( x > y )     swap( x, y ); 
        int width = y - x + 1;
        int dph = 0;
        while( ( 1 << dph ) < width )    ++dph;
        --dph; 
        y = y - ( 1 << dph ) + 1;
        return  Op()( table[dph][x], table[dph][y] ) ?
            pos_table[dph][x] : pos_table[dph][y];
    }
    
    ~RMQ() {
        for( int i = 0; i < depth; ++i ) {
            delete [] table[i];
            delete [] pos_table[i];
        }
        delete [] table;
        delete [] pos_table;
    }
    
};

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////
