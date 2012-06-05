// 1831446 2009-04-12 18:48:00 Accepted  1409 C++ 50 184 呆滞的慢板 

// 求最佳带宽价格比，其中带宽为所有组件的带宽最小值，
// 价格为各个组件价格总和，用贪心即可：
// 记录所有可能的带宽，然后枚举带宽求最优价格值，直接贪心得到当时的比例更新最大值。 

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    
    int T, N;
    
    for(cin >> T; T--;) {
        
        set<int> bands;
        
        cin >> N;
        
        vector<vector<pair<int, int> > > V(N);
        
        for(int i = 0, K; i < N; ++i) {
            cin >> K;
            V[i].resize(K);
            for(int j = 0; j < K; ++j) {
                cin >> V[i][j].first >> V[i][j].second;
                bands.insert(V[i][j].first);
            }
        }
        
        double best = 0;
        
        for(set<int>::iterator it = bands.begin(); it != bands.end(); ++it) {
            int low = *it;
            int sum = 0;
            for(int i = 0; i < N; ++i) {
                int price = INT_MAX;
                for(int j = 0; j < V[i].size(); ++j) {
                    if(V[i][j].first >= low)
                        price = min(price, V[i][j].second);
                }
                if(price == INT_MAX) {
                    low = -1;
                    break;
                }
                else sum += price;
            }
            if(low == -1) continue;
            else best = max(best, double(low) / double(sum));
        } 
        
        printf("%.3lf\n", best);
        
    } 
    
}
