// 2922952 2008-05-19 16:58:47 Accepted 2972 C++ 00:00.05 840K 呆滞的慢板 

// DP, V[M] 表示当前阶段体力为 M 的最短时间 

#include <vector>
#include <iostream>
using namespace std;

int main() {
    
    int     T,  N,  M;
    int     T1, T2, T3, F1, F2;
    vector<int> V1, V2;
    
    for( cin >> T; T--; ) {
        
        cin >> N >> M;
        V1.resize( M + 1, -1 );
        
        V1[M] = 0;
        
        for( int i = 0; i < N; ++i ) {

            cin >> T1 >> T2 >> T3 >> F1 >> F2;

            V2.assign( M + 1, -1 );

            for( int j = 0; j <= M; ++j ) {
                
                if( V1[j] != -1 ) {
                    
                    if( V2[j] == -1 ||
                        V2[j] > V1[j] + T2 ) {
                        V2[j] = V1[j] + T2;
                    }
                    if( j >= F1 && (
                        V2[j - F1] == -1 ||
                        V2[j - F1] > V1[j] + T1 ) ) {
                        V2[j - F1] = V1[j] + T1;
                    }
                    if( j + F2 >= M ) {
                        if( V2[M] == -1 ||
                            V2[M] > V1[j] + T3 )
                            V2[M] = V1[j] + T3;
                    }
                    else {
                        if( V2[j + F2] == -1 ||
                            V2[j + F2] > V1[j] + T3 )
                            V2[j + F2] = V1[j] + T3;
                    }
                
                }
                
            }
            
            V1 = V2;
            
        }
        
        int min_val = 999999999;
        for( int i = 0; i <= M; ++i )
            if( V1[i] >= 0 && V1[i] < min_val )
                min_val = V1[i];
                
        cout << min_val << endl;
    
    }
    
}
