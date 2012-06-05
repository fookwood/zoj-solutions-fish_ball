// 3061552 2008-09-06 18:05:42 Accepted 2138 C++ 00:00.09 840K 呆滞的慢板 

// 水题，读清楚就好。 

#include <iostream>
using namespace std;

int T,  N,  P;

int     R[100], C[100];
bool    H[100];

int main() {
    
    for( cin >> T; T--; ) {
        
        memset( R, 0, sizeof( R ) );
        memset( H, 0, sizeof( H ) );
        
        cin >> N >> P;
        
        for( int n = 0; n < N; ++n ) {
            int mn = INT_MAX;
            int mx = INT_MIN;
            for( int i = 0; i < P; ++i ) {
                cin >> C[i];
                mn <?= C[i];
                mx >?= C[i];
            }
            for( int i = 0; i < P; ++i ) {
                if( mn == C[i] ) ++R[i];
                if( mx == C[i] ) H[i] = true;
            }            
        }
        
        bool yes = false;
        for( int i = 0; i < P; ++i ) {
            if( R[i] > N / 2 && !H[i] ) {
                if( yes ) putchar( ' ' );
                cout << i + 1;
                yes = true;
            }
        }
        
        puts( yes ? "" : "0" );
        
        if( T ) puts( "" );

    }
    
}
