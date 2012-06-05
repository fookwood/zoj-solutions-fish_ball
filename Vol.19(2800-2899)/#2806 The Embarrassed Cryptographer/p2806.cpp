// 1741068 2009-01-12 01:03:10 Accepted  2806 C++ 3220 1468 呆滞的慢板 

// 密钥判定，枚举一个小数再用，大数模小数运算判别。 

#include <iostream>
#include <string>
using namespace std;

bool B[1000000] = {};
int P[78500], T = 0;

int main() {
    for(int i = 2; i < 1000; ++i) {
        if(B[i] == false)
        for(int j = i * i; j < 1000000; j += i)
            B[j] = true;
    }
    for(int i = 2; i < 1000000; ++i)
        if(B[i] == false)
            P[T++] = i;
    int L;
    string K;
    while(cin >> K >> L && L) {
        int ans = -1;
        for(int i = 0; P[i] < L && P[i]; ++i) {
            int rem = 0, base = 1;
            for(int j = K.size() - 1; j >= 0; --j) {
                rem = (rem + base * (K[j] - '0')) % P[i];
                base = (base * 10) % P[i];
            }
            if(rem) continue;
            ans = P[i];
            break;
        }
        if(ans == -1) puts("GOOD");
        else cout << "BAD " << ans << endl;
    }
}
