// 3044933 2008-08-21 17:10:57 Accepted 1599 C++ 00:00.00 844K ´ôÖÍµÄÂý°å 

// ×¢Òâ£ºIf the highway just touches the edge of an estate, it is still considered a crossing. 

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

    int N,  Y1,  Y2;
    
    vector<double>  V;
    
    while( cin >> N >> Y1 >> Y2 ) {
    
        if( Y2 > Y1 )   swap( Y1, Y2 );
        
        V.clear();
        
        double  step = double( Y2 - Y1 ) / double( N );
        
        for( int i = 0; i <= N; ++i )
            V.push_back( step * i + Y1 );
        
        int cnt = 0,    up, down;
        
        for( int i = 0; i < N; ++i ) {
            up = int( ceil( V[i] / 100.0 + 1e-10 ) + 1e-10 );
            down = int( floor( V[i+1] / 100.0 - 1e-10 ) + 1e-10 );
            up <?= N;
            down >?= 0;
            cnt += ( up - down );
        }
        
        cout << cnt << endl;
        
    }

}
