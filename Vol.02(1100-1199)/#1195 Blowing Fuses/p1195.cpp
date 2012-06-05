// 2917611 2008-05-16 10:01:42 Accepted 1195 C++ 00:00.01 836K 呆滞的慢板 

// 水题，模拟 

#include <iostream>
using namespace std;

int main() {
    
    int     A[20],  N,  M,  C,  tot, max_val, temp, T = 0;
    bool    B[20],  blown;
    
    while( ( cin >> N >> M >> C ) && ( M || N || C ) ) {
        
        cout << "Sequence " << ++T << endl;
        
        tot = max_val = 0;
        blown = false;
        
        for( int i = 0; i < N; ++i ) {
            cin >> A[i];
            B[i] = false;
        }
            
        for( int i = 0; i < M; ++i ) {
            cin >> temp;
            if( B[temp - 1] )
                    tot -= A[temp - 1];
            else    tot += A[temp - 1];
            B[temp - 1] = !B[temp - 1];
            if( tot > C )       blown = true;
            if( tot > max_val ) max_val = tot;
        }
    
        if( blown )
            puts( "Fuse was blown.\n" );
        else
            cout << "Fuse was not blown.\n"
                    "Maximal power consumption was "
                 << max_val << " amperes.\n" << endl;
    
    }
    
}
