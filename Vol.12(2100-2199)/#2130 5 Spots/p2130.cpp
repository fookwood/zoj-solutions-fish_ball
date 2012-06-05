// 简单，模拟就行，但是过得比较慢，iostream 也是一个原因
// 2810748 2008-03-30 01:42:04 Accepted 2130 C++ 00:00.81 840K ELF 

#include <iostream>
using namespace std;

char    Fig[60][61];
char    Pattern[60][61];
int     H,  W,  h,  w;

bool match( const int& x, const int& y ) {
    for( int i = 0; i < h; i++ )
        for( int j = 0; j < w; j++ )
            if( Pattern[i][j] == 'O' && Fig[i+x][j+y] != 'O' ||
                Pattern[i][j] == 'X' && Fig[i+x][j+y] != 'X' )
                return  false;
    return  true;
}

int main() {
    while( cin >> H >> W >> h >> w ) {
        for( int i = 0; i < H; i++ )
            cin >> Fig[i];
        for( int i = 0; i < h; i++ )
            cin >> Pattern[i];
        int     count = 0;
        for( int i = 0; i + h <= H; i++ )
            for( int j = 0; j + w <= W; j++ )
                count += match( i, j );
        cout << count << endl;
    }
}
