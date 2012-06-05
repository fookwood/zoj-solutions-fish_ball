// 2016200 2009-10-17 11:37:51 Accepted  2748 C++ 0 184 呆滞的慢板 

// 足球人墙，很无聊的几何题，注意墙一定是直线，不能是弧线就是了。 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, W, x, y, D, A;
    const double PI = acos(-1.0);
    while(cin >> a >> W >> x >> y >> D >> A) {
        double sa = a + a;
        double sb = sqrt((x-a)*(x-a) + y*y);
        double sc = sqrt((x+a)*(x+a) + y*y);
        double agl = acos(-(sa*sa - sc*sc - sb*sb) / 2.0 / sb / sc);
        agl -= A * PI / 180;
        double ans = tan(agl / 2) * D * 2 / W;
        if(ans <= 0) puts("0");
        else if(ans - int(ans) == 0) cout << ans << endl;
        else cout << int(ans) + 1 << endl;
    }
}
