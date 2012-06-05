#include <iostream> 
#include <string> 
using namespace std;

int main() {
    
    int       N,    max,    color[26];
    
    string    adj[26]; 
    
    while( cin >> N ) {
    
        if( !N ) break; 
    
        for( int i = 0; i < N; i++ )    cin >> adj[i];
    
        for( int i = 0; i < N; i++ )    color[i] = 0;
    
        max = 1; 
    
        for( int i = 0; i < N; i++ ) {
    
            bool    clr[26];
    
            for( int j = 0; j < N; j++ )    clr[j] = false; 
    
            for( int j = 2; j < adj[i].size(); j++ )
    
                if( color[adj[i][j] - 'A'] ) 
    
                    clr[color[adj[i][j] - 'A'] - 1] = true;
            int    x;
    
            for( x = 0; clr[x]; x++ );

            color[i] = x + 1;

            if( color[i] > max )    max = color[i]; 

        }

        if( max == 1 )    cout << "1 channel needed." << endl;
        else        cout << max << " channels needed." << endl; 

    }

} 
