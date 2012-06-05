// 1870060 2009-05-15 11:18:38 Accepted  2939 C++ 0 184 呆滞的慢板 

// 实现若干个罗马数字相加并输出。
// 这样的话只需要做好罗马数字与十进制整数的转换即可。 

#include <iostream>
#include <string>
using namespace std;

int rom2dec(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        bool found;
        switch(s[i]) {
            case 'M' : ans += 1000; break;
            case 'D' : ans +=  500; break;
            case 'C' :
                found = false;
                for(int j = i + 1; j < s.size(); ++j) {
                    if(s[j] == 'M' || s[j] == 'D') {
                        found = true;
                        break;
                    }
                }
                if(found) ans -= 100;
                else ans += 100;
            break;
            case 'L' : ans +=  50; break;
            case 'X' :
                found = false;
                for(int j = i + 1; j < s.size(); ++j) {
                    if(s[j] == 'L' || s[j] == 'C') {
                        found = true;
                        break;
                    }
                }
                if(found) ans -= 10;
                else ans += 10;
            break;
            case 'V' : ans +=  5; break;
            case 'I' :
                found = false;
                for(int j = i + 1; j < s.size(); ++j) {
                    if(s[j] == 'V' || s[j] == 'X') {
                        found = true;
                        break;
                    }
                }
                if(found) ans -= 1;
                else ans += 1;
            break;
        }
    }
    return ans;
}

string dec2rom(int d) {
    string ans;
    while(d >= 1000) { d -= 1000; ans += "M"; }
    if(d >= 900) { d -= 900; ans += "CM"; }
    if(d >= 500) { d -= 500; ans += "D"; }
    if(d >= 400) { d -= 400; ans += "CD"; }
    while(d >= 100) { d -= 100; ans += "C"; }
    if(d >= 90) { d -= 90; ans += "XC"; }
    if(d >= 50) { d -= 50; ans += "L"; }
    if(d >= 40) { d -= 40; ans += "XL"; }
    while(d >= 10) { d -= 10; ans += "X"; }
    if(d >= 9) { d -= 9; ans += "IX"; }
    if(d >= 5) { d -= 5; ans += "V"; }
    if(d >= 4) { d -= 4; ans += "IV"; }
    while(d >= 1) { d -= 1; ans += "I"; }
    return ans;
}

int main() {
    int T = 1, N;
    while(cin >> N && N) {
        int tot = 0;
        string s;
        while(N--) {
            cin >> s;
            tot += rom2dec(s);
        }
        cout << "Case " << dec2rom(T++) << ": ";
        cout << dec2rom(tot) << endl;
    }
}
