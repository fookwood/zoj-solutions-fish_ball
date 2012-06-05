// 1888871 2009-06-01 01:39:15 Accepted  3163 C++ 150 184 呆滞的慢板 

// 苹果题，x 和 y 不用管输出 n-1，如果是 0 输出 0。 

#include <iostream>
using namespace std;

int main() {
    int N, x, y;
    while(cin >> N >> x >> y)
        cout << (N ? N - 1 : N) << endl;
}
