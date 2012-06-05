#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class rectConvex {
    int MX, MY, loX, hiX;
    vector<int> Y1, Y2;
public:
    rectConvex(int x, int y) :
        loX(x - 1), hiX(0), Y1(x, -1), Y2(x, -1), MX(x), MY(y) {}
    void take(int x, int y) {
        if(Y1[x] == -1 || Y1[x] > y) Y1[x] = y;
        if(Y2[x] == -1 || Y2[x] < y) Y2[x] = y;
        loX = min(loX, x);
        hiX = max(hiX, x);
    }
    void insert(int x, int y) {
        if(x > 0) {
            take(x - 1, max(y - 1, 0));
            take(x - 1, min(y + 1, MY));
        }
        if(x < MX) {
            take(x, max(y - 1, 0));
            take(x, min(y + 1, MY));
        }
    }
    // 获取边界线
    void process() {
        vector<int> INC(MX, -1), DEC(MX, -1);
        DEC[loX] = Y1[loX];
        for(int x = loX + 1; x <= hiX; ++x) {
            if(Y1[x] == -1) DEC[x] = DEC[x - 1];
            else DEC[x] = min(DEC[x - 1], Y1[x]);
        }
        INC[hiX] = Y1[hiX];
        for(int x = hiX - 1; x >= loX; --x) {
            if(Y1[x] == -1) INC[x] = INC[x + 1];
            else INC[x] = min(INC[x + 1], Y1[x]);
        }
        for(int x = loX; x <= hiX; ++x) Y1[x] = max(DEC[x], INC[x]);
        
        INC.assign(MX, -1); DEC.assign(MX, -1);
        INC[loX] = Y2[loX];
        for(int x = loX + 1; x <= hiX; ++x) {
            if(Y2[x] == -1) INC[x] = INC[x - 1];
            else INC[x] = max(INC[x - 1], Y2[x]);
        }
        DEC[hiX] = Y2[hiX];
        for(int x = hiX - 1; x >= loX; --x) {
            if(Y2[x] == -1) DEC[x] = DEC[x + 1];
            else DEC[x] = max(DEC[x + 1], Y2[x]);
        }
        for(int x = loX; x <= hiX; ++x) Y2[x] = min(DEC[x], INC[x]);
        /*
        printf("loX = %d, hiX = %d\n", loX, hiX);
        cout << "X : "; for(int x = loX; x <= hiX; ++x) printf("%3d", x); puts("");
        cout << "Y1: "; for(int x = loX; x <= hiX; ++x) printf("%3d", Y1[x]); puts("");
        cout << "Y2: "; for(int x = loX; x <= hiX; ++x) printf("%3d", Y2[x]); puts("");
        system("pause");
        //*/
    }
    // 求取面积 
    int getArea() {
        int pos1 = loX, pos2 = loX;
        for(int x = loX + 1; x <= hiX; ++x) {
            if(Y1[x] < Y1[pos1]) pos1 = x;
            if(Y2[x] > Y2[pos2]) pos2 = x;
        }
//cout << "pos1 = " << pos1 << ", pos2 = " << pos2 << endl;
        int lo = Y1[pos1], hi = Y2[pos2];
        if(pos1 > pos2) {
            swap(pos1, pos2);
            reverse(Y1.begin() + pos1, Y1.begin() + pos2 + 1);
            reverse(Y2.begin() + pos1, Y2.begin() + pos2 + 1);
        }
        int now = 0;
        for(int x = pos1; x <= pos2; ++x)
            now += hi - Y2[x];
        int ans = now;
//cout << "now = " << now << endl;
        for(int x = pos1; x < pos2; ++x) {
            now -= hi - Y2[x];
            now += Y1[x + 1] - lo;
            ans = min(now, ans);
        }
//cout << "ans = " << ans << endl;
        ans += MY - hi + lo;
        for(int x = loX; x <= hiX; ++x)
            ans += Y2[x] - Y1[x];
        return ans;
    }
};

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    for(cin >> T; T--;) {
        int X, Y, N;
        cin >> X >> Y >> N;
        vector<int> x(N), y(N);
        for(int i = 0; i < N; ++i)
            cin >> x[i] >> y[i];
        rectConvex rc1(X, Y), rc2(Y, X);
        for(int i = 0; i < N; ++i) {
            rc1.insert(x[i], y[i]);
            rc2.insert(y[i], x[i]);
        }
        rc1.process();
        rc2.process();
        cout << min(rc1.getArea(), rc2.getArea()) << endl;
    }
//    system("pause");
}
