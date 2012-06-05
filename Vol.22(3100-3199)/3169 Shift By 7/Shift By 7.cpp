#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N;
int V[50000];
bool B[50000];

map<int, int> MP;

int main() {
    while(cin >> N) {
        MP.clear();
        for(int i = 0; i < N; ++i) {
            scanf("%d", V + i);
            if(V[i] > 0) MP[V[i]] = i;
        }
        memset(B, 0, sizeof(B));
        int cnt = 0;
        while(!MP.empty()) {
            for(map<int, int>::iterator iter = MP.begin();
                iter != MP.end(); ++iter) {
                int pos = (iter -> first + 7) % N;
                int here = iter -> second;
                if(pos != here)
                    here = (here + N - 1) % N;
                while(B[here] == true && here != pos) here = (here + N - 1) % N;
                if(here == pos) {
                    B[iter -> second] = true;
                    if(cnt++) putchar(' ');
                    printf("%d", iter -> first);
                    MP.erase(iter);
                    break;
                }
            }
        }
        puts("");
    }
}
