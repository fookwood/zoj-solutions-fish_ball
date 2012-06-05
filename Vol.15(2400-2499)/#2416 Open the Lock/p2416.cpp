// BFS
// 2812655 2008-03-30 22:50:28 Accepted 2416 C++ 00:00.07 876K ´ôÖÍµÄÂý°å 

#include <cstdio>
#include <cstring>
#include <deque>
using std :: deque;

struct Code {
    Code() {}
    Code( char* s, int cnt ) : count( cnt ) {
        c[0] = s[0] - '1';
        c[1] = s[1] - '1';
        c[2] = s[2] - '1';
        c[3] = s[3] - '1';
    }
    char    c[4];
    int     count;
    bool    match( char* s );
};

bool Code :: match( char* s ) {
    return  c[0] == s[0] - '1' &&
            c[1] == s[1] - '1' &&
            c[2] == s[2] - '1' &&
            c[3] == s[3] - '1' ;
}

bool    mark[9][9][9][9];

inline bool& Mark( const Code& code ) {
    return  mark[code.c[0]][code.c[1]][code.c[2]][code.c[3]];
}

int main() {
    int     T;
    char    A[5],   B[5],   ch;
    scanf( "%d", &T );
    deque<Code> Q;
    Code    now,    temp;
    while( T-- ) {
        scanf( "%s%s", A, B );
        memset( mark, 0, 6561 * sizeof( bool ) );
        Q.resize( 0 );
        Q.push_back( Code( A, 0 ) );
        Mark( Q.back() ) = true;
        while( Q.size() ) {
            now = Q.front();
            if( now.match( B ) )
                break;
            Q.pop_front();
            for( int i = 0; i < 4; i++ ) {
                temp = now;
                temp.c[i] = ( temp.c[i] + 1 ) % 9;
                temp.count++;
                if( !Mark( temp ) ) {
                    Q.push_back( temp );
                    Mark( temp ) = true;
                }
                temp.c[i] = ( temp.c[i] + 7 ) % 9;
                if( !Mark( temp ) ) {
                    Q.push_back( temp );
                    Mark( temp ) = true;
                }                
            }
            for( int i = 0; i < 3; i++ ) {
                temp = now;
                ch = temp.c[i];
                temp.c[i] = temp.c[i + 1];
                temp.c[i + 1] = ch;
                temp.count++;
                if( !Mark( temp ) ) {
                    Q.push_back( temp );
                    Mark( temp ) = true;
                }
            }
        }
        printf( "%d\n", now.count );
    }
}
