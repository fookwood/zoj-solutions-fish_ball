// 1663463 2008-10-11 13:45:34 Accepted  1713 C++ 0 184 呆滞的慢板 

// 简单的字符串截取和字符计数。 

#include <iostream>
#include <string>
using namespace std;

string s, s1, s2, s3;

void parse() {
    s1 = s.substr(0, s.find('/'));
    s.erase(0, s.find('/')+1);
    s2 = s.substr(0, s.find('/'));
    s.erase(0, s.find('/')+1);
    s3 = s;
}

bool isVowel(char c) {
    return  c=='a' || c=='A' ||
            c=='e' || c=='E' ||
            c=='i' || c=='I' ||
            c=='o' || c=='O' ||
            c=='u' || c=='U' ||
            c=='y' || c=='Y';
}

int cnt(string str) {
    int ans = 0;
    for(int i = 0; i < str.size(); ++i)
        if(isVowel(str[i]) && (i == 0 || !isVowel(str[i-1])))
            ++ans;
    return ans;
}

int main() {
    while(getline(cin, s) && s != "e/o/i") {
        parse();
        if(cnt(s1) != 5) {puts("1"); continue;}
        if(cnt(s2) != 7) {puts("2"); continue;}
        if(cnt(s3) != 5) {puts("3"); continue;}
        puts("Y");
    }
}
