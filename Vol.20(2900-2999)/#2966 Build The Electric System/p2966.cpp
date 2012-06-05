// 2921861 2008-05-18 20:35:58 Accepted 2966 C++ 00:00.33 908K 呆滞的慢板 

// 最小生成树，还是 ms 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    
    int     x,  y,  len;
    
    void getE() { cin >> x >> y >> len; }
    
};

bool operator < ( const Edge& e1, const Edge& e2 ) {
    return  e1.len < e2.len;
}

int main() {
    
    int     T,  V,  E;
    
    vector<int>     Set;
    vector<Edge>    edge;
    
    for( cin >> T; T--; ) {
        
        cin >> V >> E;
        Set.resize( V );
        edge.resize( E );
        
        for( int i = 0; i < V; ++i )
            Set[i] = i;
        
        for( int i = 0; i < E; ++i )
            edge[i].getE();
        
        sort( edge.begin(), edge.end() );
        
        int     tot = 0, cnt = 0;
        
        for( int i = 0; i < E; ++i ) {
            
            int     p,  q,  m,  n;
            
            m = p = edge[i].x;
            n = q = edge[i].y;
            
            while( m != Set[m] )    m = Set[m];
            while( n != Set[n] )    n = Set[n];
            
            if( m == n )    continue;
            
            ++cnt;
            tot += edge[i].len;
            
            Set[n] = m;
            while( Set[q] != m ) {
                p = Set[q];
                Set[q] = m;
                q = p;
            }
            
            if( cnt == V * ( V - 1 ) / 2 )
                break;
            
        }
        
        cout << tot << endl;
        
    }
    
}
