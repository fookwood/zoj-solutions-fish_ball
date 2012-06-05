// 2002776 2009-09-26 10:14:51 Accepted  1681 C++ 20 184 呆滞的慢板 

// 一个特殊的背包问题，求一个立方数加一个四面体数的背包。 
// 其实只需要用一个 set 保存所有的组合即可。
// 假设最大输入是 N，则复杂度为 O(N^2/3)，完全可以胜任。 

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> S;
    for(int i = 0, iii; (iii = i * i * i) <= 151200; ++i) {
        S.insert(iii);
        for(int j = 1, jjj; jjj = j*(j+1)*(j+2)/6; ++j) {
            if(iii + jjj > 151200) break;
            S.insert(iii + jjj);
        }
    }
    int x;
    while(cin >> x && x) {
        set<int>::iterator it = S.upper_bound(x);
        cout << *(--it) << endl;
    }
}
