const size_t max_N = 500000;

template <class Item>
int mergeAB( Item c[], Item a[], int N,
                        Item b[], int M ) {
    int inv = 0, i = 0, j = 0, k = 0;
    for( ; k < N + M; ++k ) {
        if( i == N ) { c[k] = b[j++]; continue; }
        if( j == M ) { c[k] = a[i++]; continue; }
        c[k] = ( a[i] < b[j] ) ? a[i++] :
            ( inv += ( N - i ), b[j++] );
    }
    return  inv;
}

template <class Item>
void merge( Item a[], int l, int m, int r ) {
    int     i,  j;
    static  Item aux[maxN];
    for( i = m + 1; i > l; --i )    aux[i-1] = a[j-1];
    for( j = m; j < r; ++j )        aux[r+m-j] = a[j+1];
    for( int k = l; k <= r; ++k )
        if( aux[j] < aux[i] )
            a[k] = aux[j--];
        else
            a[k] = aux[i++];
}

template <class Item>
int mergesortABr( Item a[], Item b[], int l, int r ) {
    if( r - l <= 1 ) return 0;
    int inv = mergesortABr( b, a, l, m );
    inv += mergesortABr( b, a, m + 1, r );
    inv += mergeAB( a+l, b+l, m-l+1, b+m+1, r-m );
    return  inv;
}
