#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int V[50000];
bool B[50000];

vector<pair<int, int> > MV;

int nxt[50000], M;
bool rem[50001];

int next(int p) {
    if(rem[nxt[p]]) return nxt[p];
    return nxt[p] = next(p);
}

int main() {
    while(cin >> N) {
        MV.clear();
        for(int i = M = 0; i < N; ++i) {
            scanf("%d", V + i);
            if(V[i] > 0) {
                MV.push_back(make_pair(V[i], i));
                ++M;
            }
        }
        sort(MV.begin(), MV.end());
        memset(B, 0, sizeof(B));
        for(int i = 0; i < M; ++i) nxt[i] = i + 1;
        memset(rem, true, sizeof(rem));
        int cnt = 0;
        while(next(0) != M) {
            for(int iter = 0; iter != M; iter = next(iter)) {
                int pos = (MV[iter].first + 7) % N;
                int here = MV[iter].second;
                if(pos != here)
                    here = (here + N - 1) % N;
                while(B[here] == true && here != pos) here = (here + N - 1) % N;
                if(here == pos) {
                    B[MV[iter].second] = true;
                    if(cnt++) putchar(' ');
                    printf("%d", MV[iter].first);
                    rem[iter] = false;
                    break;
                }
            }
cout<< endl;
system("pause");
        }
        puts("");
    }
}
