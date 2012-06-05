// 1994193 2009-09-14 16:29:13 Accepted  3240 C++ 500 184 呆滞的慢板 

// 模拟俄罗斯方块，直接暴搜，加一点剪枝条件即可。 

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Block {
    int x[4], y[4];
    int col, row;
    Block(char vs[4][5]) {
        int width = 0;
        row = 0;
        for(int i = 0, k = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                if(vs[i][j] == ' ') continue;
                width = max(width, j);
                row = max(row, i + 1);
                x[k] = i;
                y[k] = j;
                k++;
            }
        }
        col = 5 - width;
    }
};

map<char, vector<Block> > BLK;

char I1[][5] = {
    "****",
    "    ",
    "    ",
    "    "
};
char I2[][5] = {
    "*   ",
    "*   ",
    "*   ",
    "*   "
};
char O[][5] = {
    "**  ",
    "**  ",
    "    ",
    "    "
};
char S1[][5] = {
    "**  ",
    " ** ",
    "    ",
    "    "
};
char S2[][5] = {
    " *  ",
    "**  ",
    "*   ",
    "    "
};
char Z1[][5] = {
    " ** ",
    "**  ",
    "    ",
    "    "
};
char Z2[][5] = {
    "*   ",
    "**  ",
    " *  ",
    "    "
};
char L1[][5] = {
    " *  ",
    " *  ",
    "**  ",
    "    "
};
char L2[][5] = {
    "*** ",
    "  * ",
    "    ",
    "    "
};
char L3[][5] = {
    "**  ",
    "*   ",
    "*   ",
    "    "
};
char L4[][5] = {
    "*   ",
    "*** ",
    "    ",
    "    "
};
char J1[][5] = {
    "*   ",
    "*   ",
    "**  ",
    "    "
};
char J2[][5] = {
    "  * ",
    "*** ",
    "    ",
    "    "
};
char J3[][5] = {
    "**  ",
    " *  ",
    " *  ",
    "    "
};
char J4[][5] = {
    "*** ",
    "*   ",
    "    ",
    "    "
};
char T1[][5] = {
    "*   ",
    "**  ",
    "*   ",
    "    "
};
char T2[][5] = {
    " *  ",
    "*** ",
    "    ",
    "    "
};
char T3[][5] = {
    " *  ",
    "**  ",
    " *  ",
    "    "
};
char T4[][5] = {
    "*** ",
    " *  ",
    "    ",
    "    "
};

string s;

int ht;

int Solve(int k, vector<string> G) {
    if(G.size() > ht + 4) return 0x7FFFFFFF;
    if(k == s.size()) {
        int ans = 0;
        for(int j = 0, i; j < 5; ++j) {
            for(i = G.size() - 1; i >= 0; --i) {
                if(G[i][j] != ' ')
                    break;
            }
            ans += (i + 1) * (i + 1);
        }
        if(ht > G.size()) ht = G.size();
        return ans;
    }
    else {
        int ans = 0x7FFFFFFF;
        vector<Block> &VB = BLK[s[k]];
        for(int i = 0; i < VB.size(); ++i) {
            Block &B = VB[i];
            for(int j = 0; j < B.col; ++j) {
                vector<string> H(G);
                int pos = H.size() - 1;
                for(; pos >= 0; --pos) {
                    bool yes = true;
                    for(int r = 0; r < 4; ++r) {
                        int x = pos + B.x[r];
                        int y = j + B.y[r];
                        if(x < H.size() && H[x][y] != ' ') {
                            yes = false;
                            break;
                        }
                    }
                    if(!yes) break;
                }
                pos += 1;
                while(H.size() < pos + B.row) {
                    H.push_back("     ");
                }
                for(int r = 0; r < 4; ++r) {
                    int x = pos + B.x[r];
                    int y = j + B.y[r];
                    H[x][y] = '0' + k;
                }
                int hsz = 0;
                for(int p = 0; p < H.size(); ++p) {
                    if(H[p].find_first_of(' ') != string::npos) {
                        H[hsz++] = H[p];
                    }
                }
                H.resize(hsz);
                ans = min(ans, Solve(k+1, H));
            }
        }
        return ans;
    }
}

int main() {
    BLK['I'].push_back(Block(I1));
    BLK['I'].push_back(Block(I2));
    BLK['O'].push_back(Block(O));
    BLK['Z'].push_back(Block(Z1));
    BLK['Z'].push_back(Block(Z2));
    BLK['S'].push_back(Block(S1));
    BLK['S'].push_back(Block(S2));
    BLK['L'].push_back(Block(L1));
    BLK['L'].push_back(Block(L2));
    BLK['L'].push_back(Block(L3));
    BLK['L'].push_back(Block(L4));
    BLK['J'].push_back(Block(J1));
    BLK['J'].push_back(Block(J2));
    BLK['J'].push_back(Block(J3));
    BLK['J'].push_back(Block(J4));
    BLK['T'].push_back(Block(T1));
    BLK['T'].push_back(Block(T2));
    BLK['T'].push_back(Block(T3));
    BLK['T'].push_back(Block(T4));
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> s;
        ht = 0x7FFFFFFF;
        printf("Case %d: %d\n", t, Solve(0, vector<string> (0)));
    }
}
