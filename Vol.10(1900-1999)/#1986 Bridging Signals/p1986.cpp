// 2822396 2008-04-04 11:23:03 Accepted 1986 C++ 00:00.21 744K 呆滞的慢板 

// 变形解决，最大上升子序列题，超经典的题，O(nlogn) 才能过
// 算法参考网上某位高人的，放在文件夹里 

#include <cstdio>
#include <cstdlib>

int     A[40000],   D[40000],   P,  T,  len;

int b_search( const int& val, const int& i, const int& j ) {
    if( i + 1 == j || i == j )    return  i;
    if( val > D[ ( i + j ) >> 1 ] )
        return  b_search( val, ( i + j ) >> 1, j );
    else
        return  b_search( val, i, ( i + j ) >> 1 );
}

int main() {
        
    scanf( "%d", &T );
    
    while( T-- ) {
    
        scanf( "%d", &P );
    
        for( int i = 1; i <= P; i++ )
            scanf( "%d", A + i );
    
        D[len = 0] = 0;
    
        for( int i = 1; i <= P; i++ ) {
            if( D[len] < A[i] )
                D[++len] = A[i];
            else {
                int pos = b_search( A[i], 0, len );
                if( D[pos + 1] > A[i] )
                    D[pos + 1] = A[i];
            }
        }
    
        printf( "%d\n", len );
    
    }
    
}
