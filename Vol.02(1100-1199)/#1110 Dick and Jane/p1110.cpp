// 1693744 2008-11-08 22:58:57 Accepted  1110 C++ 0 184 呆滞的慢板 

// 胡乱枚举收缩一下情况就可以了。 

#include <iostream>
using namespace std;

int s, p, y, j;
int S, P, Y;

int main() {
    while(cin >> s >> p >> y >> j) {
        j += 12;
        for(Y = (j - p - y) / 3; Y < j; ++Y) {
            for(P = (j - Y - s) / 2; P < j; ++P) {
                S = j - Y - P;
                if(S - P > s+1 || S - P < s ||
                    P - Y > p+1 || P - Y < p ||
                    S - Y > y+1 || S - Y < y) {
                    continue;
                }
                cout << S << ' '<<P <<' '<<Y<<endl;
            }
        }
    }
}
