// 2958012 2008-06-28 20:08:08 Accepted 2243 C++ 00:01.24 9264K 呆滞的慢板 

// 太感动了...终于过了...
// 整体把握是一个二叉树的处理，先按照二叉查找堆的方式建立树，然后中序输出

// 关键问题在于建树的过程，出于效率的原因，
//      要使用 RMQ 来优化，为此卡了我很长时间
// 先对整个树的所有节点按名称升序排好，nlogn 
// 然后对整个树的节点产生一个 RMaxQ 预处理，nlogn 

// 然后，开始建树： 
// 注意，开始的树节点都是按指针存好在一个数组里的，但是左右儿子都是 NULL 
// 然后，递归建树，先是全序列 RMaxQ，找出最大的作为根
// 然后这个根的左面子序列建一个左子树，右面的子序列建一个右子树（先序）
// 这样树就建好了 
// 这样算下来，由于 RMaxQ 是 O(1) 的，建树复杂度为 O(n) 

// 最后，中序输出这个树，先 '(' 然后左子树，然后本节点，然后右子树，然后 ')'
// 大功告成，这题相当的经典，还顺带搞了个 RMQ 模板，感觉很爽！ 

#include <iostream>
#include <string>
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
    
    pair<T, int> operator () ( int x, int y ) const {
        if( x == y )    return  make_pair( table[0][x], x ); 
        int width = y - x + 1;
        int dph = 0;
        while( ( 1 << dph ) < width )    ++dph;
        --dph; 
        y = y - ( 1 << dph ) + 1;
        if( Op()( table[dph][x], table[dph][y] ) )
            return  make_pair( table[dph][x], pos_table[dph][x] );
        else
            return  make_pair( table[dph][y], pos_table[dph][y] );
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


struct Elem {

    int     num;
    Elem*   left;
    Elem*   right;
    string  label;

    Elem() {}

    Elem( int ) : left( NULL ), right( NULL ) {
        char    str[15];
        scanf( "%s", str );
        for( num = 0; str[num] != '/'; num++ );
        str[num] = 0;
        label = str;
        num = atoi( str + num + 1 );
    }
     
};

int     N;

Elem*   root;
Elem*   V[50004];

class val_cmp {
public:
    bool operator () ( Elem* e1, Elem* e2 ) {
        return  e1 -> num > e2 -> num;
    }
};

inline bool label_cmp ( Elem* e1, Elem* e2 ) {
    return  e1 -> label < e2 -> label;
}

void build( Elem* root, int l, int m, int r, const RMQ<Elem*, val_cmp> &rmq ) {
    if( l < m ) {
        int pos = rmq( l, m - 1 ).second; 
        root -> left = V[pos];
        build( root -> left, l, pos, m - 1, rmq ); 
    } 
    if( m < r ) {
        int pos = rmq( m + 1, r ).second;
        root -> right = V[pos];
        build( root -> right, m + 1, pos, r, rmq ); 
    } 
}

void disp( Elem* root ) {
    if( !root ) return;
    putchar( '(' );
    disp( root -> left );
    printf( "%s/%d", root -> label.c_str(), root -> num );
    disp( root -> right );
    putchar( ')' );
    return;
}

void destroy( Elem* root ) {
    if( !root ) return;
    destroy( root -> left );
    destroy( root -> right );
    delete( root );
}

int main() {
    
    while( scanf( "%d", &N ) && N ) {
        
        for( int i = 0; i < N; i++ )
            V[i] = new Elem( 1 );

        sort( V, V + N, label_cmp );
        
        RMQ<Elem*, val_cmp> rmq( V, N );
        
        root = rmq( 0, N - 1 ).first;
        
        build( root, 0, rmq( 0, N - 1 ).second, N-1, rmq );

        disp( root );
        putchar( '\n' );
        destroy( root );
        
    }

}
