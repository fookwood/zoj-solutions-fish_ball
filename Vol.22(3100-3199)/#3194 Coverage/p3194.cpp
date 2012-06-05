// 1863791 2009-05-10 23:46:55 Accepted  3194 C++ 90 184 呆滞的慢板 

// 给出一组坐标点 (所有坐标值为正)，X 坐标固定，Y 坐标可以随意调动。
// 问将此系列坐标点用折线连接后与 x 轴围成面积最大是多少。 
// 这题属于贪心分配，首先推导一个面积公式的变形：
// 假设 X[0..N-1], Y[0..N-1] 是两组实际分配到的坐标点，并且 X 升序。
// 那么利用梯形面积公式，求得的总的面积为 
// S = (Y[0] + Y[1]) * (X[1] - X[0]) / 2 + ... +
//     (Y[i] + Y[i+1]) * (X[i+1] - X[i]) / 2 + ... +
//     (Y[N-2] + Y[N-1]) * (X[N-1] - X[N-2]) / 2
// 稍加变形，可以得到
// S = Y[0] * (X[1] - X[0]) / 2 +
//     Y[1] * (X[2] - X[0]) / 2 + ... +
//     Y[i] * (X[i+1] - X[i-1]) / 2 + ... +
//     Y[N-2] * (X[N-1] - X[N-3]) / 2 +
//     Y[N-1] * (X[N-1] - X[N-2]) / 2
// 现在可以看到，对于确定的 i 每个 Y[i] 面的系数总是一定的，
// 因为 X[0..N-1] 总是升序的。
// 然后我们可以随便分配 Y[i] 的编序，使得总面积最大，
// 那么我们要做的仅仅是将所有的系数 P[0..N-1] 存放起来，
// 然后排序，然后按序将较大的 Y[i] 分配给较大的系数 P[i]
// 最后得到的面积就是最优的。 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, N;
    for(cin >> T; T--;) {
        cin >> N;
        vector<int> X(N), Y(N);
        for(int i = 0; i < N; ++i)
            cin >> X[i] >> Y[i];
        sort(X.begin(), X.end());
        vector<int> P(N);
        for(int i = 0; i < N; ++i) {
            if(i == 0) P[i] = X[1] - X[0];
            else if(i == N - 1) P[i] = X[N-1] - X[N-2];
            else P[i] = X[i+1] - X[i-1];
        }
        sort(P.begin(), P.end());
        sort(Y.begin(), Y.end());
        double ans = 0;
        for(int i = 0; i < N; ++i)
            ans += P[i] * Y[i];
        printf("%.1lf\n", ans / 2);
    }
}
