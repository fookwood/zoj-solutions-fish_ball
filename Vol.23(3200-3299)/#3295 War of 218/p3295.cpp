// 2084959 2010-01-31 23:47:25 Accepted  3295 C++ 30 188 呆滞的慢板 

// 弱智题，问一个 2^N 个选手的全淘汰赛，一个人最多和最少能赢多少局，算法不说自明。 

#include <iostream>
using namespace std;

int N, K;
int A[1024];

int main() {
    while(cin >> N >> K) {
        for(int i = 0; i < (1<<N); ++i) {
            cin >> A[i];
        }
        int above = 0, below = 0;
        int mx, mn;
        for(int i = 0; i < (1<<N); ++i) {
            if(A[i] > A[K]) above++;
            else if(A[i] < A[K]) below++;
        }
        if(above > 0) mn = 0;
        else mn = N;
        mx = 0;
        while((1<<mx)-1 <= below) ++mx;
        cout << mn << " " << mx - 1 << endl;
    }
} 
