#include <iostream>
#include <vector>
using namespace std;

int P[26][3] = {
    {33, 1860, 1737},
    {49, 2605, 2638},
    {34, 1833, 1839},
    {42, 2252, 2326},
    {44, 2314, 2394},
    {36, 1361, 2527},
    {38, 2159, 1945},
    {37, 1998, 1998},
    {22, 1111, 1111},
    {27, 1331, 1477},
    {36, 1941, 1911},
    {24, 1704, 864},
    {42, 2110, 2468},
    {42, 2362, 2216},
    {40, 2180, 2180},
    {38, 1626, 2516},
    {48, 2862, 2370},
    {43, 2131, 2556},
    {43, 2367, 2320},
    {34, 1019, 2619},
    {38, 2455, 1687},
    {40, 1924, 2436},
    {40, 2404, 1956},
    {40, 2140, 2140},
    {28, 1114, 1882},
    {31, 1687, 1599}
};

int m, n;
char G[300][301];

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};

vector<pair<int, int> > RT;
int x1, y1;

void calc(int x, int y) {
    if(x1 > x) x1 = x; 
    if(y1 > y) y1 = y; 
    RT.push_back(make_pair(x, y));
    G[x][y] = '1';
    for(int d = 0; d < 8; ++d) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if(xx >= 0 && xx < m && yy >= 0 && yy < n && G[xx][yy] == 'M') {
            calc(xx, yy);
        }
    }
}

int main() {
    while(cin >> m >> n) {
        bool B[26] = {};
        for(int i = 0; i < m; ++i)
            cin >> G[i];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(G[i][j] == 'M') {
                    RT.clear();
                    x1 = y1 = INT_MAX;
                    calc(i, j);
                    int v = 0;
                    for(int k = 0; k < RT.size(); ++k) {
                        v += (RT[k].first - x1) * 16 + (RT[k].second - y1);
                    }
                    for(int p = 0; p < 26; ++p) {
                        if(P[p][0] == RT.size() && (P[p][1] == v || P[p][2] == v)) {
                            B[p] = true;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 26; ++i) {
            if(B[i]) {
                putchar('A' + i);
            }
        }
        puts("");
    }
}
