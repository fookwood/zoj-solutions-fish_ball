// Ó²ËÑ£¬TLE 
#include <cstdio>
#include <cstdlib>

bool    finish;
char    A[9][10];

void DFS( const int& x, const int& y ) {
    if( x >= 9 || y >= 9 ) {
        finish = true;
        return;
    }
    bool    flag[10] = {1,1,1,1,1,1,1,1,1,1};
    for( int i = 0; i < 9; i++ ) {
        flag[A[x][i] - '0'] = false;
        flag[A[i][y] - '0'] = false;
    }
    int     posx = ( x - x % 3 );
    int     posy = ( y - y % 3 );
    for( int i = 0; i < 3; i++ )
        for( int j = 0; j < 3; j++ )
            flag[A[posx+i][posy+j]-'0'] = false;
    *flag = false;
    for( posx = x; posx < 9; posx++ ) {
        for( posy = 0; posy < 9; posy++ ) {
            if( posx == x && posy == 0 ) {
                posy = y;
                continue;
            }
            if( A[posx][posy] == '0' ) {
                *flag = true;
                break;
            }
        }
        if( *flag ) break;
    }
/*
printf( "px = %d, py = %d\n",posx,posy );
for( int i = 1; i <= 9; i++ )
printf("%d ", flag[i]);
putchar('\n');
for( int i = 0; i < 9; i++ )
puts(A[i]);
putchar('\n');
system("pause");
//*/
    for( int i = 1; i <= 9; i++ ) {
        if( flag[i] ) {
            A[x][y] += i;
            DFS( posx, posy );
            if( finish )    return;
            A[x][y] = '0';
        }
    }
}

int main() {
    int     T;
    scanf( "%d", &T );
    while( T-- ) {
        for( int i = 0; i < 9; i++ )
            scanf( "%s", A[i] );
        finish = false;
        int posx,   posy;
        for( posx = 0; posx < 9; posx++ ) {
            for( posy = 0; posy < 9; posy++ )
                if( A[posx][posy] == '0' )
                    break;
            if( A[posx][posy] == '0' )
                break;
        }
        DFS( posx, posy );
        for( int i = 0; i < 9; i++ )
            puts(A[i]);
    }
}
