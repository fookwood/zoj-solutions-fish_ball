// 1686214 2008-11-02 13:50:58 Accepted  2819 C++ 50 200 呆滞的慢板 

// 立体几何，只需判定一下两个三维向量的夹角即可。 

#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

double x[500], y[500], z[500], d[500], px, py, pz, pd, w;
bool B[500];
int N, M, C;

int main() {
    while(cin >> N && N) {
        for(int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i] >> z[i];
            d[i] = sqrt(x[i]*x[i]+y[i]*y[i]+z[i]*z[i]);
        }
        memset(B, C = 0, sizeof(B));
        for(cin >> M; M--;) {
            cin >> px >> py >> pz >> w;
            pd = sqrt(px*px+py*py+pz*pz);
            w = cos(w);
            for(int i = 0; i < N; ++i) {
                if(B[i]) continue;
                if(w - (px*x[i]+py*y[i]+pz*z[i])/(d[i]*pd) < -EPS)
                    C += (B[i] = true);
            }
        }
        cout << C << endl;
    }
}
