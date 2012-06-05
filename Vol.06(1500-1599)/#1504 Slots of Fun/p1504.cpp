// 2955554 2008-06-24 00:42:45 Accepted 1504 C++ 00:00.01 848K 呆滞的慢板 

// 不顾效率的乱搞，太疯狂了...

// 原来的方案是主三角形内中心对称的三个点遍历一次
// 然后发现原来不是这个中心对称也行
// 于是快速换了一个乱搞的方案
// 就是遍历所有主三角形的子三角形做这个工作
// 居然轻易的就 AC 了 

#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

char        G[12][12];
int         N,  pos;
string      str;
set<char>   S;
set<char>::iterator it;

// M 是子三角形的大小，x, y 是左上角点的坐标 
void scan( int M, int x, int y ) {
    int k = M / 2;
    for( int i = 0; i < k; ++i ) {
        for( int j = 0; j < M - 1 - i - i; ++j ) {
            if( G[x+j+i][y+i] == G[x+M-1-i][y+i+j] &&
                G[x+j+i][y+i] == G[x+M-1-i-j][y+M-1-i-j] )
                S.insert( G[x+j+i][y+i] );
        }
    }
}

int main() {
    
    while( cin >> N && N ) {
    
        cin >> str;
        
        memset( G, 0, sizeof( G ) );
        
        int pos = 0;
        for( int i = 0; i < N; ++i )
            for( int j = 0; j <= i; ++j )
                G[i][j] = str[pos++];
    
        S.clear();
        
/*  这段用来显示三角形，在行首加 '/' 注释本行激活 
        for( int i = 0; i < N; ++i )
            cout << G[i] << endl;
//*/
        
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j <= i; ++j ) {
                for( int p = 2; p + i <= N; ++p ) {
                    scan( p, i, j );
                }
            }
        }
        
        if( S.empty() )
            puts( "LOOOOOOOOSER!" );
    
        else {
            copy( S.begin(), S.end(), ostream_iterator<char>( cout ) );
            puts( "" );
        }
        
    
    }
    
}
