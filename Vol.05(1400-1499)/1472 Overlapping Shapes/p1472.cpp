#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long i64;

bool checkCC(i64 A[], i64 B[]) {
    i64 d = (A[0]-B[0])*(A[0]-B[0]) + (A[1]-B[1])*(A[1]-B[1]);
    i64 r = (A[2] + B[2]) * (A[2] + B[2]);
    i64 l = (A[2] - B[2]) * (A[2] - B[2]);
    return d <= r && d > l;
}

bool checkRR(i64 A[], i64 B[]) {
    int cnt = 0;
    if(A[0] >= B[0] && A[0] <= B[2]) {
        if(A[1] >= B[3] && A[1] <= B[1]) ++cnt;
        if(A[3] >= B[3] && A[3] <= B[1]) ++cnt;
        if(A[3] < B[3] && A[1] > B[1]) return true;
    }
    if(A[2] >= B[0] && A[2] <= B[2]) {
        if(A[1] >= B[3] && A[1] <= B[1]) ++cnt;
        if(A[3] >= B[3] && A[3] <= B[1]) ++cnt;
        if(A[3] < B[3] && A[1] > B[1]) return true;
    }
    if(A[0] > B[0] && A[0] < B[2])
        if(A[3] < B[3] && A[1] > B[1]) return true;
    if(A[2] > B[0] && A[2] < B[2])
        if(A[3] < B[3] && A[1] > B[1]) return true;
    return cnt > 0 && cnt < 4;
}

bool inside(i64 x, i64 y, i64 A[]) {
    i64 d = (x-A[0])*(x-A[0]) + (y-A[1])*(y-A[1]);
    return d <= A[2] * A[2];
} 

bool checkRC(i64 A[], i64 B[]) {
    // 矩形顶点在圆内
    int cnt = 0;
    if(inside(A[0], A[1], B)) ++cnt;
    if(inside(A[0], A[3], B)) ++cnt;
    if(inside(A[2], A[1], B)) ++cnt;
    if(inside(A[2], A[3], B)) ++cnt;
    if(cnt == 4) return false;
    if(cnt > 0) return true;
    // 圆心在矩形内 
    if(B[0] >= A[0] && B[0] <= A[2] && B[1] >= A[3] && B[1] <= A[1]) {
        if(abs(B[1]-A[1]) < B[2]) return true;
        if(abs(B[1]-A[3]) < B[2]) return true;
        if(abs(B[0]-A[0]) < B[2]) return true;
        if(abs(B[0]-A[2]) < B[2]) return true;
        return false;
    }
    // 矩形边割圆形
    if(B[0] >= A[0] && B[0] <= A[2]) {
        if(abs(B[1]-A[1]) <= B[2]) return true;
        if(abs(B[1]-A[3]) <= B[2]) return true;
    } 
    if(B[1] >= A[3] && B[1] <= A[1]) {
        if(abs(B[0]-A[0]) <= B[2]) return true;
        if(abs(B[0]-A[2]) <= B[2]) return true;
    }
    // 否则不相交 
    return false;
}

int main() {
    string s1, s2;
    i64 A[4], B[4];
    i64 N;
    for(cin >> N; N--;) {

        cin >> s1;
        if(s1[0] == 'c') cin >> A[2] >> A[0] >> A[1];
        if(s1[0] == 'r') cin >> A[0] >> A[1] >> A[2] >> A[3];

        cin >> s2;
        if(s2[0] == 'c') cin >> B[2] >> B[0] >> B[1];
        if(s2[0] == 'r') cin >> B[0] >> B[1] >> B[2] >> B[3];

        if(s1[0] == 'c' && s2[0] == 'c')
            puts(checkCC(A, B) ? "yes" : "no");

        else if(s1[0] == 'r' && s2[0] == 'r')
            puts(checkRR(A, B) || checkRR(B, A) ? "yes" : "no");

        else if(s1[0] == 'r' && s2[0] == 'c')
            puts(checkRC(A, B) ? "yes" : "no");

        else if(s1[0] == 'c' && s2[0] == 'r')
            puts(checkRC(B, A) ? "yes" : "no");
    }
}
