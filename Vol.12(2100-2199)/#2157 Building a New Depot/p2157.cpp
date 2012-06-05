// 1860297 2009-05-08 18:51:49 Accepted  2157 C++ 0 184 呆滞的慢板 

// 一个篱笆，所有边都是水平或者竖直的。
// 给出所有的拐弯点的坐标，问篱笆的长度。
// 很明显，对于同一 x 坐标的点有 2k 个，它们的 y 坐标排序后是 y[1..2k] 
// 那么很明显 y2-y1 肯定有篱笆， y4-y3 肯定有篱笆，依次类推，可以求出
// 所有平行 x 轴的篱笆长度。如法炮制即可求得平行 y 轴那一部分的。 

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    for(int N; cin >> N && N;) {
        map<int, vector<int> > X, Y;
        while(N--) {
            int x, y;
            scanf("%d%d", &x, &y);
            X[x].push_back(y);
            Y[y].push_back(x);
        }
        int ans = 0;
        for(map<int, vector<int> >::iterator it = X.begin();
                it != X.end(); ++it) {
            if(it->second.size() % 2) while(1) puts("OLE!!!");
            sort(it->second.begin(), it->second.end());
            for(int i = 0; i < it->second.size(); i += 2)
                ans += it->second[i+1] - it->second[i];
        }
        for(map<int, vector<int> >::iterator it = Y.begin();
                it != Y.end(); ++it) {
            if(it->second.size() % 2) while(1) puts("OLE!!!");
            sort(it->second.begin(), it->second.end());
            for(int i = 0; i < it->second.size(); i += 2)
                ans += it->second[i+1] - it->second[i];
        }
        printf("The length of the fence will be %d units.\n", ans);
    }
}
