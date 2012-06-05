// 1664138 2008-10-11 22:11:50 Accepted  1717 C++ 10 232 呆滞的慢板 

// DP，每个格子存放一个最优字符串，确定一个字符串"更优"的比较函数
// 即可不断更新到当前字符位置的最长字符串。 

#include <iostream>
#include <string>
using namespace std;

char C[100][100];
string S[100][100];

int W, H;

bool cmp(const string& lhs, const string& rhs) {
    return lhs.size() > rhs.size() ||
        lhs.size() == rhs.size() && lhs > rhs;
}

int main() {
    while(cin >> W >> H && W) {
        string mx = "";
        for(int i = 0; i < H; ++i) {
            for(int j = 0; j < W; ++j) {
                cin >> C[i][j];
                S[i][j].erase();
                if(!isdigit(C[i][j])) continue;
                if(i > 0 && cmp(S[i-1][j], S[i][j]))
                    S[i][j] = S[i-1][j];
                if(j > 0 && cmp(S[i][j-1], S[i][j]))
                    S[i][j] = S[i][j-1];
                if(S[i][j] == "" && C[i][j] == '0') continue;
                S[i][j] += C[i][j];
                if(cmp(S[i][j], mx)) mx = S[i][j];
            }
        }
        cout << mx << endl;
    }
}
