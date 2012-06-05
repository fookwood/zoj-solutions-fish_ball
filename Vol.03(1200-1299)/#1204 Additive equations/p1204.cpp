// 2919206 2008-05-17 09:27:51 Accepted 1204 C++ 00:01.27 7168K 呆滞的慢板 

// 经典 DFS + 分支限界法，注意剪枝不能剪得太多错了。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void disp( const vector<int>& equation ) {
    
    int tot = equation[0];
    cout << equation[0];
    for( int i = 1; i < equation.size(); ++i ) {
        tot += equation[i];
        cout << '+' << equation[i];
    }
    cout << '=' << tot << endl;
    
}

bool icmp( const vector<int>& V1, const vector<int>& V2 ) {
    if( V1.size() < V2.size() ) return  true;
    if( V1.size() > V2.size() ) return  false;
    return  V1 < V2;
}


vector<int> V,  path;
int     N,  T;
vector<vector<int> >    Equ;


void DFS( const int& pos, const int& Sum ) {

    if( pos == N || Sum > V.back() )  return;

    if( binary_search( V.begin() + pos, V.end(), Sum ) )
        Equ.push_back( path );

    path.push_back( V[pos] );
    DFS( pos + 1, Sum + V[pos] );
    path.pop_back();
    DFS( pos + 1, Sum );
    
}


int main() {

    for( cin >> T; T--; ) {

        Equ.clear();
        path.clear();

        cin >> N;
        V.resize( N );

        for( int i = 0; i < N; ++i )
            cin >> V[i];

        sort( V.begin(), V.end() );

        DFS( 0, 0 );

        sort( Equ.begin(), Equ.end(), icmp );
        
        if( Equ.empty() )
            puts( "Can't find any equations." );
        else for( int i = 0; i < Equ.size(); ++i ) {
            if( i == 0 || Equ[i] != Equ[i-1] )
                disp( Equ[i] );
        }

        cout << endl;
        
    }

}
