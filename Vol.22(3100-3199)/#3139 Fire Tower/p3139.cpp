// 1788732 2009-03-14 15:43:20 Accepted  3139 C++ 0 184 呆滞的慢板 

// 火塔，漂亮的几何题，经典问题的扩展！类似 2967 的彩虹那道题。
// 先找出所有斜坡确定的直线，然后按照 2967 的彩虹法求出一系列的上边界折线。
// 然后就是要求上边界折线与下边界折线之间的最短的 y 距离。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 直线 (k, b) y = k * x + b 
typedef pair<double, double> Line;

const double EPS = 1e-8;

// L 是直线集合，P 是下部原来的点折线，Q 是上部生成的点折线。 
vector<Line> L, P, Q;
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
        
        // 初始化坐标点，并录入所有斜面线 
        P.resize(N);
        L.clear();
        for(int i = 0; i < N; ++i) {
            scanf("%lf%lf", &P[i].first, &P[i].second);
            if(i > 0) {
                double xA = P[i-1].first, xB = P[i].first;
                double yA = P[i-1].second, yB = P[i].second;
                double k = (yB - yA) / (xB - xA);
                double b = - k * xA + yA;
                L.push_back(make_pair(k, b));
            }
        }
           
        // 直线按斜率排序 
        sort(L.begin(), L.end());
    
        // 剔除平行线 
        for(int i = N = 1; i < L.size(); ++i) {
            if(eq(L[i].first, L[N-1].first)) {
                if(gt(L[i].second, L[N-1].second))
                    swap(L[i], L[N-1]);
            }
            else L[N++] = L[i];
        }
        L.resize(N);
        
        // 开始堆栈法 
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
        
        Q.clear();
        for(int i = 0; i < stk.size(); ++i) {
            Q.push_back(
                make_pair(
                    stk[i].first,
                    stk[i].second.first * 
                        stk[i].first + 
                        stk[i].second.second
                )
            );
        }
        Q.push_back(
            make_pair(
                200000,
                stk.back().second.first * 200000 +
                    stk.back().second.second
            )
        );
        
        // 产生所有触发点的 X 坐标 
        vector<double> XX;
        for(int i = 1; i + 1 < Q.size(); ++i)
            if(Q[i].first > P.front().first &&
                Q[i].first < P.back().first)
                    XX.push_back(Q[i].first);
        for(int i = 0; i < P.size(); ++i)
            XX.push_back(P[i].first);
            
        sort(XX.begin(), XX.end());
 /*       
        cout << "P:" << endl;
        for(int i = 0; i < P.size(); ++i) cout << P[i].first << ", " << P[i].second << endl;
        cout << "Q:" << endl;
        for(int i = 0; i < Q.size(); ++i) cout << Q[i].first << ", " << Q[i].second << endl;
        cout << endl;
   */     
        // 开始追赶扫描 
        int pi = 0, qi= 0;
        Q.push_back(make_pair(200000.0, 0.0));
        /*
        cout << "XX:" << endl;
        for(int i = 0; i < XX.size(); ++i)
            cout << XX[i] << endl;
*/
        double ans = 2000.0;
        
        for(int i = 0; i < XX.size(); ++i) {
            double x = XX[i], xA, yA, xB, yB, yC, yD;
            while(qi + 1 < Q.size() && Q[qi + 1].first <= x) ++qi;
            while(pi + 1 < P.size() && P[pi + 1].first <= x) ++pi;
            
            xA = P[pi].first, xB = P[pi + 1].first;
            yA = P[pi].second, yB = P[pi + 1].second;
            yC = (x-xA)*(yB-yA)/(xB-xA)+yA;
            
            xA = Q[qi].first, xB = Q[qi + 1].first;
            yA = Q[qi].second, yB = Q[qi + 1].second;
            yD = (x-xA)*(yB-yA)/(xB-xA)+yA;
            
            ans = min(ans, yD - yC);
            
            /*
            cout << "x = " << x << endl;
            cout << "  yC = " << yC << ", yD = " << yD << ", h = " << yD - yC << endl;;
            */
        }
        
        if(ans > 1000) puts("IMPOSSIBLE");
        else printf("%.1lf\n", ans);
    }
    
}
