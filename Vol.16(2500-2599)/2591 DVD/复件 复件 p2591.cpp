#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, N;

vector<string> F[5][136];
int cnt[5][136];

int DP[5][6][136];
int pre[5][6][136];

int pack(int x, int y, int z) {
    return (x * 6 + y) * 136 + z;
}

void output(int x, int y, int z) {
    if(pre[x][y][z] == -1) return;
    int i = pre[x][y][z] % 136;
    int j = pre[x][y][z] / 136 % 6;
    int k = pre[x][y][z] / 136 / 6;
    output(k, j, i);
    for(int v = 0; v < F[x][z].size(); ++v)
        cout << F[x][z][v] << endl;
}

int main() {
    for(cin >> T; T--;) {
        for(int i = 0; i < 5; ++i)
            for(int j = 0; j < 136; ++j)
                F[i][j].clear();
        memset(cnt, 0, sizeof(cnt));
        memset(DP, -1, sizeof(DP));
        memset(pre, -1, sizeof(pre));
        for(cin >> N; N--;) {
            char c;
            cin >> c;
            string s(1, c);
            while((c = getchar()) != '\"')
                s += c;
            s += c;
            int year, region;
            cin >> year >> region;
            F[region-1][year-1870+1].push_back(s);
            cnt[region-1][year-1870+1] += 1;
        }
        DP[0][5][0] = 0;
        DP[1][5][0] = 0;
        DP[2][5][0] = 0;
        DP[3][5][0] = 0;
        DP[4][5][0] = 0;

        for(int i = 0; i < 136; ++i) {
            for(int k = 5; k >= 0; --k) {
                for(int j = 0; j < 5; ++j) {
                    if(DP[j][k][i] == -1) continue;
                    if(i + 1 < 136 &&
                        DP[j][k][i+1] < DP[j][k][i] + cnt[j][i+1]) {
                        DP[j][k][i+1] = DP[j][k][i] + cnt[j][i+1];
                        pre[j][k][i+1] = pack(j, k, i);
                    }
                    if(k > 0)
                    for(int p = 0; p < 5; ++p) {
                        if(p == j) continue;
                        if(cnt[p][i] == 0) continue;
                        if(DP[p][k-1][i] < DP[j][k][i] + cnt[p][i]) {
                            DP[p][k-1][i] = DP[j][k][i] + cnt[p][i];
                            pre[p][k-1][i] = pack(j, k, i);
                        }
                    }
                }
            }
        }
        int mx = -1, ii = 0, jj = 0, kk = 0;
        for(int i = 0; i < 136; ++i) {
            for(int j = 0; j < 5; ++j) {
                for(int k = 0; k < 6; ++k) {
                    if(DP[j][k][i] > mx) {
                        mx = DP[j][k][i];
                        ii = i;
                        jj = j;
                        kk = k;
                    }
                }
            }
        }
        cout << DP[jj][kk][ii] << endl;
        output(jj, kk, ii);
        if(T) puts("");
    } 
}
