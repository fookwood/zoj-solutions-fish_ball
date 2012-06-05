// 1842106 2009-04-23 16:23:24 Accepted  3106 C++ 0 184 呆滞的慢板 

// 成绩预测，注意输入输出，读明题意之后蛮力即可，没什么难度，
// 新预测过的成绩并不需要追加到历史档案中。 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int DATA[51][5], N = 0;
    string s;
    while(getline(cin, s) && s != "") {
        istringstream is(s);
        for(int i = 0; i < 5; ++i) is >> DATA[N][i];
        N++;
    }
    int k;
    while(getline(cin, s)) {
        if(s == "") continue;
        if(s.find(' ') == string::npos) k = atoi(s.c_str());
        else {
            istringstream is(s);
            for(int i = 0; i < 4; ++i) is >> DATA[N][i];
            vector<pair<int, int> > v;
            for(int i = 0; i < N; ++i) {
                int val = 0;
                for(int j = 1; j < 4; ++j)
                    val += abs(DATA[N][j] - DATA[i][j]);
                v.push_back(make_pair(val, i));
            }
            sort(v.begin(), v.end());
            int ans = 0;
            for(int i = 0; i < k; ++i) {
                if(DATA[v[i].second][4]) ans += 1;
                else ans -= 1;
            }
            cout << DATA[N][0] << ' ';
            if(ans > 0) puts("1");
            else puts("0");
        }
    }
}
