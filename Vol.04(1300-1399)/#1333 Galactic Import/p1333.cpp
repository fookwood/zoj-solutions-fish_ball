// 3063476 2008-09-08 12:54:55 Accepted 1333 C++ 00:00.00 840K ´ôÖÍµÄÂý°å 

// Floyd

#include <iostream>
using namespace std;

double  VL[30];

char    G[30][30];

int DP[30][30];

bool input() {
    fill( VL, VL + 30, 0.0 );
    fill( *G, *G + 30*30, 0 );
    fill( *DP, *DP + 30*30, 1000 );
    int N; char c;
    if( cin >> N ) {
        while( N-- ) {
            cin >> c;
            cin >> VL[c-'A'] >> G[c-'A'];
        }
        for( int i = 0; i < 26; ++i ) {
            DP[i][i] = 0;
            for( int j = 0; G[i][j]; ++j ) {
                if( G[i][j] == '*' ) DP[i][26] = 1;
                else DP[i][G[i][j]-'A'] = DP[G[i][j]-'A'][i] = 1;
            }
        }
        for( int i = 0; i < 27; ++i )
            for( int j = 0; j < 27; ++j ) 
                for( int k = 0; k < 27; ++k )
                    DP[j][k] <?= DP[j][i] + DP[i][k];
        
        return  true;
    }
    return  false;
}

int main() {
    
    while( input() ) {
        
        int     pos = -1;
        double  mx = 0.0;

        for( int i = 0; i < 26; ++i ) {
            for( int j = 2; j < DP[i][26]; ++j )
                VL[i] *= 0.95;
            if( VL[i] > mx + 1e-5 ) {
                mx = VL[i];
                pos = i;
            }
        }
        
        printf( "Import from %c\n", 'A' + pos );
        
    }
    
}
