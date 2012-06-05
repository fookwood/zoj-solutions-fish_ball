// 1740887 2009-01-11 13:17:01 Accepted  3109 C++ 0 184 ´ôÖÍµÄÂı°å 

// ½âÃÜ£¬ÂİĞıÖØÅÅ¡£ 

#include <iostream>
#include <string>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    int M, N;
    string s;
    char mat[20][20];
    while(cin >> M >> N && M) {
        cin >> s;
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                mat[i][j] = s[i * N + j] - 7;
        int x = 0, y = 0, d = 0;
        string ans = "";
        for(int i = 0; i < s.size(); ++i) {
            ans += mat[x][y];
            mat[x][y] = 0;
            if(x + dx[d] < 0 || x + dx[d] >= M ||
                y + dy[d] < 0 || y + dy[d] >= N ||
                mat[x + dx[d]][y + dy[d]] == 0) d = (d + 1) % 4;
            x += dx[d];
            y += dy[d];
        }
        cout << ans << endl;
    }
}
