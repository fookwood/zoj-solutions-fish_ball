#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int pre[100001];
    
void output(int p) {
    if(pre[p] == -1)
        printf("%d", p);
    else {
        output(pre[p]);
        printf(" %d", p);
    }
}

int main() {
    vector<pair<pair<int, int>, int> > V;
    int T, N;
    for(cin >> T; T--;) {
        cin >> N;
        V.resize(N);
        for(int i = 0; i < N; ++i) {
            scanf("%d%d",
                &V[i].first.first,
                &V[i].first.second);
            V[i].second = i + 1;
        }
        sort(V.begin(), V.end());
        
        vector<pair<pair<int, int>, int> > DP;
        DP.push_back(V[0]);
        memset(pre, -1, sizeof(pre));
        for(int i = 1; i < N; ++i) {
            vector<pair<pair<int, int>, int> >::iterator pos;
            pos = upper_bound(
                DP.begin(),
                DP.end(),
                make_pair(
                    make_pair(
                        V[i].first.first - 1,
                        INT_MAX
                    ),
                    INT_MAX
                )
            );
            
            if(pos != DP.begin()) {
                if((pos-1)->first.second >= V[i].first.second)
                    continue;
                if(pos == DP.end()) {
                    pre[V[i].second] = DP.back().second;
                    DP.push_back(V[i]);
                    continue;
                }
                if(pos->first.second > V[i].first.second) {
                    pre[V[i].second] = (pos-1)->second;
                    *pos = V[i];
                }
            }
            else {
                if(pos->first.second > V[i].first.second)
                    *pos = V[i];
            }
        }
        cout << DP.size() << endl;
//*
cout<<"V:"<<endl;
for(int i = 0; i < V.size(); ++i) {
    cout << V[i].first.first << ',' << V[i].first.second <<":  " << V[i].second<< endl;
}

cout<<"DP:"<<endl;
for(int i = 0; i < DP.size(); ++i) {
    cout << DP[i].first.first << ',' << DP[i].first.second <<":  " << DP[i].second<< endl;
}
//*/
        output(DP.back().second);
        puts("");
        if(T) puts("");
    }
}


/*
4
9
1 1
2 4
6 5
7 5
4 4
6 2
3 3
3 5
5 4
*/
