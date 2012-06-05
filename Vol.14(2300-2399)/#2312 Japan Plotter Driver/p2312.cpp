// 1661785 2008-10-09 17:00:35 Accepted  2312 C++ 0 188 呆滞的慢板 

// 蘑菇题，画板的模拟，关键在于字符的组合规则，
// 先把字符的组合规则包成函数，然后画一个字符上去就只须与原来的字符组合就行了。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char P[77][77];
int M, N, x1, y1, x2, y2;
string cmd, txt;

char *COMB[9] = {
    "-+**+**-*",
    "+|**+**|*",
    "**/x*x*/*",
    "**x\\*x*\\*",
    "++**+**+*",
    "**xx*x*x*",
    "*********",
    "-|/\\+x* *",
    "*********"
};

int type(char c) {
    switch(c) {
        case '-': return 0;
        case '|': return 1;
        case '/': return 2;
        case '\\': return 3;
        case '+': return 4;
        case 'x': return 5;
        case '*': return 6;
        case ' ': return 7;
        default: return 8;
    }
    return -1;
}

char comb(char c1, char c2) {
    if(c1 == c2) return c1;
    if(c1 == ' ') return c2;
    if(c2 == ' ') return c1;
    else return COMB[type(c1)][type(c2)];
}

void clear() {
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    x1 = max(x1, 0);
    y1 = max(y1, 0);
    x2 = min(x2, M+1);
    y2 = min(y2, N+1);
    for(int i = x1; i <= x2; ++i)
        for(int j = y1; j <= y2; ++j)
            P[j][i] = ' ';
}

void point() {P[y1][x1] = comb(P[y1][x1], 'o');}

void line() {
    int dx, dy, stp; char pen;
    if(x1 < x2 && y1 < y2) {dx = dy = 1; pen = '\\'; stp = x2 - x1 + 1;}
    if(x1 < x2 && y1 == y2) {dx = 1; dy = 0; pen = '-'; stp = x2 - x1 + 1;}
    if(x1 < x2 && y1 > y2) {dx = 1; dy = -1; pen = '/'; stp = x2 - x1 + 1;}
    if(x1 == x2 && y1 < y2) {dx = 0; dy = 1; pen = '|'; stp = y2 - y1 + 1;}
    if(x1 == x2 && y1 > y2) {dx = 0; dy = -1; pen = '|'; stp = y1 - y2 + 1;}
    if(x1 > x2 && y1 < y2) {dx = -1; dy = 1; pen = '/'; stp = x1 - x2 + 1;}
    if(x1 > x2 && y1 == y2) {dx = -1; dy = 0; pen = '-'; stp = x1 - x2 + 1;}
    if(x1 > x2 && y1 > y2) {dx = -1; dy = -1; pen = '\\'; stp = x1 - x2 + 1;}
    for(int i = 0; i < stp; ++i)
        P[y1+dy*i][x1+dx*i] = comb(pen, P[y1+dy*i][x1+dx*i]);
}

void text() {
    for(int i = 0; i < txt.size() && i+x1 <= M; ++i)
        P[y1][x1+i] = comb(P[y1][x1+i], txt[i]);
}

void print() {
    for(int i = 0; i <= N+1; ++i) {
        for(int j = 0; j <= M+1; ++j)
            putchar(P[i][j]);
        puts("");
    }
    puts("");
}

int main() {
    while(cin >> M >> N && M) {
        memset(P, ' ', sizeof(P));
        x1 = 0; y1 = 0; x2 = 0; y2 = N+1; line();
        x1 = 0; y1 = 0; x2 = M+1; y2 = 0; line();
        x1 = M+1; y1 = 0; x2 = M+1; y2 = N+1; line();
        x1 = 0; y1 = N+1; x2 = M+1; y2 = N+1; line();
        while(cin >> cmd) {
            if(cmd == "PRINT") {
                print();
                break;
            }
            if(cmd == "LINE") {
                cin >> x1 >> y1 >> x2 >> y2;
                line();
            }
            if(cmd == "TEXT") {
                cin >> x1 >> y1 >> txt;
                text();
            }
            if(cmd == "CLEAR") {
                cin >> x1 >> y1 >> x2 >> y2;
                clear();
            }
            if(cmd == "POINT") {
                cin >> x1 >> y1;
                point();
            }
        }
    }
}
