// 2925882 2008-05-20 23:59:57 Accepted 2164 C++ 00:00.04 840K 呆滞的慢板 

// 简单模拟题，不用多想，直接硬搞 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> V1, V2;
    
    int N,  R,  P,  C;
    
    while( ( cin >> N >> R ) && N ) {
    
        V1.resize( N );
        
        for( int i = 0; i < N; ++i ) 
            V1[i] = N - i;
        
        while( R-- ) {
        
            V2 = V1;
            
            cin >> P >> C;
            
            for( int i = 0; i < C; ++i )
                V1[i] = V2[P + i - 1];
            
            for( int i = 0; i < P - 1; ++i )
                V1[i + C] = V2[i];
        
        }
        
        cout << V1[0] << endl;
    
    }
    
}
