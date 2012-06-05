#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// T 为退火次数，step 为步长。 
int m, p, T = 10;
double a, b, low, high, val, step;

vector<double> VEC;

double power(double x, int y) {
    if(y == 1) return x;
    double p = pow(x, y / 2);
    if(y % 2 == 1) p *= p * x;
    else p *= p;
    return p;
}

double eval() {
    double ans = 0;
    for(int i = 0; i < m; ++i)
        ans += power(VEC[i], p);
    return ans;
}

int main() {
    while(cin >> m >> p >> a >> b) {
        high = sqrt(a);
        low = -1.0 / high;
        VEC.assign(m, b * high / m);
        
        step = min(high - VEC[0], VEC[0] - low) / 10;
        for(int v = 0; v < 1000; v++, step *= 0.9) {
            for(int t = 0; t < T; ++t) {
                double maxdown = eval(), maxup = eval();
                int pmin = 0, pmax = 0; 
                for(int i = 0; i < m; ++i) {
                    if(VEC[i] + step < high) {
                        VEC[i] += step;
                        if(eval() > maxup * (1.0 + 1e-10))
                            pmax = i;
                        VEC[i] -= step;
                    }
                    if(VEC[i] - step > low) {
                        VEC[i] -= step;
                        if(eval() > maxdown * (1.0 - 1e-10))
                            pmin = i;
                        VEC[i] += step;
                    }
                }
                
                for(int i = 0; i < m; ++i) {
                    cout << VEC[i] << ' ';
                    cout << endl;
                }
                
                cout << "step: " << step << endl;
                cout << "min: " << pmin << endl;
                cout << "max: " << pmax << endl;
                //system("pause");
                
                VEC[pmin] -= step;
                VEC[pmax] += step;
            }
        }
        
        cout << eval() << endl;
    }
}
