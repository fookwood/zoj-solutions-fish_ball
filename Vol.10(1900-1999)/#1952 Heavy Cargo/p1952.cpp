// 2875295 2008-04-27 21:17:00 Accepted 1952 C++ 00:00.18 904K 呆滞的慢板
// 求最大连通路径，类 Kruscal 算法，并查集 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

////////////////////////////////////////////////////
//                 并查集模板 v1.0                //
////////////////////////////////////////////////////
//                                                //
//  1. SZ: 并查集最大元素总数(模板参数);          //
//  2. init:  初始化 N 各元素的并查集;            //
//  3. check: 检查两个元素是否共集，并合并之;     //
//  4. getSets: 返回并查集的子集个数;             //
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

template<int SZ> class Union {
    int elem,   subSets;
    int* U;
public:
    Union( int N = 0 ) : elem( N ), subSets( N )
        { U = new int[SZ]; }
    void init( const int& );
    bool check( int, int ) const;
    bool merge( const int&, const int& );
    int getSets() const { return subSets; }
    ~Union() { delete [] U; }
};

template<int SZ> void Union<SZ>::init( const int& N ) {
    elem = subSets = N;
    for( int i = 1; i <= N; i++ )   U[i] = i;
}

template<int SZ> bool Union<SZ>::check( int x, int y ) const {
    while( U[x] != x ) x = U[x];
    while( U[y] != y ) y = U[y];
    return x == y;
}

template<int SZ> bool Union<SZ>::merge( const int& x, const int& y ) {
    int p = x, q = y, r = y;
    while( U[p] != p ) p = U[p];
    while( U[q] != q ) q = U[q];
    if( p == q ) return true;
    U[q] = p;
    while( U[r] != p ) {
        q = U[r];
        U[r] = p;
        r = q;
    }
    subSets--;
    return  false;
}

//////////////////////  MAIN PROCEDURE  ///////////////////////

struct Edge {
    
    int x,  y,  len;

    Edge() {}
    Edge( int x, int y, int len ) :
        x( x ), y( y ), len( len ) {}

};

bool icmp( const Edge& e1, const Edge& e2 ) {
    return  e1.len > e2.len;
}


int main() {
    
    int     V,  E,  S,  D,  v,  e,  T = 0;

    map<string, int>    Vname;
    map<string, int>::iterator iter;
    Union<201>  U;
    vector<Edge>    edge;
    
    string  s1, s2;
    int     val;
    

    while( ( cin >> V >> E ) && ( V || E ) ) {
        
        Vname.clear();
        edge.clear();
        v = 1;
        
        for( int i = 0; i < E; i++ ) {
            
            cin >> s1 >> s2 >> val;

            iter = Vname.find( s1 );
            if( iter == Vname.end() ) {
                Vname.insert( make_pair( s1, v ) );
                S = v++;
            }
            else  S = iter -> second;

            iter = Vname.find( s2 );
            if( iter == Vname.end() ) {
                Vname.insert( make_pair( s2, v ) );
                D = v++;
            }
            else  D = iter -> second;

            edge.push_back( Edge( S, D, val ) );

        }

        cin >> s1 >> s2;
        S = Vname.find( s1 ) -> second;
        D = Vname.find( s2 ) -> second;
        
        sort( edge.begin(), edge.end(), icmp );

        cout << "Scenario #" << ++T << endl;

        int pos = 0;
        U.init( V );
        
        for( int i = 0; i < edge.size(); i++ ) {
            if( U.check( S, D ) ) break;
            U.merge( edge[i].x, edge[i].y );
            pos = i;
        }
        
        cout << edge[pos].len << " tons\n";
        
        cout << endl;
        
    }
    
}
