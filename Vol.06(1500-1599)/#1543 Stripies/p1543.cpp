// 将原式稍微展开，发现最多的数字开方了 N 次
// 然后是 N-1 次....
// 其余均是不变的常数... 
// 因此贪心让大的数先结合，预排序即可。 

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    
    vector<double>  V;
    
    int     N;
    
    cout.setf( ios::fixed );
    cout.precision( 3 );
    
    while( cin >> N ) {
        
        V.resize( N );
        
        for( int i = 0; i < N; ++i )
            cin >> V[i];
            
        sort( V.begin(), V.end(), greater<double>() );
        
        double  ans = V[0];
        
        for( int i = 1; i < N; ++i )
            ans = 2.0 * sqrt( V[i] * ans );
            
        cout << ans << endl;
        
    }
    
}
