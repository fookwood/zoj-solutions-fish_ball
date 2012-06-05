// 1810949 2009-03-30 21:02:37 Accepted  1633 C++ 30 184 呆滞的慢板 

// 递归，因为前缀是一致的。可想而知，串的增长是指数级的，正如 Fibonacci 数一样。
// 因此我们可以用 log(N) 的时间知道给出的 N 是在第几次迭代中加入的。
// 也就是说，如果用 f(k) 来表示第 k 次迭代时总串的长度，
// 那么 f(0) = 4, f(1) = 3, f(2) = 7, f(k+1) = f(k) + f(k-1)。
// 如果求得 a = f(k-1) < N < f(k) = b，那么也可以得到递归式：
// f(N) = f(N - a)，然后锚例是 f(1~7) = "T.T^__^"。

#include <iostream>
using namespace std;

typedef long long i64;

char* str = "T.T^__^";

char gao(i64 n) {
    if(n <= 7) return str[n - 1];
    i64 a = 3, b = 7;
    while(b < n) {
        i64 c = a + b;
        a = b;
        b = c;
    }
    return gao(n - a);
}

int main() {
    i64 N;
    while(cin >> N) cout << gao(N) << endl;
}
