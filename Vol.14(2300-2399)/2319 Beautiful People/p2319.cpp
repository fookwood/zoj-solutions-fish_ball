#include <algorithm>
#include <vector>
#include <map>
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
        memset(pre, -1, sizeof(pre));
        multimap<int, pair<pair<int, int>, int> > MP;
        multimap<int, pair<pair<int, int>, int> >::reverse_iterator iter;
        MP.insert(make_pair(1, V[0]));
        for(int i = 1; i < N; ++i) {
            iter = MP.rbegin();
            while(iter != MP.rend()) {
                if(V[i].first.first > iter->second.first.first &&
                    V[i].first.second > iter->second.first.second) {
                    pre[V[i].second] = iter->second.second;
                    MP.insert(make_pair(iter->first+1, V[i]));
                    break;
                }
                ++iter;
            }
        } 
        
/*
cout<<"V:"<<endl;
for(int i = 0; i < V.size(); ++i) {
    cout << V[i].first.first << ',' << V[i].first.second <<":  " << V[i].second<< endl;
}

cout<<"DP:"<<endl;
for(int i = 0; i < DP.size(); ++i) {
    cout << DP[i].first.first << ',' << DP[i].first.second <<":  " << DP[i].second<< endl;
}
//*/
        cout << MP.rbegin()->first << endl;
        output(MP.rbegin()->second.second);
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
