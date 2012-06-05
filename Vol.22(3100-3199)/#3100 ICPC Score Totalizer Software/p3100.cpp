// 1841987 2009-04-23 14:13:32 Accepted  3100 C++ 0 184 呆滞的慢板 

// 超水肉题，求和剔除最大最小值求平均。 

#include <iostream>
using namespace std;

int main() {
    for(int N; cin >> N && N;) {
        int sum = 0;
        int mx = INT_MIN, mn= INT_MAX;
        for(int i = 0, x; i < N; ++i) {
            cin >> x;
            sum += x;
            if(x > mx) mx = x;
            if(x < mn) mn = x;
        }
        sum -= mx;
        sum -= mn;
        sum /= (N - 2);
        cout << sum << endl;
    }
}
