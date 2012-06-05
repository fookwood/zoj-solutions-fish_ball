#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    while(scanf("%d", &N), N) {
        vector<pair<int, int> > frames(0);
        int maxPos = 0;
        for(int i = 0, l, p; i < N; ++i) {
            scanf("%d%d", &l, &p);
            maxPos = max(maxPos, p + l);
            frames.push_back(make_pair(p, l));
            vector<int> DP(maxPos, );
        }
    }
}
