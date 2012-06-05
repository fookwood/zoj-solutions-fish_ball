// 2954981 2008-06-22 21:25:01 Accepted 2990 C++ 00:00.01 864K 呆滞的慢板 

// 字符串 + 矩阵遍历，螺旋状遍历~~ 注意注意就好~~ 
// 关键在于螺旋状遍历，可以重用 2989 的很多代码 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

char fromString( string s ) {
    char    ans = 0;
    for( int i = 0; i < 5; ++i ) {
        ans <<= 1;
        ans += ( s[i] == '1' );
    }
    if( !ans )  return  ' ';
    return  ans + 'A' - 1;
}

int main() {
    
    int     T,  R,  C,  x1, x2, y1, y2;
    char    B[21][21];
    
    string  s1, s2;
    
    cin >> T;
    
    for( int t = 1; t <= T; ++t ) {
        
        cin >> R >> C >> s1;
        
        int pos = 0;
        for( int i = 0; i < R; ++i )
            for( int j = 0; j < C; ++j )
                B[i][j] = s1[pos++];
        
        s1.erase();
        s2.erase();
        pos = 0;
        
        x1 = 0; x2 = R - 1;
        y1 = 0; y2 = C - 1;

        while( x1 <= x2 && y1 <= y2 ) {
            for( int i = y1; i <= y2; ++i ) {
                s1 += B[x1][i];
                if( s1.length() == 5 ) {
                    s2 += fromString( s1 );
                    s1.clear();
                }
            }
            if( ++x1 > x2 ) break;
            for( int i = x1; i <= x2; ++i ) {
                s1 += B[i][y2];
                if( s1.length() == 5 ) {
                    s2 += fromString( s1 );
                    s1.clear();
                }
            }
            if( --y2 < y1 ) break;
            for( int i = y2; i >= y1; --i ) {
                s1 += B[x2][i];
                if( s1.length() == 5 ) {
                    s2 += fromString( s1 );
                    s1.clear();
                }
            }
            if( --x2 < x1 ) break;
            for( int i = x2; i >= x1; --i ) {
                s1 += B[i][y1];
                if( s1.length() == 5 ) {
                    s2 += fromString( s1 );
                    s1.clear();
                }
            }
            if( ++y1 > y2 ) break;
        }

        pos = s2.find_last_not_of( ' ' );
        s2.erase( pos + 1 );

        cout << t << ' ' << s2 << endl;
        
    }

    
}
