// 3032575 2008-08-12 20:58:38 Accepted 2386 C++ 00:00.73 4744K 呆滞的慢板 

// 困扰好久的题目，nlogn 求逆序对，结果会超 int，为此无数 WA 

#include <iostream>
using namespace std;

template <class Item>
long long mergeAB( Item c[], Item a[], int N,
                             Item b[], int M ) {
    long long   inv = 0;
    int         i = 0, j = 0, k = 0;
    while( k < N + M ) {
        if( i == N ) { c[k++] = b[j++]; continue; }
        if( j == M ) { c[k++] = a[i++]; continue; }
        c[k++] = ( a[i] <= b[j] ) ? a[i++] :
            ( ( inv += ( N - i ) ), b[j++] );
    }
    return  inv;
}

template <class Item>
long long mergesortABr( Item a[], Item b[], int l, int r ) {
    if( r - l <= 1 ) return 0;
    int m = ( l + r ) / 2;
    long long inv = 0;
    inv += mergesortABr( a, b, l, m );
    inv += mergesortABr( a, b, m, r );
    inv += mergeAB( a+l, b+l, m-l, b+m, r-m );
    memcpy( b + l, a + l, ( r - l ) * sizeof( Item ) );
    return  inv;
}


int     N,  A[500000],  B[500000];

int main() {
    
    while( cin >> N && N ) {

        for( int i = 0; i < N; ++i )
            scanf( "%d", A + i );
        
        cout << mergesortABr( B, A, 0, N ) << endl;

    }
    
}
