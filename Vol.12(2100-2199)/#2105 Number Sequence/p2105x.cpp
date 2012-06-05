// 用矩阵连乘解决

#include <iostream>
using namespace std;

struct Mat{
    int a11, a12, a21, a22;
    Mat(int a11 = 0, int a12 = 0,
        int a21 = 0, int a22 = 0) :
        a11(a11), a12(a12),
        a21(a21), a22(a22) {}
};

const Mat operator* (const Mat& lhs, const Mat& rhs) {
    return Mat(
        (lhs.a11*rhs.a11 + lhs.a12*rhs.a21) % 7,
        (lhs.a11*rhs.a12 + lhs.a12*rhs.a22) % 7,
        (lhs.a21*rhs.a11 + lhs.a22*rhs.a21) % 7,
        (lhs.a21*rhs.a12 + lhs.a22*rhs.a22) % 7
    );
}

const Mat power(const Mat& m, int n) {
    if(n == 1) return m;
    Mat ans = power(m, n/2);
    ans = ans * ans;
    if(n & 1) ans = ans * m;
    return ans;
}

int main() {
    int A, B, N;
    while(cin >> A >> B >> N && (A||B||N)) {
        if(N < 3) puts("1");
        else {
            Mat m = power(Mat(A%7, B%7, 1, 0), N-2);
            cout << (m.a11 + m.a12) % 7 << endl;
        }
    }
}
