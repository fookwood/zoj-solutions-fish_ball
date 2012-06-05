// 2954976 2008-06-22 21:07:46 Accepted 2989 C++ 00:00.00 860K 呆滞的慢板 

// 字符串 + 矩阵遍历，螺旋状遍历~~ 注意注意就好~~ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string toString( char c ) {
    if( c == ' ' )
        return  "00000";
    char  ans[6] = "00000";
    c -= ( 'A' - 1 );
    for( int i = 4; i >= 0; --i ) {
        ans[i] += ( c & 1 );
        c >>= 1;
    }
    return  ans;
}

int main() {
    
    int     T,  R,  C,  x1, x2, y1, y2;
    char    B[21][21];
    
    string  s1, s2;
    
    cin >> T;
    
    for( int t = 1; t <= T; ++t ) {
        
        cin >> R >> C;
        getline( cin, s1 );
        s2.erase();
        for( int i = 1; i < s1.size(); ++i )
            s2 += toString( s1[i] );
        s2 += string( R * C - s2.size(), '0' );
        
        int pos = 0;
        x1 = 0; x2 = R - 1;
        y1 = 0; y2 = C - 1;

        while( x1 <= x2 && y1 <= y2 ) {
            for( int i = y1; i <= y2; ++i )
                B[x1][i] = s2[pos++];
            if( ++x1 > x2 ) break;
            for( int i = x1; i <= x2; ++i )
                B[i][y2] = s2[pos++];
            if( --y2 < y1 ) break;
            for( int i = y2; i >= y1; --i )
                B[x2][i] = s2[pos++];
            if( --x2 < x1 ) break;
            for( int i = x2; i >= x1; --i )
                B[i][y1] = s2[pos++];
            if( ++y1 > y2 ) break;
        }

        cout << t << ' ';
        for( int i = 0; i < R; ++i ) 
            for( int j = 0; j < C; ++j )
                putchar( B[i][j] );
        
        cout << endl;
        
    }

    
}
