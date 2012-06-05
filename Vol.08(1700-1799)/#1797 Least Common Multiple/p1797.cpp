// 简单，最小公倍数具有传递性
// 2822108 2008-04-04 01:52:13 Accepted 1797 C++ 00:00.00 836K 呆滞的慢板  

#include <iostream>
using namespace std;

int main() {
    int     T,  N;
    cin >> T;
    while( T-- ) {
        cin >> N;
        int     LCM = 1,  m,  n,  r,  temp;
        while( N-- ) {
            m = LCM;
            cin >> n;
            temp = n;
            while( n ) {
                r = m % n;
                m = n;
                n = r;
            }
            LCM /= m;
            LCM *= temp;
        }
        cout << LCM << endl;
    }
}
