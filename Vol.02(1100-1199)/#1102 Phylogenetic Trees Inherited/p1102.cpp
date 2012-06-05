// 2147408 2010-04-08 15:37:46 Accepted  1102 C++ 1000 712 呆滞的慢板 

// 一个完全二叉字串树，节点是等长L(L<=1000)字串，边权为字符串对应位置不同的字符数。
// 只给出数的所有叶子，构造一个树使得边权和最小并输出树根和最小边权和。 
// 归并法，具有最优子结构的贪心方法。可以看出这个问题具有字符独立性，也就是
// 可以对字符串每个位置的字符单独做一次操作。
// 做法如下，对字符串的每个字符位置做一次：用一个队列，存放一个树节点，
// 节点保存如果这个节点取某个字符，那么这个节点为根的子树边权和的最小值。
// 维持这个最优子结构，每次从队列中取出两个节点，归并后放回队列，直到队列只有一个节点。
// 归并方法如下：求出要归并的两个节点(兄弟)取所有字母时的最小值，然后枚举可以使用的
// 20个字母，如果，分别对两个节点，该字母位置取值恰好等于最小值，那么对这个字母，
// 新的值取这个最小值，否则，取所有字母最小值加1作为新的最小值。
// 复杂度为 O(L*N*20)

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string charset = "ARNDCQEGHILKMFPSTWYV";

pair<char, int> parse(string s) {
    queue<vector<int> > Q;
    for(int i = 0; i < s.size(); ++i) {
        vector<int> V(20);
        for(int j = 0; j < 20; ++j) {
            V[j] = charset[j] != s[i];
        }
        Q.push(V);
    }
    while(Q.size() > 1) {
        vector<int> A = Q.front(); Q.pop();
        vector<int> B = Q.front(); Q.pop();
        int mina = INT_MAX, minb = INT_MAX;
        for(int i = 0; i < 20; ++i) {
            mina = min(A[i], mina);
            minb = min(B[i], minb);
        }
        for(int i = 0; i < 20; ++i) {
            if(A[i] != mina) A[i] = mina + 1;
            A[i] += B[i] == minb ? minb : minb + 1;
        }
        Q.push(A);
    }
    vector<int> V = Q.front(); Q.pop();
    int minv = INT_MAX, minp = -1;
    for(int i = 0; i < 20; ++i) {
        if(minv > V[i]) {
            minv = V[i];
            minp = i;
        }
    }
    return make_pair(charset[minp], minv);
}

int main() {
    int N, L;
    while(cin >> N >> L && N) {
        vector<string> S(N);
        for(int i = 0; i < N; ++i) {
            cin >> S[i];
        }
        string ans = "";
        int val = 0;
        for(int i = 0; i < L; ++i) {
            string tmp = "";
            for(int j = 0; j < N; ++j) {
                tmp += S[j][i];
            }
            pair<char, int> ret = parse(tmp);
            ans += ret.first;
            val += ret.second;
        }
        cout << ans << " " << val << endl;
    }
}
