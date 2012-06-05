// 1666297 2008-10-14 23:12:58 Accepted  1975 C++ 20 5860 呆滞的慢板  

// 画分形图。类似于 2423 的做法即可。 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> G, P[11];

int main() {
    G.push_back(" /\\ ");
    G.push_back("/__\\");
    P[1] = G;
    for(int i = 1; i < 10; ++i) {
        string s = string(G.back().size() / 2, ' ');
        for(int j = 0; j < 1<<i; ++j) {
            G.push_back(G[j]);
            G.back() += G.back();
            G[j] = s + G[j] + s;
        }
        P[i+1] = G;
    }
    int N;
    while(cin >> N && N) {
        for(int i = 0; i < P[N].size(); ++i) {
            P[N][i].erase(P[N][i].find_last_not_of(' ') + 1);
            cout << P[N][i] << endl;
        }
        puts("");
    }
}
