// 1706060 2008-11-21 20:52:15 Accepted  2967 C++ 80 184 呆滞的慢板 

// 堆栈贪心法。先按斜率排序，然后用一个堆栈保存一系列 "半直线" 。 
// 半直线保存直线和最后一个交点 x 值。
// 然后按照排序向堆栈插入直线，如果新加入的直线与栈顶直线交点小于栈顶 x，退栈。
// 直到堆栈只剩一个或者满足条件，插入新的 x 和直线。
// 最后堆栈的大小即为所求。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<double, double> Line;

const double EPS = 1e-8;

vector<Line> L;
vector<pair<double, Line> > stk;

int T, N;

inline bool lt(double x, double y) {return x < y - EPS;}
inline bool gt(double x, double y) {return y < x - EPS;}
inline bool le(double x, double y) {return x < y + EPS;}
inline bool ge(double x, double y) {return y < x + EPS;}
inline bool eq(double x, double y) {return x < y + EPS && y < x + EPS;}
inline bool ne(double x, double y) {return x > y + EPS || y > x + EPS;}

double intersect(const Line& m, const Line& n) {
    return (m.second - n.second) / (n.first - m.first);
}

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        L.resize(N);
        for(int i = 0; i < N; ++i)
            scanf("%lf%lf", &L[i].first, &L[i].second);
        sort(L.begin(), L.end());
        for(int i = N = 1; i < L.size(); ++i) {
            if(eq(L[i].first, L[N-1].first)) {
                if(gt(L[i].second, L[N-1].second))
                    swap(L[i], L[N-1]);
            }
            else L[N++] = L[i];
        }
        L.resize(N);
        stk.clear();
        stk.push_back(make_pair(0.0, L[0]));
        for(int i = 1; i < N; ++i) {
            while(1) {
                double x = intersect(L[i], stk.back().second);
                if(stk.size() > 1 && le(x, stk.back().first))
                    stk.pop_back();
                else {
                    stk.push_back(make_pair(x, L[i]));
                    break;
                }
            }
        }
        cout << stk.size() << endl;
    }
    
}
