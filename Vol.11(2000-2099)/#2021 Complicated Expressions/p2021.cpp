// 1833475 2009-04-14 17:25:19 Accepted  2021 C++ 480 184 呆滞的慢板 

// 多余括号消除，1423 的加强版 

// 表达式多余括号消除，完整的逻辑应该消除如下几种情况：
// 1、开头的括号；
// 2、前导是 '(' 或 '+' 的 '('，如果匹配的 ')' 后面是 '+' 或减，消除，
//    否则如果 ')' 后面是 '*' 或 '/' 则其一级范围内不存在 '+' 和 '-' 者消除；
// 3、'-' 和 '*' 后面的 '(' ，其后一级范围没有出现 '+' 和 '-' 者消除；
// 4、'/' 后面的 '(' ，其后一级范围没有出现 '+', '-', '*' 和 '/' 者消除；

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    while(N--) {
        cin >> s; 
        s = "+" + s + "+";
        // 剔除 +( 的情况： 
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if((s[pos-1] == '+' || s[pos-1] == '(') && s[pos] == '(') {
                    int pos2 = pos + 1;
                    int cnt = 1, add = 0, sub = 0;
                    while(cnt) {
                        if(s[pos2] == '(') cnt += 1;
                        if(s[pos2] == ')') cnt -= 1;
                        if(cnt == 1 && s[pos2] == '+') add += 1;
                        if(cnt == 1 && s[pos2] == '-') sub += 1;
                        if(cnt == 0) break;
                        pos2 += 1;
                    }
                    if( add + sub == 0 || s[pos2+1] != '*' && s[pos2+1] != '/') {
                        s.erase(pos2, 1);
                        s.erase(pos, 1);
                        break;
                    }
                }
                pos++;
            }
            if(pos == s.size()) break;
        }
        // 剔除 -( 和 *( 的情况： 
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if((s[pos-1] == '-' || s[pos-1] == '*') && s[pos] == '(') {
                    int pos2 = pos + 1;
                    int cnt = 1, add = 0, sub = 0, mul = 0, div = 0;
                    while(cnt) {
                        if(s[pos2] == '(') cnt += 1;
                        if(s[pos2] == ')') cnt -= 1;
                        if(cnt == 1 && s[pos2] == '+') add += 1;
                        if(cnt == 1 && s[pos2] == '-') sub += 1;
                        if(cnt == 1 && s[pos2] == '*') mul += 1;
                        if(cnt == 1 && s[pos2] == '/') div += 1;
                        if(cnt == 0) break;
                        pos2 += 1;
                    }
                    if(add + sub == 0) {
                        s.erase(pos2, 1);
                        s.erase(pos, 1);
                        break;
                    }
                }
                pos++;
            }
            if(pos == s.size()) break;
        }
        // 剔除 /( 的情况：
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if(s[pos-1] == '/' && s[pos] == '(') {
                    int pos2 = pos + 1;
                    int cnt = 1, add = 0, sub = 0, mul = 0, div = 0;
                    while(cnt) {
                        if(s[pos2] == '(') cnt += 1;
                        if(s[pos2] == ')') cnt -= 1;
                        if(cnt == 1 && s[pos2] == '+') add += 1;
                        if(cnt == 1 && s[pos2] == '-') sub += 1;
                        if(cnt == 1 && s[pos2] == '*') mul += 1;
                        if(cnt == 1 && s[pos2] == '/') div += 1;
                        if(cnt == 0) break;
                        pos2 += 1;
                    }
                    if(add + sub + mul + div == 0) {
                        s.erase(pos2, 1);
                        s.erase(pos, 1);
                        break;
                    }
                }
                pos++;
            }
            if(pos == s.size()) break;
        }
        cout << s.substr(1, s.size() - 2) << endl;
    }
}
