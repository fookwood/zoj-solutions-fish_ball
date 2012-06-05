// 1886441 2009-05-28 03:57:44 Accepted  1916 C++ 0 184 呆滞的慢板 

// 时区转换，就是字符串形式的时间和分钟数之间的转换。
// 实际时间表示上，如果对 am-pm 的时间表示方式不是太熟悉的话， 
// 搞起来有点恶心。时区的输入处理稍要技巧，手工打一个表然后 map 就差不多了。 

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> MP;

string name[32] = {
    "UTC",  "GMT",  "BST",  "IST",  "WET",
    "WEST", "CET",  "CEST", "EET",  "EEST",
    "MSK",  "MSD",  "AST",  "ADT",  "NST",
    "NDT",  "EST",  "EDT",  "CST",  "CDT",
    "MST",  "MDT",  "PST",  "PDT",  "HST",
    "AKST", "AKDT", "AEST", "AEDT", "ACST",
    "ACDT", "AWST"
};

int inc[32] = {
       0,    0,   60,   60,    0, 
      60,   60,  120,  120,  180, 
     180,  240, -240, -180, -210, 
    -150, -300, -240, -360, -300, 
    -420, -360, -480, -420, -600, 
    -540, -480,  600,  660,  570, 
     630,  480
};

int getmin(string s) {
    int pos = s.find(':');
    int a = atoi(s.substr(0, pos).c_str());
    if(a == 12) a = 0;
    int b = atoi(s.substr(pos + 1).c_str());
    return a * 60 + b;
}

int tomin(string a, string b) {
    if(a == "noon") return 720;
    if(a == "midnight") return 0;
    if(b == "a.m.") return getmin(a);
    else return getmin(a) + 720;
}

void printtime(int a) {
    if(a == 720) puts("noon");
    else if(a == 0) puts("midnight");
    else if(a >= 720) printf("%d:%02d p.m.\n", (a / 60 - 12) ? (a / 60 - 12) : 12, a % 60);
    else printf("%d:%02d a.m.\n", a / 60 ? a / 60 : 12, a % 60);
}

int main() {
    int N;
    for(int i = 0; i < 32; ++i) MP[name[i]] = (inc[i] + 1440) % 1440;
    string a, b, c, d;
    for(cin >> N; N--;) {
        cin >> a;
        if(a != "noon" && a != "midnight") cin >> b;
        cin >> c >> d;
        int t = tomin(a, b);
        t = (1440 + t - MP[c] + MP[d]) % 1440;
        printtime(t);
    }
}
