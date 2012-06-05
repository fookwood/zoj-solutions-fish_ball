#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    char c;
    int end;
    Node* nxt[26];
    Node(char cc = 'A') : c(cc), end(0) { memset(nxt, 0, sizeof(nxt)); }
} *root;

void insert(char* str) {
    Node* ptr = root;
    for(char* cc = str; *cc; ++cc) {
        int i = *cc - 'A';
        if(ptr->nxt[i] == NULL)
            ptr->nxt[i] = new Node(*cc);
        ptr = ptr->nxt[i];
    }
    ptr->end += 1;
}

void destroy(Node* ptr) {
    if(!ptr) return;
    for(int i = 0; i < 26; ++i)
        destroy(ptr->nxt[i]);
    delete ptr;
}

const int MOD = 1000000007;

int cnt[1000][1000];

int main() {
    char text[1001], tile[201];
    int T, N;
    for(cin >> T; T--;) {
        scanf("%s", text);
        int L = strlen(text);
        scanf("%d", &N);
        root = new Node();
        while(N--) {
            scanf("%s", tile);
            insert(tile);
        }
        vector<pair<int, int> > V(0);
        for(int i = 0; text[i]; ++i) {
            Node* ptr = root;
            for(int j = i; text[j]; ++j) {
                ptr = ptr->nxt[text[j]-'A'];
                if(!ptr) break;
                if(ptr->end) {
                    cnt[i][j] = ptr->end;
                    V.push_back(make_pair(i, j));
                }
            }
        }
        destroy(root);
        vector<int> DP(V.size(), 0);
        int ans = 0;
        /*
        for(int i = 0; i < V.size(); ++i) {
            printf("(%d, %d) : %d\n", V[i].first, V[i].second, cnt[V[i].first][V[i].second]);
        }
        */
        for(int i = 0; i < V.size(); ++i) {
            if(V[i].first == 0)
                DP[i] = cnt[V[i].first][V[i].second];
            if(V[i].second == L - 1) {
                ans += DP[i];
                ans %= MOD;
            }
            int j = lower_bound(V.begin(), V.end(), make_pair(V[i].first + 1, V[i].second + 1)) - V.begin();
            int k = upper_bound(V.begin(), V.end(), make_pair(V[i].second, L - 1)) - V.begin();
            while(j < k) {
                DP[j] += ((long long)DP[i] * cnt[V[j].first][V[j].second]) % MOD;
                DP[j] %= MOD;
                j += 1;
            }
        }
        printf("%d\n", ans);
    }
}
