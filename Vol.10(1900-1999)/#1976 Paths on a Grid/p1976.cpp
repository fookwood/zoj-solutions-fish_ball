// 2941750 2008-06-04 16:34:24 Accepted 1976 C++ 00:00.01 832K 呆滞的慢板 

// 组合数学问题，等价于 C(m+n, n) 

#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long uInt;

uInt comb( uInt x, uInt y ) {
    uInt    ans = 1;
    uInt    xx = x - y;
    uInt    yy = 1;
    while( x > xx ) {
        ans *= ( x-- );
        while( yy <= y && ( ans % yy == 0 ) )
            ans /= ( yy++ );
    }
    return  ans;
}

int main() {
    
    uInt    m,  n;
    
    while( ( cin >> m >> n ) && ( m || n ) )
        cout << comb( m + n, min( n, m ) ) << endl;
    
}
