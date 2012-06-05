#include <string>
#include <iostream>
using namespace std;

int DP[5][26] = {};

int main() {
    
    for( int i = 0; i < 26; ++i )
        DP[0][i] = i;
    
    for( int i = 1; i < 5; ++i ) {
        for( int j = 0; j + i < 26; ++j ) {
            for( int k = 0; k < 26; ++k )
                DP[i][j] += DP[i-1][k];
        }
    }
    
    string  input;
    while( cin >> input ) {
        
        bool    valid = true;
        for( int i = 1; i < input.size(); ++i ) {
            if( input[i] <= input[i - 1] ) {
                valid = false;
                break;
            }
        }
        
        if( !valid ) {
            cout << 0 << endl;
            continue;
        }
        
        int ans = 0;
        for( int i = 0; i < input.size(); ++i  ) {
            for( int j = 0; 'a' + j < input[i]; ++j )
                ans += DP[input.size()-i-1][j];
        }
        
        cout << ans + 1 << endl;
        
    }
    
}
