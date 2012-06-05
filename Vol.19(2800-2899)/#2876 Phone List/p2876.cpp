// 2823317 2008-04-04 20:26:28 Accepted 2876 C++ 00:00.59 1124K 呆滞的慢板  

// // 限制较少，容易

#include <string>
#include <cstdio>
#include <algorithm>
using std::sort;
using std::string;

int main() {
    string  S[10000];
    char    str[11];
    int     T,  N;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &N );
        for( int i = 0; i < N; i++ ) {
            scanf( "%s", str );
            S[i] = str;
        }
        sort( S, S + N );
        bool    yes = true;
        for( int i = 1; i < N; i++ ) {
            if( S[i].length() >= S[i - 1].length() &&
                S[i].find( S[i - 1] ) == 0 ) {
                yes = false;
                break;
            }
        }
        puts( yes ? "YES" : "NO" );
    }
}
