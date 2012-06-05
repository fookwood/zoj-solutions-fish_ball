// 1663329 2008-10-11 11:06:10 Accepted  1720 C++ 0 184 呆滞的慢板 

// 简单模拟，多项式的格式化输出 

#include <iostream>
#include <string>
using namespace std;

inline int abs(int x) {return x < 0 ? -x : x;}

string i2a(int x) {
    char a[10];
    sprintf(a, "%d", x);
    return a;
}

string D[] = {
    "",
    "x",
    "x^2",
    "x^3",
    "x^4",
    "x^5",
    "x^6",
    "x^7",
    "x^8"
};

int main() {
    while(1) {
        string ans = "";
        int x;
        for(int i = 8; i >= 0; --i) {
            if(!(cin >> x)) return 0;
            if(x == 0) continue;
            else if(x < 0) ans += " - ";
            else ans += " + ";
            x = abs(x);
            if(x != 1 || i == 0) ans += i2a(x);
            ans += D[i];
        }
        if(ans == "") {puts("0"); continue;}
        if(ans[1] == '+') ans.erase(0 ,3);
        else {ans [2] = '-'; ans.erase(0, 2);}
        cout << ans << endl;
    }
}
