// 2002998 2009-09-26 17:35:17 Accepted  2220 C++ 0 184 呆滞的慢板 

// 天花板和狗，很水的问题，直接蛮力枚举钉子坐标。
// 注意他是不管绳子长度最优的，只管 x 最优，y 次优，合法即可。 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, S, N, X[50], Y[50];
    for(cin >> T; T--;) {
        cin >> S >> N;
        for(int i = 0; i < N; ++i)
            cin >> X[i] >> Y[i];
        bool found = false;
        for(int x = 1; x < S && !found; ++x) {
            for(int y = 1; y < S && !found; ++y) {
                bool skip = false;
                for(int i = 0; i < N; ++i) {
                    if(x == X[i] && y == Y[i]) {
                        skip = true;
                        break;
                    }
                }
                if(skip) continue;
                int ltd = min(min(x, y), min(S-x, S-y));
                bool yes = true;
                for(int i = 0; i < N; ++i) {
                    if((X[i]-x)*(X[i]-x) + (Y[i]-y)*(Y[i]-y) > ltd * ltd) {
                        yes = false;
                        break;
                    }
                }
                if(yes) {
                    cout << x << ' ' << y << endl;
                    found = true;
                }
            }
        }
        if(!found) cout << "poodle" << endl;
    }
}
