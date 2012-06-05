// 1723758 2008-12-11 20:56:28 Accepted  2529 C++ 0 184 呆滞的慢板 

// 特殊进制加法，直接用 vector 运算进位，每位的进位权注意就行。 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int    Prime[26] = {  2,  3,  5,  7, 11,
                     13, 17, 19, 23, 29,
                     31, 37, 41, 43, 47,
                     53, 59, 61, 67, 71,
                     73, 79, 83, 89, 97 };

int main() {
    
    string sa, sb;
    vector<int> va, vb, vc;
    
    while(cin >> sa >> sb) {
        va.clear();
        vb.clear();
        sa += ',';
        sb += ',';
        int pos;
        while((pos = sa.find_first_of(',')) != string::npos) {
            va.push_back(atoi(sa.substr(0, pos).c_str()));
            sa.erase(0, pos + 1);
        }
        while((pos = sb.find_first_of(',')) != string::npos) {
            vb.push_back(atoi(sb.substr(0, pos).c_str()));
            sb.erase(0, pos + 1);
        }
        reverse(va.begin(), va.end());
        reverse(vb.begin(), vb.end());
        while(va.size() < vb.size()) va.push_back(0);
        while(va.size() > vb.size()) vb.push_back(0);
        vc.assign(1, 0);
        for(int i = 0, carry = 0; i < va.size(); ++i, vc.push_back(carry)) {
            vc.back() += va[i] + vb[i];
            carry = vc.back() / Prime[i];
            vc.back() %= Prime[i];
        }
        if(vc.size() > 1 && vc.back() == 0) vc.pop_back();
        while(!vc.empty()) {
            cout << vc.back();
            vc.pop_back();
            if(!vc.empty()) cout << ',';
        }
        puts("");
    }
    
}
