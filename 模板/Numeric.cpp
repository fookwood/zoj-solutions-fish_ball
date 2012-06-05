#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

// 拉格朗日插值公式 

template<class DP> 
void polint(const vector<DP>& xa, const vector<DP>& ya,
            const DP& x, DP& y, DP& dy) {
    int i, m, ns = 0;
    DP den, dif, dift, ho, hp, w;
    
    int n = xa.size();
    vector<DP> c(n), d(n);
    dif = fabs(x - xa[0]);
    for(i = 0; i < n; i++) {
        if((dift = fabs(x - xa[i])) < dif) {
            ns = i;
            dif = dift;
        }
        c[i] = ya[i];
        d[i] = ya[i];
    }
    y = ya[ns--];
    for(m = 1; m < n; m++) {
        for(i = 0; i < n - m; i++) {
            ho = xa[i] - x;
            hp = xa[i+m] - x;
            w = c[i+1] - d[i];
            den = ho - hp;
            // 当有相同的 xa 输入的时候，会激活错误 
            assert( den != 0.0 );
            den = w / den;
            d[i] = hp * den;
            c[i] = ho * den;
        }
        y += (dy = (2*(ns+1)<(n-m) ? c[ns+1] : d[ns--]));
    }    
}

#include <iostream>

int main() {
    
    int     N,  T;
    vector<double> xa, ya;
    double y,  dy;
        
    for( cin >> T; T--; ) {

        cin >> N;
        
        xa.resize( N );
        ya.resize( N );

        for( int i = 0; i < N; ++i ) {
            xa[i] = i + 1;
            cin >> ya[i];
        }

        polint<double>( xa, ya, N + 1, y, dy );

        cout.setf( ios::fixed );
        cout.precision( 0 );

        cout << y << endl;

    }

}

