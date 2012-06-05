// 3050408 2008-08-25 21:03:47 Accepted 1863 C++ 00:00.03 1144K ´ôÖÍµÄÂı°å 

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int     M,  N,  P,  Q;

vector<int> U,  V,  W,  S,  T;

int main() {
    
    while( cin >> M >> N >> P >> Q ) {
    
        N <?= M - N;
        Q <?= P - Q;
    
        U.clear();
        V.clear();
        W.clear();
        S.clear();
        T.clear();
        
        for( int i = M - N + 1; i <= M; ++i )   U.push_back( i );
        for( int i = 2;     i <= N; ++i )       V.push_back( i );
        for( int i = P - Q + 1; i <= P; ++i )   V.push_back( i );
        for( int i = 2;     i <= Q; ++i )       U.push_back( i );
        
        sort( U.begin(), U.end() );
        sort( V.begin(), V.end() );
        
        set_intersection( U.begin(), U.end(),
            V.begin(), V.end(), back_inserter<vector<int> >( W ) ); 
        
        set_difference( U.begin(), U.end(),
            W.begin(), W.end(), back_inserter<vector<int> >( S ) ); 
        
        set_difference( V.begin(), V.end(),
            W.begin(), W.end(), back_inserter<vector<int> >( T ) ); 
        
        double  ans = 1.0;
        
        for( int i = 0; i < min( S.size(), T.size() ); ++i ) {
            ans *= ( double )S[i];
            ans /= ( double )T[i];
        }
        
        for( int i = S.size(); i < T.size(); ++i )  ans /= ( double )T[i];
        
        for( int i = T.size(); i < S.size(); ++i )  ans *= ( double )S[i];
        
        cout.setf( ios::fixed );
        cout.precision( 5 );
        
        cout << ans << endl;

    }
    
}
