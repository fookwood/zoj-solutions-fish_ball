// 1930181 2009-07-18 10:43:54 Accepted  1427 C++ 0 184 呆滞的慢板 

// 树状 DP，直接 dfs 这棵树，后序到达某个节点时返回填满这个数需要多少棵石子。
// 对于没有儿子(叶子)节点，返回值是 1。
// 否则，依次 dfs 其所有叶子节点，得到结果数组 vec，降序排列， 
// 然后按照第一个 i = 0，往后遍历这个 vec，用 i + vec[i] 去更新结果的最大值， 
// 然后返回结果即可。 

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int T, N;

vector<vector<int> > G;

int dfs(int v) {
    if(G[v].size() == 0) return 1;
    vector<int> vec;
    for(int i = 0; i < G[v].size(); ++i)
        vec.push_back(dfs(G[v][i]));
    sort(vec.begin(), vec.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < vec.size(); ++i)
        ans = max(i + vec[i], ans);
    return ans;
}

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        G.assign(N, vector<int>());
        for(int i = 0; i < N; ++i) {
            int K, v;
            for(cin >> v >> K; K--;) {
                int w;
                cin >> w;
                G[v-1].push_back(w-1);
            }
        }
        cout << dfs(0) << endl;
    }
}
