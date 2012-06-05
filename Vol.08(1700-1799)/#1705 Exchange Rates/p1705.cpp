// 2979746 2008-07-15 14:44:59 Accepted 1705 C++ 00:00.00 880K 呆滞的慢板 

// 很经典的 FLOYD

// 记住，floyd 也是 DP 

#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

vector<string>  VV; 

string  oper,   s1, s2;
    
int x,  y,  m,  n,  t;
    
pair<int, int>  G[60][60];
    
map<string, int>    M;
    
int gcd( int m, int n ) {
    if( !n )    return  m;
    return  gcd( n, m % n );
}

int getIndex( string& s, map<string, int>& M ) {
    
    if( M.find( s ) == M.end() ) {
        
    #ifndef ONLINE_JUDGE 
        VV.push_back( s ); 
        if( VV.back().size() > 7 )
        VV.back().erase( 7 ); 
    #endif 
    
        M.insert( make_pair( s, M.size() ) );
        return  M.size() - 1;
    }
    
    else return M[s];
    
}

int main() {
    
    for( int i = 0; i < 60; ++i )
        G[i][i] = make_pair( 1, 1 );    
    
    while( cin >> oper ) {
        
        if( oper == "." )   break;
        
        else if( oper == "!" ) {
            cin >> x >> s1 >> s2
                >> y >> s2;
            m = getIndex( s1, M );
            n = getIndex( s2, M );
            t = gcd( x, y );
            x /= t, y /= t;
            G[m][n] = make_pair( x, y );
            G[n][m] = make_pair( y, x );
            for( int i = 0; i < M.size(); ++i ) {
                for( int j = 0; j < M.size(); ++j ) { 
                    if( G[i][m].first && G[n][j].first ) {
                        int p = G[i][m].first * x * G[n][j].first,
                            q = G[i][m].second * y * G[n][j].second;
                        t = gcd( p, q );
                        G[i][j] = make_pair( p / t, q / t );
                    }
                    if( G[i][n].first && G[m][j].first ) {
                        int p = G[i][n].first * y * G[m][j].first,
                            q = G[i][n].second * x * G[m][j].second;
                        t = gcd( p, q );
                        G[i][j] = make_pair( p / t, q / t );
                    }
                }
            }
        }
        
        else if( oper == "?" ) {
            cin >> s1 >> s2 >> s2;
            m = getIndex( s1, M );
            n = getIndex( s2, M );
            
            if( G[m][n].first )
                    cout << G[m][n].first << ' ';
            else    cout << "? ";
            cout << s1 << " = ";
            if( G[m][n].second )
                    cout << G[m][n].second << ' ';
            else    cout << "? ";
            cout << s2 << endl;
        }
        
        
    #ifndef ONLINE_JUDGE 
        for( int i = 0; i < M.size(); ++i )
            cout << '\t' << VV[i];
        cout << endl; 
        for( int i = 0; i < M.size(); ++i ) {
            cout << VV[i] << '\t';
            for( int j = 0; j < M.size(); ++j )
                cout << G[i][j].first << '/'
                     << G[i][j].second << '\t'; 
            cout << endl; 
        }
    #endif 
        
    }
    
    
}
