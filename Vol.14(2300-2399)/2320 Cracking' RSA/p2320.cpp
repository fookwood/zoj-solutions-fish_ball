#include <iostream>
#include <bitset>
using namespace std;

bool    isPrime[600] = {};
int     Prime[110], N = 0, T, M;

bitset<100> B[101];

int main() {
    
    for( int i = 2; i * i < 600; ++i )
        if( !isPrime[i] )
            for( int j = i * i; j < 600; j += i )
                isPrime[j] = true;

    for( int i = 2; i < 600; ++i )
        if( !isPrime[i] )
            Prime[N++] = i;
    
    for( cin >> T; T--; ) {
        
        cin >> N >> M;
        
        B[0].reset();
        
        for( int i = 1; i <= M; ++i ) {
            B[i].reset();
            int temp;
            cin >> temp;
            for( int j = 0; temp > 1; ++j ) {
                while( temp % Prime[j] == 0 ) {
                    B[i].flip( j );
                    temp /= Prime[j];
                }
            }
            B[i] ^= B[i-1];
        }
        
        int cnt = 0;
        for( int i = 0; i <= M; ++i )
            for( int j = i + 1; j <= M; ++j )
                cnt += ( B[i] == B[j] );
        cout << cnt << endl;

        if( T ) puts( "" );

    }
    
}
