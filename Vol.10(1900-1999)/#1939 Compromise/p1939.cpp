// 2903677 2008-05-10 13:39:13 Accepted 1939 C++ 00:00.00 920K 呆滞的慢板 

// 保存路径的最长公共子串，DP 

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int DP[101][101],   Trace[101][101];
vector<string>  V1, V2, V3;
string  input;

int main() {
    
    while( 1 ) {
        
        V1.clear();
        V2.clear();
        V3.clear();
        
        while( ( cin >> input ) && input != "#" )
            V1.push_back( input );
        
        while( ( cin >> input ) && input != "#" )
            V2.push_back( input );

        for( int i = 0; i <= V1.size(); ++i )
            DP[i][0] = 0;
            
        for( int j = 1; j <= V2.size(); ++j ) {
            DP[0][j] = 0;
            for( int i = 1; i <= V1.size(); ++i ) {
                if( V1[i-1] == V2[j-1] &&
                    DP[i-1][j-1] + 1 > DP[i][j-1] &&
                    DP[i-1][j-1] + 1 > DP[i-1][j] ) {
                    DP[i][j] = DP[i-1][j-1] + 1;
                    Trace[i][j] = 0;    // 0 代表获取字符串(向斜上回溯)
                }
                else if( DP[i-1][j] > DP[i][j-1] ) {
                    DP[i][j] = DP[i-1][j];
                    Trace[i][j] = 1;    // 1 表示忽略串 1，x - 1，(向上回溯) 
                }
                else {
                    DP[i][j] = DP[i][j-1];
                    Trace[i][j] = 2;    // 2 表示忽略串 2，y - 1，(向左回溯) 
                }
            }
        }

        int     x = V1.size(),  y = V2.size();
        
        while( x && y ) {
            
            if( Trace[x][y] == 0 ) {
                V3.push_back( V1[x-1] );
                --x;    --y;
            }
            
            else if( Trace[x][y] == 1 )
                    --x;
            else    --y;
            
        }
        
        while( !V3.empty() ) {
            cout << V3.back();
            V3.pop_back();
            if( V3.empty() )    putchar( '\n' );
            else                putchar( ' ' );
        }

        if( cin.eof() ) break;

    }
    
}
