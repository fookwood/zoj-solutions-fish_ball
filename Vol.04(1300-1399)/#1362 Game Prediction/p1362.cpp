// 2905433 2008-05-11 08:50:38 Accepted 1362 C++ 00:00.01 844K 呆滞的慢板 

// 生成一个尽可能强的对手，然后贪心比较。 

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    
    int M,  N,  T = 1;
    vector<int>  V1,    V2;
    
    while( ( cin >> M >> N ) && ( M || N ) ) {
        
        V1.resize( N );
        for( int i = 0; i < N; ++i )
            cin >> V1[i];
            
        V2.clear();
        for( int i = 0; i < 2 * N; ++i ) {
            bool    yes = true;
            for( int j = 0; j < N; ++j ) {
                if( V1[j] == M * N - i ) {
                    yes = false;
                    break;
                }
            }
            if( yes )   V2.push_back( M * N - i );
        }

        sort( V1.begin(), V1.end(), greater<int>() );
        
        cout << "Case " << T++ << ": ";
        
        int total = 0;

        int j = 0;
        for( int i = 0; i < N; ++i ) {
            if( V1[i] > V2[j] ) ++total;
            else    ++j;
        }
        
        cout << total << endl;
        
    }
    
    
}
