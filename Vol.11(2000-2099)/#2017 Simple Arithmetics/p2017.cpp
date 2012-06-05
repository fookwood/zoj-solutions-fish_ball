// 1833286 2009-04-14 13:36:50 Accepted  2017 C++ 250 184 呆滞的慢板 

// 模拟笔算，其实没什么难度的，但是输出格式方面真的需要斟酌。 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a.size() < b. size()) a += '0';
    while(a.size() > b. size()) b += '0';
    int carry = 0;
    string ans = "";
    for(int i = 0; i < a.size(); ++i) {
        int c = carry + a[i] - '0' + b[i] - '0';
        if(c > 9) {
            carry = 1;
            c -= 10;
        }
        else carry = 0;
        ans += ('0' + c);
    }
    if(carry) ans += '1';
    /*
    int up = ans.size() - 1;
    while(up > 0 && ans[up] == '0') --up;
    ans = ans.substr(0, up + 1);
    */
    reverse(ans.begin(), ans.end());
    return ans;
}

string sub(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a.size() < b. size()) a += '0';
    while(a.size() > b. size()) b += '0';
    int carry = 0;
    string ans = "";
    for(int i = 0; i < a.size(); ++i) {
        int c = a[i] - b[i] - carry;
        if(c < 0) {
            carry = 1;
            c += 10;
        }
        else carry = 0;
        ans += ('0' + c);
    }
    //*
    int up = ans.size() - 1;
    while(up > 0 && ans[up] == '0') --up;
    if(up >= 0) ans.erase(up + 1);
    //*/
    reverse(ans.begin(), ans.end());
    return ans;
}

string mul(string a, char b) {
    reverse(a.begin(), a.end());
    int val = b - '0';
    int carry = 0;
    string ans = "";
    for(int i = 0; i < a.size(); ++i) {
        int c = val * (a[i] - '0') + carry;
        carry = c / 10;
        c %= 10;
        ans += ('0' + c);
    }
    if(carry) ans += '0' + carry;
    int up = ans.size() - 1;
    while(up > 0 && ans[up] == '0') --up;
    if(up >= 0) ans.erase(up + 1);
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<string> mul(string a, string b) {
    vector<string> ans;
    for(int i = b.size() - 1; i >= 0; --i)
        ans.push_back(mul(a, b[i]));
    return ans;
}

int main() {
    int N;
    for(cin >> N; N--;) {
        string s, a, b;
        cin >> s;
        int pos = 0;
        while(pos < s.size() && isdigit(s[pos])) pos++;
        a = s.substr(0, pos);
        b = s.substr(pos + 1);
        if(s[pos] == '+') {
            string c = add(a, b);
            b = '+' + b;
            size_t most = a.size();
            most = max(most, b.size());
            most = max(most, c.size());
            string d = string(max(b.size(), c.size()), '-');
            cout << string(most - a.size(), ' ') << a << endl;
            cout << string(most - b.size(), ' ') << b << endl;
            cout << string(most - d.size(), ' ') << d << endl;
            cout << string(most - c.size(), ' ') << c << endl;
        }
        else if(s[pos] == '-') {
            string c = sub(a, b);
            b = '-' + b;
            size_t most = a.size();
            most = max(most, b.size());
            most = max(most, c.size());
            string d = string(max(b.size(), c.size()), '-');
            cout << string(most - a.size(), ' ') << a << endl;
            cout << string(most - b.size(), ' ') << b << endl;
            cout << string(most - d.size(), ' ') << d << endl;
            cout << string(most - c.size(), ' ') << c << endl;
        }
        else if(s[pos] == '*') {
            vector<string> c = mul(a, b);
            vector<string> ans(0);
            string final = "0";
            for(int i = 0; i < c.size(); ++i) {
                string tmp = c[i] + string(i, '0');
                final = add(final, tmp);
            }
            ans.push_back(a);
            ans.push_back("*" + b);
            if(c.size() == 1) {
                ans.push_back(string(max(final.size(), ans[1].size()), '-'));
                ans.push_back(final);
            }
            else {
                ans.push_back(string(max(c[0].size(), ans[1].size()), '-'));
                for(int i = 0; i < c.size(); ++i)
                    ans.push_back(c[i] + string(i, ' '));
                ans.push_back(string(max(final.size(), ans.back().size()), '-'));
                ans.push_back(final);
            }
            int most = 0;
            for(int i = 0; i < ans.size(); ++i)
                if(ans[i].size() > most) most = ans[i].size();
            for(int i = 0; i < ans.size(); ++i) {
                ans[i] = string(most - ans[i].size(), ' ') + ans[i];
                int up = ans[i].size() - 1;
                while(up > 0 && ans[i][up] == ' ') --up;
                if(up >= 0) ans[i].erase(up + 1);
                puts(ans[i].c_str());
            }
        }
        cout << endl;
    }
}
