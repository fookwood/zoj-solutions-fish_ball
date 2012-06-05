// 2083142 2010-01-30 10:54:41 Accepted  2502 C++ 240 184 呆滞的慢板 

// 状态序列转移，转化成逻辑矩阵连乘即可。 

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int N, t;

int x[100] = {};

struct Mat {
    int A[100][100];
    Mat() { memset(A, 0, sizeof(A)); }
};

Mat mult(const Mat& lhs
        , const Mat& rhs) {
    Mat ans;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                ans.A[i][j] ^= (lhs.A[i][k] & rhs.A[k][j]);
            }
        }
    }
    return ans;
}

Mat powM(const Mat& A
        , int deg) {
    if(deg == 1) return A;
    Mat m1 = powM(A, deg / 2);
    Mat m2 = mult(m1, m1);
    if(deg % 2) return mult(m2, A);
    else return m2;
}

int main() {
    int T;
    for(cin >> T; T--;) {
        cin >> N >> t;
        map<string, int> mp;
        vector<vector<string> > G(N, vector<string>());
        for(int i = 0; i < N; ++i) {
            string s;
            int val, k;
            cin >> s >> val >> k;
            x[i] = val % 2;
            mp[s] = i;
            while(k--) {
                cin >> s;
                G[i].push_back(s);
            }
        }
        Mat m;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < G[i].size(); ++j)
                m.A[i][mp[G[i][j]]] = 1;
            m.A[i][i] ^= 1;
        }
        Mat mout = powM(m, t - 1);
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            int xx = 0;
            for(int j = 0; j < N; ++j) {
                xx ^= (x[j] & mout.A[j][i]);
            }
            ans += xx;
        }
        cout << ans << endl;
    }
}
