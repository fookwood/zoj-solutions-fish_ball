// 3014845 2008-07-30 23:59:16 Accepted 1946 C++ 00:00.02 860K 呆滞的慢板 

// 求结账的简化问题，把数统计起来一起算就好，贪心 

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int T = 1,  V,  E;

map<string, int>    M;
string  s1, s2, N[1000];
int     S[1000],    val;
vector<int> v1, v2;

int main() {
    
    while( cin >> V >> E && V ) {
        
        printf( "Case #%d\n", T++ );
        
        M.clear();
        
        memset( S, 0, sizeof( S ) );
        
        for( int i = 0; i < V; ++i ) {
            cin >> N[i];
            M[N[i]] = i;
        }
        
        for( int i = 0; i < E; ++i ) {
            cin >> s1 >> s2 >> val;
            S[M[s1]] += val;
            S[M[s2]] -= val;
        }
        
        v1.clear();
        v2.clear();
        
        for( int i = 0; i < V; ++i ) {
            if( S[i] > 0 )  v1.push_back( i );
            if( S[i] < 0 )  v2.push_back( i );
        }
        
        while( !v1.empty() ) {
            val = min( S[v1.back()], -S[v2.back()] );
            cout << N[v2.back()] << ' ' 
                 << N[v1.back()] << ' ' << val << endl;
            S[v1.back()] -= val;
            S[v2.back()] += val;
            if( S[v1.back()] == 0 ) v1.pop_back();
            if( S[v2.back()] == 0 ) v2.pop_back();
        }
        
        puts( "" );
        
    }
    
}
