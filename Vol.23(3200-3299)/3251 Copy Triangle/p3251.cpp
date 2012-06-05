#include <iostream>
#include <set>
#include <queue>
using namespace std;

// 返回一个点会在第几个周期被踩到，如果是 -1 则永不被踩。 
int check(int x, int y) {
    if(x < 0 || y < 0) return 0;
    int ans = 0;
    while(x || y) {
        if((x&1)&(y&1)) return -1;
        ++ans;
        x >>= 1;
        y >>= 1;
    }
    return ans;
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Bac {
    int x, y, t;
    Bac(const int& x, const int& y, const int& t) :
        x(x), y(y), t(t) {}
};

int main() {
    int T, N;
    for(cin >> T; T--;) {
        int ans = 0; 
        queue<Bac> Q;
        set<pair<int, int> > S;
        cin >> N;
        while(N--) {
            int x, y;
            cin >> x >> y;
            if(check(x, y) == -1) ++ans;
            Q.push(Bac(x, y, 0));
            S.insert(make_pair(x, y));
        }
        while(!Q.empty()) {
            int x = Q.front().x;
            int y = Q.front().y;
            int t = Q.front().t;
//            cout << x <<' '<< y <<' '<< t << endl;
            Q.pop();
            for(int d = 0, xx, yy; d < 4; ++d) {
                xx = x + dx[d];
                yy = y + dy[d];
                if(S.find(make_pair(xx, yy)) != S.end()) continue;
                int c = check(xx, yy);
//printf("check(%d,%d)=%d\n", xx, yy, c);
                if(c == -1) {
                    ++ans;
                    Q.push(Bac(xx, yy, t+1));
                    S.insert(make_pair(xx, yy));
printf("[%d,%d]+\n", xx, yy);
                }
                else if(c > t) {
                    Q.push(Bac(xx, yy, t+1));
                    S.insert(make_pair(xx, yy));
printf("[%d,%d]\n", xx, yy);
                }
            }
        }
        cout << ans << endl;
    }
    
}
