// 1835712 2009-04-17 00:06:00 Accepted  2173 C++ 0 184 呆滞的慢板 

// 模拟题，检查窗口覆盖是否有不合法的情况。
// 通过各个窗口的位置，构有向图 G[i][j] 如果 i 块在 j 块下面 G[i][j] 为真。
// 然后如果 G[i][j] 无环则合法，否则不合法。 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void tidy(string& x) {
    int j = 0;
    for(int i = 0; i < x.size(); ++i)
        if(x[i] != ' ')
            x[j++] = x[i];
    x.erase(j);
}

int main() {
    string x;
    string P[4];
    bool G[9][9];
    vector<int> H[4][4];
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            H[i][j].push_back(i*3+j);
            H[i][j+1].push_back(i*3+j);
            H[i+1][j].push_back(i*3+j);
            H[i+1][j+1].push_back(i*3+j);
        }
    }
    while(getline(cin, x) && x == "START") {
        for(int i = 0; i < 4; ++i) {
            getline(cin, P[i]);
            tidy(P[i]);
        }
        getline(cin, x);
        memset(G, 0, sizeof(G));
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                for(int k = 0; k < H[i][j].size(); ++k)
                    if(H[i][j][k] != P[i][j] - '1')
                        G[P[i][j] - '1'][H[i][j][k]] = true;
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                for(int k = 0; k < 9; ++k)
                    if(G[j][i] && G[i][k])
                        G[j][k] = true;
        bool ans = false;
        for(int i = 0; i < 9; ++i)
            if(G[i][i] == true)
                ans = true;
        puts(
            ans ?
            "THESE WINDOWS ARE BROKEN" :
            "THESE WINDOWS ARE CLEAN"
        );
    }
}
