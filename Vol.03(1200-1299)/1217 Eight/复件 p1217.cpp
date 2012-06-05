#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    for(string s; getline(cin, s);) {
        
        if(s == "") continue;
        
        for(int i = 0, j = 0; i < s.size(); ++i)
            if(s[i] != ' ') s[j++] = s[i];

        s.erase(9);
        
        map<string, char> MP;
        queue<string> Q;
        
        MP[s] = '?';
        Q.push(s);
        
        while(!Q.empty()) {
            string now = Q.front();
            if(now == "12345678x") break;
            Q.pop();
            int pos = now.find('x');
            if(pos + 3 < 9) {
                swap(now[pos], now[pos+3]);
                if(MP.find(now) == MP.end()) {
                    MP[now] = 'u';
                    Q.push(now);
                }
                swap(now[pos], now[pos+3]);
            }
            if(pos - 3 >= 0) {
                swap(now[pos], now[pos-3]);
                if(MP.find(now) == MP.end()) {
                    MP[now] = 'd';
                    Q.push(now);
                }
                swap(now[pos], now[pos-3]);
            }
            if(pos % 3 < 2) {
                swap(now[pos], now[pos+1]);
                if(MP.find(now) == MP.end()) {
                    MP[now] = 'l';
                    Q.push(now);
                }
                swap(now[pos], now[pos+1]);
            }
            if(pos % 3 > 0) {
                swap(now[pos], now[pos-1]);
                if(MP.find(now) == MP.end()) {
                    MP[now] = 'r';
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
            while((c = MP[now]) != '?') {
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
