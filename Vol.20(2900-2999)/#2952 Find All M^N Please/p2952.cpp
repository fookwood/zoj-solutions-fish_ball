// 2812297 2008-03-30 20:49:57 Accepted 2952 C++ 00:00.09 1364K ´ôÖÍµÄÂý°å 

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int     i,  j;
    long long  p;
    vector<long long> Q( 1, 0 );
    for( i = 2; i < 46342; i++ )
        for( j = 2; ( p = (long long)( pow( double(i), double(j) ) ) ) <= 2147483648ll; j++ )
            Q.push_back( (long long)( pow( double(i), double(j) ) + 1e-5 ) );
    sort( Q.begin(), Q.end() );
    for( int k = 1; k < Q.size() - 1; k++ )
        if( Q[k] != Q[k - 1] )
            printf( "%d\n", int( Q[k] ) );
}
