// 解析几何，用定比分点做比较方便
// 这个四舍五入是大大地恶心 
// 2809532 2008-03-29 16:40:07 Accepted 1199 C++ 00:00.00 836K 呆滞的慢板 

#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-5;

int main() {
    int     T,  x1, y1, r1, x2, y2, r2;;
    double  x3, y3;
    cin >> T;
    cout.setf( ios :: fixed );
    cout.precision( 2 );
    while( T-- ) {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        if( r1 == r2 ||
            ( x1 - x2 ) * ( x1 - x2 ) +
            ( y1 - y2 ) * ( y1 - y2 ) <=
            abs( ( r1 - r2 ) * ( r1 - r2 ) ) ) {
            cout << "Impossible.\n";
            continue;
        }
        // 注意在设置精度之后，cout << 1.555; 的结果是 1.55，不合要求( 应该舍入到 1.56 )
        // 因此乘一个 100 round 之后再除 100，然后除的时候精度有危险，再加一个 EPS 输出
        // 因为同样的理由，cout << 1.99999999; 的结果是 1.99，这使我 WA 了很多次 
        x3 = round( double( r2 * x1 - r1 * x2 ) / double( r2 - r1 ) * 100.0 ) / 100.0 + EPS;
        y3 = round( double( r2 * y1 - r1 * y2 ) / double( r2 - r1 ) * 100.0 ) / 100.0 + EPS;
        cout << x3 << ' ' << y3 << endl;
    }
}
