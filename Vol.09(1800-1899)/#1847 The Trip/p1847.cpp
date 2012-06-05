// 1664783 2008-10-12 22:12:26 Accepted  1847 C++ 10 192 呆滞的慢板 

// 应该属于简单题，但涉及一个取整或许有所麻烦：
// 精确解应该是求出平均值，再求偏差绝对值和除 2。
// 这里由于精确到分，求出平均值 mean，按分求出 ceil 和 floor 的值。
// 然后对于每个人，若钱 < mean，求与 floor 偏差绝对值加到总和中，否则与 ceil 求。
// 另外，记录偏差(不取绝对值总和)，如果最后总偏差不为 0，要将总偏差绝对值加到总和中。
// 最后输出总和一半即可。 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double A[1000], mean, sum, up, down, diff;
int N;

int main() {
    while(cin >> N && N) {
        mean = 0;
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
            mean += A[i];
        }
        mean /= N;
        up = ceil(mean * 100) / 100;
        down = floor(mean * 100) / 100;
        sum = diff = 0;
        for(int i = 0; i < N; ++i) {
            if(fabs(up - A[i]) < fabs(down - A[i])) {
                sum += fabs(up - A[i]);
                diff += up - A[i];
            }
            else {
                sum += fabs(down - A[i]);
                diff += down - A[i];
            }
        }
        if(diff > 1e-5 || diff < -1e-5)
            sum += fabs(diff);
        printf("$%.2lf\n", sum / 2);
    }
}
