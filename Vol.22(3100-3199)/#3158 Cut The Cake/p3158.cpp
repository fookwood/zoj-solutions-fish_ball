// 1763990 2009-02-15 23:41:25 Accepted  3158 C++ 0 184 呆滞的慢板 

// 切蛋糕，dfs 枚举出所有状态，注意，每一行两边都必须有蛋糕(不能一边没有) 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class CutTheCake {
    
    int M, N, S, MIN, BOUND;

    int C[7][7];
    
    void dfs(int row, int sum) {
        
        if(row == M) {
            if(MIN > abs(S - sum - sum))
                MIN = abs(S - sum - sum);
            return;
        }

        for(int col = 0; col + 1 < N; ++col)
            dfs(row + 1, sum += C[row][col]);
        
    }
    
public:

    bool input() {
        S = 0;
        if(!(cin >> M >> N)) return false;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                cin >> C[i][j];
                S += C[i][j];
            }
        }
        cin >> BOUND;
        
        MIN = INT_MAX;
        
        return true;
    }
    
    void solve() {
        dfs(0, 0);
    }
    
    void display() {
        if(MIN < BOUND) cout << MIN << endl;
        else puts("You'd better buy another one!");
    }

};

int main() {
    
    CutTheCake obj;
    
    while(obj.input()) {
        obj.solve();
        obj.display();
    }
}
