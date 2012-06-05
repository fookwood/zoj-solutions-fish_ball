// 1653274 2008-10-01 20:35:22 Accepted  1530 C++ 0 268 呆滞的慢板 

// dfs，dfs 到某一个数的时候，判断 mod k 的余数是否为 0 。
// 加分支限界法保证算法正确。 

#include <vector>
#include <iostream>
using namespace std;

int k;
int v[200];
vector<char> s;

bool dfs(int r, int l) {
    if(r == 0) return true;
    if(s.size() >= 100) return false;
    if(v[10*r%k] > l) {
        v[10*r%k] = l;
        s.push_back('0');
        if(dfs(10*r%k, l+1))
            return true;
        s.pop_back();
    }
    if(v[(10*r+1)%k] > l) {
        v[(10*r+1)%k] = l;
        s.push_back('1');
        if(dfs((10*r+1)%k, l+1))
            return true;
        s.pop_back();
    }
    return false;
}

int main() {
    while(cin >> k && k) {
        s.assign(1, '1');
        for(int i = 0; i < k; ++i) v[i] = INT_MAX;
        dfs(1, 1);
        for(int i = 0; i < s.size(); ++i)
            putchar(s[i]);
        puts("");
    }
}
