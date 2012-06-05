// 2943447 2008-06-06 00:03:14 Accepted 1324 C++ 00:00.00 844K 呆滞的慢板 

// 没什么难度，注意除零 RE 1，后面不能有空格 PE 1 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int     N,  L,  R,  C,  P;
    
    vector<string>  V;
    
    while( cin >> N ) {
        
        V.resize( N );
        L = 0;
        
        for( int i = 0; i < N; ++i ) {
            cin >> V[i];
            if( L < V[i].size() )
                L = V[i].size();
        }
        
        sort( V.begin(), V.end() );
        
        puts( "--------------------"
              "--------------------"
              "--------------------" );
        
        if( L + 2 >= 60 )   C = 1;
        else                C = 60 / ( L + 2 );
        R = ( N - 1 ) / C + 1;
        for( int i = 0; i < R; ++i ) {
            for( int j = 0; ( P = j * R + i ) < N; ++j ) {
                cout << V[P];
                if( P + R < N )
                    cout << string( L+2-V[P].size(), ' ' );
            }
            cout << endl;
        }
        
    }
    
}
