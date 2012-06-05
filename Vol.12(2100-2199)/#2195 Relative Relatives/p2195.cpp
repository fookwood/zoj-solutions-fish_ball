// 2977575 2008-07-14 16:42:56 Accepted 2195 C++ 00:00.01 856K 呆滞的慢板 

// 实际上这是一个 DAG
// 递归搞搞搞...用 map 就行 

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int     T,  N;

map<string, int>    AGE;
typedef map<string, int>::iterator A_Iter;
map<string, pair<string, int> > FATHER;
typedef map<string, pair<string, int> >::iterator Iter;
vector<pair<string, int> > V;

int DFS( Iter it ) {
    
    string  s1 = it -> first,
            s2 = it -> second.first;
    int     val = it -> second.second;
    
    FATHER.erase( it );
    
    A_Iter  a_it = AGE.find( s2 );
    
    if( a_it != AGE.end() ) {
        AGE.insert( make_pair( s1, a_it -> second - val ) );
        return  a_it -> second - val;
    }

    else {
        val = DFS( FATHER.find( s2 ) ) - val;
        AGE.insert( make_pair( s1, val ) );
        return  val;
    }
    
}

bool icmp( pair<string, int> p1, pair<string, int> p2 ) {
    if( p1.second > p2.second ) return  true;
    if( p1.second < p2.second ) return  false;
    return  p1.first < p2.first;
}

int main() {
    
    string  s1, s2;
    int     val;
    
    cin >> T;
    
    for( int t = 1; t <= T; ++t ) {
        
        AGE.clear();
        FATHER.clear();
        V.clear();
        AGE["Ted"] = 100;
        
        for( cin >> N; N--; ) {
            cin >> s1 >> s2 >> val;
            FATHER[s2] = make_pair( s1, val );
        }
        
        while( FATHER.size() )
            DFS( FATHER.begin() );
            
        for( A_Iter a_it = AGE.begin(); a_it != AGE.end(); ++a_it )
            V.push_back( *a_it );
            
        sort( V.begin(), V.end(), icmp );
        
        cout << "DATASET " << t << endl;
        
        for( int i = 0; i < V.size(); ++i )
            if( V[i].first != "Ted" )
                cout << V[i].first << ' ' << V[i].second << endl;

    }
    
}
