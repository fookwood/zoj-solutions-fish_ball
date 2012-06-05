// 2921789 2008-05-18 20:17:44 Accepted 2969 C++ 00:00.62 840K ´ôÖÍµÄÂý°å 

// ¼òµ¥£¬ms too 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int     T,  N;
    vector<int> V;
    
    for( cin >> T; T--; ) {
        
        cin >> N;
        
        V.resize( N + 1 );
        
        for( int i = 0; i <= N; ++i )
            cin >> V[i];
            
        if( N == 0 ) {
            puts( "0" );
            continue;
        }
        
        for( int i = 1; i <= N; ++i )
            V[N - i + 1] = i * V[N - i];

        cout << V[1];
        for( int i = 2; i <= N; ++i )
            cout << ' ' << V[i];
        
        cout << endl;
        
    }
    
}
