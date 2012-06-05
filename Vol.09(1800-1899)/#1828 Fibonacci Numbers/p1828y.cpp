// 3065270 2008-09-10 00:25:40 Accepted 1828 C++ 00:00.04 852K ´ôÖÍµÄÂı°å 

// ´óÊı 

#include <iostream>
#include <string>
#include <algorithm>
 
const std::size_t BSZ = 1000; 

struct BigNum {
    int s[BSZ];
    BigNum() { memset(s, 0, sizeof(s)); }
    BigNum(int);
    int& operator[](int p) { return s[p]; }
    const int& operator[](int p) const { return s[p]; }
}; 

BigNum::BigNum(int x) {
    memset(s, 0, sizeof(s));
    s[0] = 1;
    s[1] = x;
    if(x >= 10000) {
        s[2] = s[1] / 10000;
        s[1] %= 10000;
        s[0] = 2;
    }
}

std::istream& operator>>(std::istream& is, BigNum& x) {
    char    buf[4*BSZ+1];
    int     i,  j,  len;
    memset(x.s, 0, sizeof(x.s));
    is >> buf;
    x[0] = strlen(buf); 
    std::reverse(buf, buf + x[0]);
    len = x[0] = (x[0] + 3) / 4;
    for(j = strlen(buf); j < x[0] * 4; buf[j++] = '0');
    for(i = 1; i <= len; i++)
        for(x.s[i] = 0, j = 0; j < 4; j++)
            x[i] = x[i] * 10 + buf[i*4-1-j] - '0';
    for(; !x[x[0]] && x[0] > 1; x[0]--);
    return  is;
}

std::ostream& operator<<(std::ostream& os, const BigNum& x) {
    os << x[x[0]];
    for(int i = x[0] - 1; i; i--)
        for(int j = 1000; j; j /= 10)
            os << x[i] / j % 10;
    return  os;
}

int comp(const BigNum& a, const BigNum& b){
    int i;
    if(a[0] != b[0]) return a[0] - b[0];
    for(i = a[0]; i; i--)
        if(a[i] != b[i])
            return  a[i] - b[i];
    return 0;
}

bool operator==(const BigNum& a, const BigNum& b) { return comp(a, b)==0; }
bool operator!=(const BigNum& a, const BigNum& b) { return comp(a, b)!=0; }
bool operator< (const BigNum& a, const BigNum& b) { return comp(a, b)< 0; }
bool operator<=(const BigNum& a, const BigNum& b) { return comp(a, b)<=0; }
bool operator> (const BigNum& a, const BigNum& b) { return comp(a, b)> 0; }
bool operator>=(const BigNum& a, const BigNum& b) { return comp(a, b)>=0; }

BigNum operator+(const BigNum& a, const BigNum& b) {
    BigNum  c;  int i;
    for(i = 1; i <= b[0] || i <= a[0]; i++) {
        if((c[i] += a[i] + b[i]) >= 10000) {
            c[i] -= 10000;
            c[i+1] = 1;
        }
    }
    c[0] = i;
    if(c[0] > 1 && !c[c[0]]) c[0] -= 1;
    return  c;
}

using namespace std;

int main() {
    
    int     N;
    BigNum  a,  b,  c;
    
    while( cin >> N ) {
        if( N < 3 ) {
            puts( "1" );
            continue;
        }
        a = b = 1;
        for( int i = 2; i < N; ++i ) {
            c = a + b;
            a = b;
            b = c;
        }
        cout << c << endl;
    }
    
}
