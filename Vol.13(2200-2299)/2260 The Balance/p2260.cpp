#include <cstdio>

inline int abs( const int& x ) {
    return x >= 0 ? x : -x;
}

inline int swap( int& x, int& y ) {
    int t = x;  x = y;  y = t;
}

int main() {
    
    int     X,  Y,  Z,  a[4],  b[4];
    bool    found;
    
    while( scanf( "%d%d%d", &X, &Y, &Z ) && ( X || Y || Z ) ) {
        
        a[0] = found = 0;
        while( a[0] * X <= Z  ) {
            if( ( Z - a[0] * X ) % Y == 0 ) {
                b[0] = ( Z - a[0] * X ) / Y;
                found = true;
                break;
            }
            ++a[0];
        }
        if( !found )
            a[0] = b[0] = 99999999;
        
        a[1] = Z / X + 1;
        found = false;
        while( a[1] * X < 1000000000 ) {
            if( ( a[1] * X - Z ) % Y == 0 ) {
                b[1] = ( a[1] * X - Z ) / Y;
                found = true;
                break;
            }
            ++a[1];
        }
        if( !found )
            a[1] = b[1] = 99999999;
        
        b[2] = found = 0;
        while( b[2] * Y <= Z  ) {
            if( ( Z - b[2] * Y ) % X == 0 ) {
                a[2] = ( Z - b[2] * Y ) / X;
                found = true;
                break;
            }
            ++b[2];
        }
        if( !found )
            a[2] = b[2] = 99999999;
        
        b[3] = Z / Y + 1;
        found = false;
        while( b[3] * Y < 1000000000 ) {
            if( ( b[3] * Y - Z ) % X == 0 ) {
                a[3] = ( b[3] * Y - Z ) / X;
                found = true;
                break;
            }
            ++b[3];
        }
        if( !found )
            a[3] = b[3] = 99999999;
        
        int pos = 0;
        for( int i = 1; i < 4; ++i )
            if( a[pos] + b[pos] > a[i] + b[i] )
                pos = i;
        
//        printf( "pos = %d\n", pos );
        printf( "%d %d\n", a[pos], b[pos] );
        
    }
    
}
