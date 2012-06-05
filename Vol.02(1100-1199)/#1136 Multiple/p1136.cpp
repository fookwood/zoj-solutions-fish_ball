// 1659175 2008-10-06 23:23:56 Accepted  1136 C++ 170 188 呆滞的慢板 

// 保存余数和字符串广搜，注意细节，N 可以为 0，也有可能结果是一位数 

#include <deque>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
vector<int> v;
deque<pair<int, string> > Q;
bool B[5001];

int main() {
    while(cin >> N) {
        cin >> K;
        v.resize(K);
        for(int i = 0; i < K; ++i)
            cin >> v[i];
        sort(v.begin(), v.end());
        if(N == 0) {puts("0"); continue;}
        Q.clear();
        memset(B, 0, sizeof(B));
        for(int i = 0; i < v.size(); ++i) {
            if(v[i]) Q.push_back(make_pair(v[i]%N, string(1, '0'+v[i])));
            if(v[i] && v[i] % N == 0) {
                B[N] = true;
                cout << v[i] << endl;
            }
        }
        if(B[N]) continue;
        string s;
        int r;
        while(!Q.empty()) {
            s = Q.front().second;
            r = Q.front().first;
            Q.pop_front();
            for(int i = 0; i < v.size(); ++i) {
                int p = (r*10 + v[i]) % N;
                if(p == 0) {
                    s += ('0' + v[i]);
                    B[N] = true;
                    Q.clear();
                    break;
                }
                if(B[p]) continue;
                B[p] = true;
                Q.push_back(make_pair(p, s+char('0'+v[i])));
            }
        }
        if(B[N]) cout << s << endl;
        else puts("0");
    }
}
