// 1943447 2009-07-25 14:03:46 Accepted  1352 C++ 10 184 呆滞的慢板 

// 直接数制转换模板。 

#include <iostream>
#include <deque>
#include <string>
using namespace std;

class BaseConvert {

    deque<int> add(deque<int> lhs, deque<int> rhs, int b) {
        int carry = 0;
        deque<int> ans;
        for (int i = 0; i < lhs.size() || i < rhs.size(); ++i) {
            int now = (i < lhs.size() ? lhs[i] : 0) + 
                (i < rhs.size() ? rhs[i] : 0) + carry;
            ans.push_back(now % b);
            carry = now / b;
        }
        ans.push_back(carry);
        while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
        return ans;
    }

    deque<int> mult(deque<int> lhs, int rhs, int b) {
        int carry = 0;
        for (int i = 0; i < lhs.size(); ++i) {
            int now = lhs[i] * rhs + carry;
            lhs[i] = now % b;
            carry = now / b;
        }
        lhs.push_back(carry);
        while(lhs.size() > 1 && lhs.back() == 0) lhs.pop_back();
        return lhs;
    }

    deque<int> mult(deque<int> lhs, deque<int> rhs, int b) {
        deque<int> ans;
        for (int i = rhs.size() - 1; i >= 0; --i) {
            deque<int> now = mult(lhs, rhs[i], b);
            ans.push_front(0);
            ans = add(ans, now, b);
        }
        ans.push_back(0);
        while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
        return ans;
    }

    deque<int> convert(int num, int b) {
        deque<int> ans;
        while(num > 0) {
            ans.push_back(num % b);
            num /= b;
        }
        if(ans.empty()) ans.push_back(0);
        return ans;
    }

public:

    string Convert(string alien_number, string source_language, string target_language) {
        int b1 = source_language.size();
        int b2 = target_language.size();
        deque<int> num;
        for (int i = 0; i < alien_number.size(); ++i) {
            num = mult(num, convert(b1, b2), b2);
            num = add(num, convert(source_language.find(alien_number[i]), b2), b2);
        }
        string ans = "";
        for (int i = num.size() - 1; i >= 0; --i) {
            ans = ans + target_language[num[i]];
        }
        if (ans == "") ans = target_language.substr(0, 1);
        return ans;
    }
};


int main() {
    
    int a, b;
    string s;
    string c = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    BaseConvert bc;
    
    int T;
    for(cin >> T; T--;) {
        cin >> a >> b >> s;
        cout << a << " " << s << endl;
        cout << b << " " << bc.Convert(s, c.substr(0, a), c.substr(0, b)) << endl;
        puts("");
    }
    
}

