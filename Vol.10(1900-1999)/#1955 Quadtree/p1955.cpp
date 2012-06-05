// 3020225 2008-08-04 00:33:19 Accepted 1955 C++ 00:00.03 872K 呆滞的慢板 

// 此版本由标程修改而来 

// 比较棘手的模拟题，可以不用递归的... 
// 注意输出的时候二进制是倒过来的... 

#include <iostream>
using namespace std;

unsigned char grid[512][64];

void build( int x, int y, int sz ) {
    
    switch( getchar() ) {
    
        case 'B':
            for( int i = x; i < x + sz; ++i )
                for( int j = y; j < y + sz; ++j )
                    grid[i][j/8] |= ( 1 << j%8 );
        break;
        
        case 'W':
            for( int i = x; i < x + sz; ++i )
                for( int j = y; j < y + sz; ++j )
                    grid[i][j/8] &= ~( 1 << j%8 );
        break;
        
        case 'Q':
            sz /= 2;
            build( x,    y,    sz );
            build( x,    y+sz, sz );
            build( x+sz, y,    sz );
            build( x+sz, y+sz, sz );
        break;
        
    }
    
} 


int main() {

//    freopen( "quadtree.in", "r", stdin );
//    freopen( "debug.txt", "w", stdout );

    int     N;

    while( cin >> N >> ws ) {

        build( 0, 0, N ); 
        
        printf( "#define quadtree_width %d\n", N );
        printf( "#define quadtree_height %d\n", N );
        puts( "static char quadtree_bits[] = {" );
        
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < N / 8; ++j )
                printf( "0x%02x,", grid[i][j] );
            puts( "" );
        }
        
        puts( "};" );
        
    }

}
