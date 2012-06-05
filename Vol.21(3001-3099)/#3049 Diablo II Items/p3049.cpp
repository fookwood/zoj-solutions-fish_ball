// 1453 2008-10-04 14:54:58 Accepted  DiabloII C++ 30 268 XPer 

#include <iostream>
#include <algorithm>
using namespace std;

int low[1000], inc[1000];
int N, P, now, tot, rem;
char s[100];
int knap[20000];

int main() {
    while(cin >> N >> P) {
        gets(s);
        tot = now = 0;
        for(int n = 0; n < N; ++n) {
            gets(s);
            if(sscanf(s, "%d%d", low+n, inc+n) == 1)
                inc[n] = low[n];
            inc[n] -= P + low[n];
            if(inc[n] <= 0) {
                now += low[n];
                tot += low[n];
                n--; N--;
            }
            else {
                now += low[n];
                now += inc[n];
            }
        }
        if(tot >= P) {
            cout << now << endl;
            continue;
        }
        memset(knap, -1, sizeof(knap));
        knap[0] = 0;
        int mx = 0;
        for(int n = 0; n < N; ++n) {
            mx += inc[n];
            for(int i = P - tot; i >= 0; --i) {
                if(knap[i] != -1) {
                    if(knap[i+low[n]] == -1 ||
                        knap[i+low[n]] > knap[i]+inc[n])
                        knap[i+low[n]] = knap[i]+inc[n];
                }
            }
        }
        int mn = INT_MAX;
        for(int i = P - tot; i < 20000; ++i)
            if(knap[i] != -1)
                mn = min(mn, knap[i]);
        if(mn != INT_MAX)
                cout << now - mn << endl;
        else    cout << now - mx << endl;
    }
}
