// 1740874 2009-01-11 12:41:18 Accepted  3107 C++ 0 184 呆滞的慢板 

// 简单的多边形面积计算，不用预存，不用浮点，直接搞。 

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T >> ws;
    for(int t = 1; t <= T; ++t) {
        int x = 0, y = 0, s = 0;
        char c;
        while((c = getchar()) != '\n') {
            int nx = x, ny = y;
            switch(c) {
                case 'R': nx++; break;
                case 'L': nx--; break;
                case 'U': ny++; break;
                case 'D': ny--; break;
            }
            s += x * ny - y * nx;
            x = nx; y = ny;
        }
        cout << "case " << t << ": " << abs(s) / 2 << endl;
    }
}
