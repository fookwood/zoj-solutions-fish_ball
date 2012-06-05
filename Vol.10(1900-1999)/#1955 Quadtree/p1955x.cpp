// 3020219 2008-08-04 00:29:24 Accepted 1955 C++ 00:00.20 1820K 呆滞的慢板 

// 模拟题，递归构造，某些部分可用 DP 初始化 
// 注意输出的时候二进制是倒过来的...  

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string>  V;
char    str[200000];
int     N,  M;

// 字符串上所指下一个子树位置
int POS[200000];

string toString( int x ) {
    string  ans( "0x" );
    int a = x / 16, b = x % 16;
    if( a < 10 )    ans += ( '0' + a );
    else            ans += ( 'a' + a - 10 );
    if( b < 10 )    ans += ( '0' + b );
    else            ans += ( 'a' + b - 10 );
    return  ans;
}

void build( int x, int y, int sz, int pos ) {
    
    if( str[pos] == 'W' )
        for( int i = 0; i < sz; ++i )
            for( int j = 0; j < sz; ++j )
                V[x+i][y+j] = '0';
    else if( str[pos] == 'B' )
        for( int i = 0; i < sz; ++i )
            for( int j = 0; j < sz; ++j )
                V[x+i][y+j] = '1';
    else {
        sz /= 2;
        build( x,    y,    sz, pos += 1 );
        build( x,    y+sz, sz, pos = POS[pos] );
        build( x+sz, y,    sz, pos = POS[pos] );
        build( x+sz, y+sz, sz, pos = POS[pos] );
    }
    
} 

void disp() {
    
    printf( "#define quadtree_width %d\n", V.size() );
    printf( "#define quadtree_height %d\n", V.size() );
    puts( "static char quadtree_bits[] = {" );
    
    for( int i = 0, x; i < V.size(); ++i ) {
        for( int j = 0; j < V.size(); j += 8 ) {
            x = 0;
            for( int k = 7; k >= 0; --k ) {
                x *= 2;
                x += ( V[i][j+k] == '1' );
            }
            cout << toString( x ) << ',';
        }
        puts( "" );
    }
    puts( "};" );

}

int main() {

    while( cin >> N >> str ) {

        M = strlen( str );

        for( int i = M - 1; i >= 0; --i ) {
            if( str[i] == 'W' || str[i] == 'B' ) 
                POS[i] = i + 1;
            else {
                int j = i + 1;
                for( int k = 0; k < 4; ++k )
                    j = POS[j];
                POS[i] = j;
            }
        }

        V.assign( N, string( N, '?' ) );

        build( 0, 0, N, 0 ); 
        
        disp();
        
    }

}
