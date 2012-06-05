// 1686508 2008-11-02 16:23:14 Accepted  2831 C++ 0 184 ´ôÖÍµÄÂý°å 

// Ä¢¹½°æ A+B£¬³ýÁËÓ²¸ã»¹ÊÇÓ²¸ãÁË¡£ 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S = "0123456789+";

string C[11][8] = {
{"  XXXX  ",
 " XX  XX ",
 " XX  XX ",
 " XX  XX ",
 " XX  XX ",
 " XX  XX ",
 " XX  XX ",
 "  XXXX  "},

{"   XX   ",
 " XXXX   ",
 "   XX   ",
 "   XX   ",
 "   XX   ",
 "   XX   ",
 "   XX   ",
 " XXXXXX "},

{"  XXXX  ",
 " XX  XX ",
 " XX  XX ",
 "     XX ",
 "    XX  ",
 "   XX   ",
 "  XX    ",
 " XXXXXX "},

{"  XXXX  ",
 " X   XX ",
 "     XX ",
 "   XXX  ",
 "     XX ",
 "     XX ",
 " X   XX ",
 "  XXXX  "},

{"    XX  ",
 "   XXX  ",
 "   XXX  ",
 "  X XX  ",
 " X  XX  ",
 " XXXXXX ",
 "    XX  ",
 "  XXXXX "}, 

{"  XXXXX ",
 "  XX    ",
 "  XXXX  ",
 "  X  XX ",
 "     XX ",
 "     XX ",
 " X   XX ",
 "  XXXX  "},

{"   XXXX ",
 "  XX    ",
 " XX     ",
 " XXXXX  ",
 " XX  XX ",
 " XX  XX ",
 " XX  XX ",
 "  XXXX  "},

{" XXXXXX ",
 " X   XX ",
 "     XX ",
 "    XX  ",
 "    XX  ",
 "    XX  ",
 "   XX   ",
 "   XX   "},

{"  XXXX  ",
 " XX  XX ",
 " XX  XX ",
 "  XXXX  ",
 " XX  XX ",
 " XX  XX ",
 " XX  XX ",
 "  XXXX  "},

{"  XXXX  ",
 " XX  XX ",
 " XX  XX ",
 " XX  XX ",
 "  XXXXX ",
 "     XX ",
 "    XX  ",
 " XXXX   "},

{"        ",
 "   X    ",
 "   X    ",
 "   X    ",
 "XXXXXXX ",
 "   X    ",
 "   X    ",
 "   X    "}};



int N, L;
string s[8], expr;

char check(int k) {
    for(int i = 0; i < 11; ++i) {
        bool yes = true;
        for(int j = 0; j < 8; ++j) {
            if(s[j].substr(k, 8) != C[i][j]) {
                yes = false;
                break;
            }
        }
        if(yes) return S[i];
    }
    return -1;
}

bool judge(int k) {
    for(int i = 0; i < 8; ++i)
        if(s[i][k] == 'X') return true;
    return false;
}

int main() {
    for(cin >> N; N--;) {
        L = 0;
        getline(cin, s[0]);
        for(int i = 0; i < 8; ++i) {
            getline(cin, s[i]);
            L = max(L, int(s[i].size()));
        }
        for(int i = 0; i < 8; ++i)
            s[i] += string(L+1-s[i].size(), ' ');
        expr.erase();
        
        while(L >= 0) {
            if(judge(L)) {
                L -= 6;
                expr = check(L) + expr;
                L -= 1;
            }
            else L--;
        }
        int pos = expr.find('+'),
        ans = atoi(expr.substr(0, pos).c_str()) +
            atoi(expr.substr(pos + 1).c_str());
        char tmp[10];
        sprintf(tmp, "%d", ans);
        int len = strlen(tmp);
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < len; ++j) {
                cout << C[tmp[j]-'0'][i];
            }
            cout << endl;
        }
        if(N) puts("");
    }
}
