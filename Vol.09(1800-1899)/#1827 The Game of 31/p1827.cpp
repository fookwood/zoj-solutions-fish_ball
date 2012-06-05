// 1763546 2009-02-15 11:45:43 Accepted  1827 C++ 0 244 呆滞的慢板 

// 博弈，状态不大，用记忆化搜索解决的，前推 DP 的话次序和初始状态稍为麻烦。

#include <iostream>
#include <string>
using namespace std;

void read(int code, int* C) {
    for(int i = 0; i < 6; ++i) {
        C[i] = code % 5;
        code /= 5;
    }
}

int write(int* C) {
    int code = 0;
    for(int i = 5; i >= 0; --i) {
        code *= 5;
        code += C[i];
    }
    return code;
}

int count(int pos) {
    int C[6];
    read(pos, C);
    int ans = 0;
    for(int i = 0; i < 6; ++i)
        ans += (i + 1) * (4 - C[i]);
    return ans;
}

int DP[15625];

int eval(int pos) {
    if(DP[pos] != -1) return DP[pos];
    int A[6];
    read(pos, A);
    for(int i = 0; i < 6; ++i) {
        if(A[i] > 0) {
            A[i] -= 1;
            int newPos = write(A);
            if(count(newPos) <= 31 && eval(newPos) == 0) return DP[pos] = 1; // 1 indicates a win position
            A[i] += 1;
        }
    }
    return DP[pos] = 0; // 0 indicates a lose position
}

int main() {

    int A[6], B[6];
    memset(DP, -1, sizeof(DP)); // -1 indicates a non-determined status

    string s;
    while(cin >> s) {
        for(int i = 0; i < 6; ++i) B[i] = 4;
        for(int i = 0; i < s.size(); ++i)
            B[s[i] - '1'] -= 1;
        char c = (eval(write(B)) ^ (s.size() % 2)) ? 'A' : 'B';
        cout << s << ' ' << c << endl;
    }

}
