// 先标记可能的格子，然后 DFS 一下再计数，简单快捷 

#include <iostream>
#include <algorithm>
using namespace std;

char    C[8][9];
bool    B[8][8];
int     mx;

int main() {
    
    while( cin >> C[0] ) {
                
        for( int i = 1; i < 8; ++i )
            cin >> C[i];
        
        mx = 0;
        
        for( int t = 0; t < 2; ++t ) {
            
            for( int p = 0; p < 7; ++p ) {
                
                for( int q = 0; q < 7; ++q ) {
                    
                    swap( C[p][q], C[p+t][q+1-t] );
            
                    int     val = 0;
                    
                    memset( B, 0, sizeof( B ) );

                    for( int i = 0; i < 6; ++i ) {
                        for( int j = 0; j < 6; ++j ) {
                            if( !C[i][j] )  continue;
                            if( C[i][j] == C[i+1][j] &&
                                C[i][j] == C[i+2][j] ) {
                                B[i][j] = B[i+1][j] =
                                B[i+2][j] = true;
                            }
                            if( C[i][j] == C[i][j+1] &&
                                C[i][j] == C[i][j+2] ) {
                                B[i][j] = B[i][j+1] =
                                B[i][j+2] = true;
                            }
                        }
                    }

                    for( int i = 0; i < 8 ; ++i )
                        for( int j = 0; j < 8; ++j )
                            if( B[i][j] ) ++val;

                    mx >?= val;

                    swap( C[p][q], C[p+t][q+1-t] );
                    
                }

            }

        }
        
        cout << mx << endl;
            
    }
    
}
