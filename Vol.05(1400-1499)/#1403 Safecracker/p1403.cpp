// 3027353 2008-08-08 02:01:44 Accepted 1403 C++ 00:00.18 840K 呆滞的慢板 

// 霸王硬上弓...生成全排列... 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char        X[6] = {},   C[13];

long long   V[5];

int         L,      P[5];

long long   target;

long long getval() {
    for( int i = 0; i < 5; ++i )
        V[i] = X[i] - 64;
    long long ans = 0,  k;
    for( int i = 0; i < 5; ++i ) {
        k = V[i];
        for( int j = 0; j < i; ++j )
            k *= -V[i];
        ans += k;
    }
    return  ans;
}

int main() {
    
    string      ans;

    while( cin >> target >> C ) {
        
        if( target == 0 && string( C ) == "END" )   break;
        L = strlen( C );
        
        sort( C, C + L );
        
        ans.erase();
        
        for( P[0] = 0; P[0] < L; ++P[0] )
        for( P[1] = P[0]+1; P[1] < L; ++P[1] )
        for( P[2] = P[1]+1; P[2] < L; ++P[2] )
        for( P[3] = P[2]+1; P[3] < L; ++P[3] )
        for( P[4] = P[3]+1; P[4] < L; ++P[4] ) {
            for( int i = 0; i < 5; ++i )
                X[i] = C[P[i]];
            do {
                if( getval() == target && ans < X )
                    ans = X;
            } while( next_permutation( X, X + 5 ) );
        }
        
        if( ans == "" ) puts( "no solution" );
        else    cout << ans << endl;
            
    }

}
