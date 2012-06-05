// 1835712 2009-04-17 00:06:00 Accepted  2173 C++ 0 184 呆滞的慢板 

// 流布局，很水的模拟题。 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int W, w, h;
    while(cin >> W && W) {
        int mw = 0, mh = 0;
        int rw = W, rh = 0;
        while(cin >> w >> h && w != -1) {
            if(w > W) while(1) puts("OLE!!");
            if(w <= rw) {
                rw -= w;
                mw = max(mw, W - rw);
                rh = max(rh, h);
            }
            else {
                mh += rh;
                rw = W - w; rh = h;
                mw = max(mw, W - rw);
            }
        }
        mh += rh;
        mw = max(mw, W - rw);
        cout << mw << " x " << mh << endl;
    }
}
