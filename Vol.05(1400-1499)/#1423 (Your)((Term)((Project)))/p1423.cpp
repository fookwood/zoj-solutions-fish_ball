// 1831826 2009-04-13 01:03:06 Accepted  1423 C++ 0 184 呆滞的慢板 

// 表达式多余括号消除，完整的逻辑应该消除如下三种情况：
// 1、开头的括号，例如 (A+B)+C ； 
// 2、前导是 '(' 或者 '+' 的括号，例如 ((A+B)-C) 和(A+(B-C)) ； 
// 3、在括号的一级范围内没有出现符号的括号，例如 ((A+B))； 

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    getline(cin, s);
    while(N--) {
        getline(cin, s);
        s = "+" + s;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == ' ' || s[i] == '\t')
                s.erase(i--, 1);
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if((s[pos-1] == '+' || s[pos-1] == '(') && s[pos] == '(')
                    break;
                pos++;
            }
            if(pos == s.size()) break;
            int pos2 = pos + 1;
            int cnt = 1;
            while(cnt) {
                if(s[pos2] == '(') cnt += 1;
                if(s[pos2] == ')') cnt -= 1;
                if(cnt == 0) break;
                pos2 += 1;
            }
            s.erase(pos2, 1);
            s.erase(pos, 1);
        }
        while(true) {
            int pos = 1;
            while(pos < s.size()) {
                if(s[pos] == '(') {
                    int pos2 = pos + 1;
                    int cnt = 1, sign = 0;
                    while(cnt) {
                        if(s[pos2] == '(') cnt += 1;
                        if(s[pos2] == ')') cnt -= 1;
                        if(cnt == 1 && (s[pos2] == '+' || s[pos2] == '-')) sign += 1;
                        if(cnt == 0) break;
                        pos2 += 1;
                    }
                    if(sign == 0) {
                        s.erase(pos2, 1);
                        s.erase(pos, 1);
                        break;
                    }
                }
                pos++;
            }
            if(pos == s.size()) break;
        }
        cout << s.substr(1) << endl;
    }
}
