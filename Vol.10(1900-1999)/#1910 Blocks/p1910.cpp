// 2942203 2008-06-04 20:14:14 Accepted 1910 C++ 00:00.02 832K 呆滞的慢板 

// 暴力枚举！！不要想当然，把所有可能的情况都要枚举出来！！ 

#include <iostream>
using namespace std;

int main() {
    
    int T,  V,  S,  M,  x,  y,  z,  s;

    for( cin >> T; T--; ) {
        
        cin >> V;
        
        if( !V ) {
            cout << 0 << endl;
            continue;
        }
        
        S = 0x7FFFFFFF;
        for( M = 1; M * M * M < V; ++M );
        
        for( x = 1; x <= V; ++x ) {
            for( y = V / x; y > 0; --y ) {
                if( V % ( x * y ) )
                    continue;
                s = x*y + V/x + V/y;
                S = s < S ? s : S;
            }
        }
        
        cout << S * 2 << endl;
        
    }

}
