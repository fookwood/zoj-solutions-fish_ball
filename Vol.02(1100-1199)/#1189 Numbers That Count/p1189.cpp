// 2150998 2010-04-10 13:19:06 Accepted  1189 C++ 80 184 呆滞的慢板 

// 简单题，字串演变循环，直接模拟迭代即可。 

#include <iostream>
#include <string>
#include <map>
using namespace std;

string next(string s) {
    int c[10] = {};
    for(int i = 0; i < s.size(); ++i) {
        c[s[i]-'0']++;
    }
    string ans = "";
    char buf[10];
    for(int i = 0; i < 10; ++i) {
        if(c[i]) {
            sprintf(buf, "%d", c[i]);
            ans += buf;
            ans += i + '0';
        }
    }
    return ans;
}

void solve(string s) {
    map<string, int> MP;
    int cnt = 0;
    string t = s;
    while(MP.find(t) == MP.end() && cnt <= 15) {
        MP[t] = cnt++;
        t = next(t);
    }
    if(cnt == 16) {
        cout << s << " can not be classified after 15 iterations" << endl;
    }
    else if(cnt == 1 && MP[t] == 0) {
        cout << s << " is self-inventorying" << endl;
    }
    else if(cnt > 1 && MP[t] == cnt - 1) {
        cout << s << " is self-inventorying after " << cnt - 1 << " steps" << endl;
    }
    else {
        cout << s << " enters an inventory loop of length " << cnt - MP[t] << endl;
    }
//    cout << "cnt = " << cnt << endl;
//    cout << "MP[t] = " << MP[t] << endl;
}

int main() {
    //freopen("out.txt", "w", stdout);
    int T;
    for(cin >> T; T--;) {
        string s;
        while(cin >> s && s != "-1") {
            solve(s);
        }
        if(T) puts("");
    }
}
