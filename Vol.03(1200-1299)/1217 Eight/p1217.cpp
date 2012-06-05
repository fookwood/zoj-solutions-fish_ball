#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int frac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

int hash(string s) {
    int ans = 0;
    for(int i = 0; i < 9; ++i) {
        int cnt = 0;
        for(int j = 0; j < i; ++j)
            if(s[i] < s[j])
                ++cnt;
        ans += cnt * frac[i];
    }
    return ans;
} 

char MP[362880];

int main() {

    for(string s; getline(cin, s);) {
        
        if(s == "") break;
        
        for(int i = 0, j = 0; i < s.size(); ++i)
            if(s[i] != ' ') s[j++] = s[i];

        s.erase(9);
        
        memset(MP, -1, sizeof(MP));
        queue<string> Q;
        
        MP[hash(s)] = '?';
        Q.push(s);

        while(!Q.empty()) {
            string now = Q.front();
            if(now == "12345678x") break;
            Q.pop();
            int pos = now.find('x');
            if(pos + 3 < 9) {
                swap(now[pos], now[pos+3]);
                if(MP[hash(now)] == -1) {
                    MP[hash(now)] = 'u';
                    Q.push(now);
                }
                swap(now[pos], now[pos+3]);
            }
            if(pos - 3 >= 0) {
                swap(now[pos], now[pos-3]);
                if(MP[hash(now)] == -1) {
                    MP[hash(now)] = 'd';
                    Q.push(now);
                }
                swap(now[pos], now[pos-3]);
            }
            if(pos % 3 < 2) {
                swap(now[pos], now[pos+1]);
                if(MP[hash(now)] == -1) {
                    MP[hash(now)] = 'l';
                    Q.push(now);
                }
                swap(now[pos], now[pos+1]);
            }
            if(pos % 3 > 0) {
                swap(now[pos], now[pos-1]);
                if(MP[hash(now)] == -1) {
                    MP[hash(now)] = 'r';
                    Q.push(now);
                }
                swap(now[pos], now[pos-1]);
            }
        }
        
        if(Q.empty()) puts("unsolvable");
        else {
            string now = "12345678x";
            string ans("");
            char c;
            while((c = MP[hash(now)]) != '?') {
                ans = c + ans;
                int pos = now.find('x');
                switch(c) {
                    case 'u': swap(now[pos], now[pos-3]); break;
                    case 'd': swap(now[pos], now[pos+3]); break;
                    case 'l': swap(now[pos], now[pos-1]); break;
                    case 'r': swap(now[pos], now[pos+1]); break;
                    default: while(1) puts("Fault(OLE): Unexpected trace.");
                }
            }
            cout << ans << endl;
        }

    }

}
