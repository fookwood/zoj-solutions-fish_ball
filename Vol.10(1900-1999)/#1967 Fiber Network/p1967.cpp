// 3004956 2008-07-25 18:41:14 Accepted 1967 C++ 00:00.47 1868K ´ôÖÍµÄÂý°å 

// ¶¯Ì¬Í¼ Floyd 

#include <iostream>
#include <string> 
#include <bitset>
using namespace std;

bool    G[26][201][201],    B[26];

int     N; 

int main() {
    
    while( scanf( "%d", &N ) && N ) {
        
        memset( G, 0, sizeof( G ) ); 
        
        for( int i = 0; i < 26; ++i )
            for( int j = 1; j <= N; ++j )
                G[i][j][j] = true;

        int     x,  y;
        string  s; 
        
        while( scanf( "%d%d", &x, &y ) && x ) {
            
            cin >> s;
            
            for( int i = 0; i < s.size(); ++i ) {
                int z = s[i]-'a'; 
                B[z] = true;
//                G[z][x][y] = true;
                for( int u = 1; u <= N; ++u ) {
                    if( G[z][u][x] )
                    for( int v = 1; v <= N; ++v )
                        if( G[z][y][v] )
                            G[z][u][v] = true;
                }
            }
            
        }
        
        while( scanf( "%d%d", &x, &y ) && x ) {
            s.erase();
            for( int i = 0; i < 26; ++i )
                if( B[i] && G[i][x][y] )
                    s += ( 'a' + i );
            if( s == "" )   puts( "-" );
            else            puts( s.c_str() );
        } 
        
        puts( "" );

    } 
    
}
