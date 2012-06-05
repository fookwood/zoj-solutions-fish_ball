// 1687492 2008-11-03 13:56:22 Accepted  1803 C++ 0 184 呆滞的慢板 

// 多项式求值的模拟，用(...((x+c[N])*x+c[N-1])*x+...)+c[0] 的方法模拟即可。 

#include <iostream>
#include <vector>
using namespace std;

int N, X, Y, C, P = 1;
vector<int> V;

int count(int x) {
    int ans = 0;
    while(x) {
        ++ans;
        x /= 10;
    }
    return ans;
}

int main() {
    while(cin >> N && N) {
        V.resize(N+1);
        for(int i = 0; i <= N; ++i)
            cin >> V[i];
        cin >> X;
        printf("Polynomial %d: ", P++);
        Y = 0;
        for(int i = 0; i <= N; ++i) {
            Y *= X;
            Y += V[i];
        }
        cout << Y << ' ';
        C = 0;
        for(int i = 1; i <= N; ++i) {
            int p = count(V[i]);
            if(p != 0) C += p + 1;
            C += 2;
        }
        cout << C << endl;
    }
}
