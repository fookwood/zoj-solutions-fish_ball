// 1869087 2009-05-14 17:41:30 Accepted  3151 C++ 0 184 呆滞的慢板 

// 模拟题，判断两个骰子是相同的或者镜像关系还是完全不同的。
// 第一步就是读入，将骰子类构造旋转的函数，
// 然后用 DFS 每次将骰子按指定方向旋转之后将数字填在顶面。
// 将骰子读入之后，通过旋转枚举所有面向上，
// 然后在作四次旋转跟另一个骰子比较。 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Dice {
    char p[6];
    
    void RotU() {
        int c = p[2];
        p[2] = p[1];
        p[1] = p[0];
        p[0] = p[3];
        p[3] = c;
    }
    
    void RotD() {
        int c = p[2];
        p[2] = p[3];
        p[3] = p[0];
        p[0] = p[1];
        p[1] = c;
    }
    
    void RotR() {
        int c = p[4];
        p[4] = p[1];
        p[1] = p[5];
        p[5] = p[3];
        p[3] = c;
    }
    
    void RotL() {
        int c = p[4];
        p[4] = p[3];
        p[3] = p[5];
        p[5] = p[1];
        p[1] = c;
    }
    
    void RotX() {
        int c = p[4];
        p[4] = p[2];
        p[2] = p[5];
        p[5] = p[0];
        p[0] = c;
    }
    
    void dfs(vector<string>& G, int x, int y) {
        p[1] = G[x][y];
        G[x][y] = ' ';
        if( x + 1 >= 0 && x + 1 < G.size() &&
            y >= 0 && y < G[x + 1].size() &&
            G[x + 1][y] != ' ') {
            RotD();
            dfs(G, x + 1, y);
            RotU();
        }
        if( x - 1 >= 0 && x - 1 < G.size() &&
            y >= 0 && y < G[x - 1].size() &&
            G[x - 1][y] != ' ') {
            RotU();
            dfs(G, x - 1, y);
            RotD();
        }
        if( y + 2 < G[x].size() &&
            G[x][y + 2] != ' ') {
            RotR();
            dfs(G, x, y + 2);
            RotL();
        }
        if( y - 2 >= 0 &&
            G[x][y - 2] != ' ') {
            RotL();
            dfs(G, x, y - 2);
            RotR();
        }
    }
    
    
    void get() {
        vector<string> G;
        string inp = "";
        while(inp == "") getline(cin, inp);
        while(inp != "") {
            G.push_back(inp);
            getline(cin, inp);
        }
        memset(p, '*', sizeof(p));
        for(int i = 0; i < G[0].size(); ++i)
            if(G[0][i] != ' ')
                dfs(G, 0, i);
    }
    
    void put() {
        for(int i = 0; i < 6; ++i)
            cout << p[i] << ' ';
        cout << endl;
    }
    
    bool equal(Dice rhs) {
        for(int i = 0; i < 6; ++i)
            if(p[i] != rhs.p[i])
                return false;
        return true;
    }
    
    bool equal2(Dice rhs) {
        bool ans = false;
        for(int i = 0; i < 4; ++i) {
            RotX();
            if(equal(rhs))
                ans = true;
        }
        return ans;
    }
    
    bool same(Dice rhs) {
        bool ans = false;
        if(equal2(rhs)) ans = true;
        RotD();
        if(equal2(rhs)) ans = true;
        RotD();
        if(equal2(rhs)) ans = true;
        RotD();
        if(equal2(rhs)) ans = true;
        RotD();
        RotL();
        if(equal2(rhs)) ans = true;
        RotL();
        RotL();
        if(equal2(rhs)) ans = true;
        RotL();
        return ans;
    }
    
    bool ref(Dice rhs) {
        return
            p[1] == rhs.p[3] &&
            p[3] == rhs.p[1] &&
            p[0] == rhs.p[0] &&
            p[2] == rhs.p[2] &&
            p[4] == rhs.p[4] &&
            p[5] == rhs.p[5];
    }
    
    bool ref2(Dice rhs) {
        bool ans = false;
        for(int i = 0; i < 4; ++i) {
            RotX();
            if(ref(rhs))
                ans = true;
        }
        return ans;
    }
    
    
    bool reflect(Dice rhs) {
        bool ans = false;
        if(ref2(rhs)) ans = true;
        RotD();
        if(ref2(rhs)) ans = true;
        RotD();
        if(ref2(rhs)) ans = true;
        RotD();
        if(ref2(rhs)) ans = true;
        RotD();
        RotL();
        if(ref2(rhs)) ans = true;
        RotL();
        RotL();
        if(ref2(rhs)) ans = true;
        RotL();
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        Dice a, b;
        a.get();
        b.get();
        if(a.same(b)) puts("Same");
        else if(a.reflect(b)) puts("Reflection");
        else puts("Different");
    }
}
