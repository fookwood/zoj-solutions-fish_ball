// 1649990 2008-09-26 22:01:26 Accepted  1695 C++ 10 2048 fish_ball 

// 先构图，按照 同色边、反色边 记录所有边，然后二涂色
// 每涂色一个分量，用两个 vector 记录该分量的两个对立颜色的顶点集合
// 最后，DP 确定各分量的分配 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum {GRAY = 0, WHITE = 1, BLACK = 2};

vector<int> same[600], diff[600];

int color[600];

int n, p1, p2;

vector<vector<int> > suitB, suitW;

int     DP[601][601];
bool    CP[601][601];

bool final() {
    
    memset(DP, -1, sizeof(DP));
    memset(CP, 0, sizeof(CP));
        
    DP[0][0] = 0;
    
    int N = suitB.size();
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j <= p1; ++j) {
            if(DP[i][j] != -1) {
                if(j + suitB[i].size() <= p1) {
                    if(DP[i+1][j+suitB[i].size()] != -1 || CP[i][j])
                        CP[i+1][j+suitB[i].size()] = true;
                    DP[i+1][j+suitB[i].size()] = 1;
                }
                if(j + suitW[i].size() <= p1) {
                    if(DP[i+1][j+suitW[i].size()] != -1 || CP[i][j])
                        CP[i+1][j+suitW[i].size()] = true;
                    DP[i+1][j+suitW[i].size()] = 2;
                }
            }
        }
    }
    if(DP[suitB.size()][p1] == -1 || CP[suitB.size()][p1])
        return  false;

    vector<int> ans(0);

    for(int m = suitB.size() - 1, n = p1; m >= 0; --m) {
        if( DP[m+1][n] == 1 ) {
            for(int i = 0; i < suitB[m].size(); ++i)
                ans.push_back(suitB[m][i]);
            n -= suitB[m].size();
        }
        else {
            for(int i = 0; i < suitW[m].size(); ++i)
                ans.push_back(suitW[m][i]);
            n -= suitW[m].size();
        }
    }
    
    sort( ans.begin(), ans.end() );
    
    for( int i = 0; i < ans.size(); ++i )
        cout << ans[i] << endl;
    
    puts( "end" );
    
    return true;
    
}

bool dfs(int v, int clr) {
    color[v] = clr;
    if(clr == WHITE) suitW.back().push_back(v+1);
    if(clr == BLACK) suitB.back().push_back(v+1);
    for(int i = 0, w; i < same[v].size(); ++i) {
        w = same[v][i];
        if(color[w] == 3-clr ||
            color[w] == GRAY &&
            !dfs(w, clr))
            return false;
    }
    for(int i = 0, w; i < diff[v].size(); ++i) {
        w = diff[v][i];
        if(color[w] == clr ||
            color[w] == GRAY &&
            !dfs(w, 3-clr))
            return false;
    }
    return true;
}

int main() {
    
    while(cin >> n >> p1 >> p2 && (n || p1 || p2)) {
        
        for(int i = p1 + p2 - 1; i >= 0; --i) {
            same[i].clear();
            diff[i].clear();
        }
        for(int i = 0; i < n; ++i) {
            int x, y;
            char s[4];
            cin >> x >> y >> s;
            if(*s == 'y') {
                same[x-1].push_back(y-1);
                same[y-1].push_back(x-1);
            }
            else {
                diff[x-1].push_back(y-1);
                diff[y-1].push_back(x-1);
            }
        }
        
        memset(color, GRAY, sizeof(color));
        suitB.clear();
        suitW.clear();
        
        bool success = true;
        for(int i = p1 + p2 - 1; i >= 0; --i) {
            if(color[i] == GRAY) {
                suitB.push_back(vector<int>());
                suitW.push_back(vector<int>());
                if(!dfs(i, WHITE)) {
                    success = false;
                    break;
                }
            }
        }
        
        if(!success || !final())  puts("no");

    }
    
}
