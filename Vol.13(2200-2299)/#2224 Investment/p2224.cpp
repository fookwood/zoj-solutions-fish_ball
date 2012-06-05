// 1661430 2008-10-09 09:34:19 Accepted  2224 C++ 2250 1372 呆滞的慢板 

// 典型可重复选取背包，数值较大，用 map 不失为好的实现。
// 10 个物品也顶多是出来 2<<10 大约 1000 个价格组合。 

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int T, S, Y, N;
int V[10], I[10];
map<int, int> M;
map<int, int>::iterator it;

void refresh(int& x, int y) {
    x = x > y ? x : y;
}

int main() {
    for(cin >> T; T--;) {
        cin >> S >> Y >> N;
        for(int i = 0; i < N; ++i)
            cin >> V[i] >> I[i];
        while(Y--) {
            M.clear();
            M[0] = 0;
            for(int i = 0; i < N; ++i)
                for(it = M.begin(); it != M.end(); ++it)
                    if(it->first+V[i] <= S)
                        refresh(M[it->first+V[i]], it->second+I[i]);
            S += M.rbegin()->second;
        }
        cout << S << endl;
    }
}
