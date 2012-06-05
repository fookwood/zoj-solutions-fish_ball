// 2151611 2010-04-10 19:37:13 Accepted  3313 C++ 0 184 呆滞的慢板 

// 输出每天时针与分针角度 < 给定角度的秒数。
// 用相对运动的角度分析，由于是循环对称的，因此夹角为某一度的时间
// 都是均等的，因此，直接 x/180*86400 即乘以 480 可得到结果。 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    for(cin >> N; N--;) {
        int K;
        cin >> K;
        cout << K * 480 << ".00" << endl;
    }
}
