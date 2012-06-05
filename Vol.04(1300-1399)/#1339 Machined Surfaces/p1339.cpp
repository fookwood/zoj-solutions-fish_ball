// 很简单的一道题，WA 了 N 次，原因是没看清楚题
// (character "B" for ease of reading. The actual
// input file will use the ASCII-space character, not "B"). 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string  VS[13];
    int     VI[13];
    int     N;
    while( ( cin >> N ) && N ) {
        getchar();
        for( int n = 0; n < N; n++ ) {
            getline( cin, VS[n] );
            VI[n] = 0;
            for( int i = 0; i < 25; i++ )
                if( VS[n][i] != 'X' )
                    VI[n]++;
        }
        int     Min = VI[0],    Sum = 0;
        for( int n = 0; n < N; n++ ) {
            Sum += VI[n];
            if( VI[n] < Min )
                Min = VI[n];
        }
        cout << ( Sum - Min * N ) << endl;
    }
}
