// 2996693 2008-07-22 16:34:17 Accepted 1047 C++ 00:00.00 448K ´ôÖÍµÄÂý°å 

// 1 ´Î DFS ¸ã¶¨ 

#include <cstdio>
#include <cstring>

char A[21][22];

int X,  Y,  x,  y,  cnt;

int D[8][2] = {
    { 0, 1 },
    { 0, -1 },
    { 1, 0 },
    { -1, 0 },
    { 1, 1 },
    { 1, -1 },
    { -1, 1 },
    { -1, -1 }
};

bool isvalid( int xx, int yy ) {
    return  xx >= 1 && xx <= X &&
            yy >= 1 && yy <= Y;
}

void DFS( int xx, int yy ) {
    A[xx][yy] = 'x';
    for( int i = 0; i < 4; ++i ) {
        if( !isvalid( xx + D[i][0], yy + D[i][1] ) ||
            A[xx + D[i][0]][yy + D[i][1]] == '.' )
            ++cnt;
    }
    for( int i = 0; i < 8; ++i ) {
        if( isvalid( xx + D[i][0], yy + D[i][1] ) &&
            A[xx + D[i][0]][yy + D[i][1]] == 'X' )
            DFS( xx + D[i][0], yy + D[i][1] );
    }
}

int main() {
    
    while( scanf( "%d%d%d%d", &X, &Y, &x, &y ) && X ) {
        
        for( int i = 1; i <= X; ++i )
            scanf( "%s", A[i] + 1 );
            
        cnt = 0;
        
        DFS( x, y );
        
        printf( "%d\n", cnt );
        
    }
    
}
