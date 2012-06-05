// 2003140 2009-09-26 23:22:05 Accepted  2250 C++ 80 184 呆滞的慢板 

// 简单题，水题，求出现次数第二多的数字们是多少。不要想当然，题目没错。。 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int M, N, V;
    while(cin >> M >> N && (M || N)) {
        int MP[10001] = {}, MQ[10001];
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                scanf("%d", &V);
                MP[V]++;
            }
        }
        int v1 = INT_MIN, v2 = INT_MIN;
        memcpy(MQ, MP, sizeof(MQ));
        sort(MP, MP + 10000);
        for(int i = 1; i <= 10000; ++i) {
            if(MP[i] > v1) {
                v2 = v1;
                v1 = MP[i];
            }
        }
        if(v2 == INT_MIN) continue;
        for(int i = 1; i <= 10000; ++i) {
            if(MQ[i] == v2)
                cout << i << ' ';
        }
        cout << endl;
    }
}
