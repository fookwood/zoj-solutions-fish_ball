// 3049983 2008-08-25 15:58:35 Accepted 1824 C++ 00:00.00 2992K ´ôÖÍµÄÂý°å 

#include <iostream>
using namespace std;

int     X,  Y,  x,  y,  d;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

char    C[61][62],  c,  *D = "NESW";

int main() {
    
    while( cin >> X >> Y ) {
        gets( C[0] );
        for( int i = 1; i <= X; ++i )
            gets( C[i] + 1 );
        cin >> x >> y;
        d = 0;
        while( ( c = getchar() ) != 'Q' ) {
            if( !isalpha( c ) ) continue;
            switch( c ) {
                case 'R':
                    d = ( d + 1 ) % 4;
                break;
                case 'L':
                    d = ( d + 3 ) % 4;
                break;
                case 'F':
                    x += dx[d];
                    y += dy[d];
                    if( x < 1 || x > X ||
                        y < 1 || y > Y || C[x][y] == '*' ) {
                        x -= dx[d];
                        y -= dy[d];
                    }
                break;
            }
        }
        cout << x << ' ' << y << ' ' <<D[d] << endl;
    }
    
}
