// 1835705 2009-04-16 23:54:18 Accepted  2187 C++ 0 184 呆滞的慢板 

// 图像缩放，超简单模拟题，几层 for 就可以搞定的事。 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    string G[9];
    int R, C;
    while(cin >> x && x == "START") {
        cin >> R >> C;
        for(int i = 0; i < R; ++i) cin >> G[i];
        cin >> x;
        for(int i = 1; i < R; ++i) {
            for(int j = 1; j < C; ++j) {
                putchar(
                    '0' +
                    (
                        (G[i][j]-'0') +
                        (G[i-1][j]-'0') +
                        (G[i][j-1]-'0') +
                        (G[i-1][j-1]-'0')
                    ) / 4
                );
            }
            puts("");
        }
    }
}
