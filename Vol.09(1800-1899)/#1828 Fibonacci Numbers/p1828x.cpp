// 3065179 2008-09-09 22:50:27 Accepted 1828 C++ 00:00.36 996K ´ôÖÍµÄÂý°å 

// ´óÊý 

#include <iostream>

const int maxLen = 10000;

class BigNum {
public:
    int len, s[maxLen];
    BigNum(int x = 0);
    BigNum& operator=(int);
    BigNum& operator=(const char*);
    int toInt() const;
    int Compare(const BigNum& b);
};

int BigNum::toInt() const {
    if( len > 9 ) return -1;
    int ans = 0;
    for(int i = 1; i <= len; ++i) {
        ans *= 10;
        ans += s[i];
    }
    return  ans;
}

BigNum::BigNum(int x) {
    if(x == 0)  s[len = 1] = 0;
    else for(len = 0; x > 0;) {
        s[++len] = x % 10;
        x /= 10;
    }
}

BigNum& BigNum::operator = (int x) {
    if(x == 0)  s[len = 1] = 0;
    else for(len = 0; x > 0;) {
        s[++len] = x % 10;
        x /= 10;
    }
    return  *this;
}

BigNum& BigNum::operator = (const char *str) {
    len = strlen(str);
    for(int i = 1; i <= len; i++)
        s[i] = str[len-i] - '0';
    return  *this;
}

std::istream& operator>>(std::istream& in, BigNum& x) {
    char str[maxLen];
    in >> str;
    x = str;
    return  in;
}

std::ostream& operator<<(std::ostream& out, const BigNum& x) {
    for(int i = x.len; i >= 1; i--)
        out << x.s[i];
    return out;
}

int Compare(const BigNum& a, const BigNum& b) {
    if(a.len > b.len) return 1;
    if(a.len < b.len) return -1;
    int i = a.len;
    while(i > 1 && a.s[i] == b.s[i]) i--;
    return  a.s[i] - b.s[i];
}

bool operator==(const BigNum& a, const BigNum& b) {return Compare(a, b) == 0;}
bool operator!=(const BigNum& a, const BigNum& b) {return Compare(a, b) != 0;}
bool operator< (const BigNum& a, const BigNum& b) {return Compare(a, b) <  0;}
bool operator<=(const BigNum& a, const BigNum& b) {return Compare(a, b) <= 0;}
bool operator> (const BigNum& a, const BigNum& b) {return Compare(a, b) >  0;}
bool operator>=(const BigNum& a, const BigNum& b) {return Compare(a, b) >= 0;}

BigNum operator+(const BigNum& a, const BigNum& b) {
    int i;  BigNum  c;
    c.s[1] = 0;
    for(i = 1; i <= a.len || i <= b.len || c.s[i]; i++) {
        if(i <= a.len) c.s[i] += a.s[i];
        if(i <= b.len) c.s[i] += b.s[i];
        c.s[i+1] = c.s[i] / 10;  c.s[i] %= 10; 
    }
    c.len = i - 1 ? i - 1 : 1;
    return  c;
}

BigNum operator-(const BigNum& a, const BigNum& b) {
    int i,  j;  BigNum  c;
    for(i = 1, j = 0; i <= a.len; i++) {
        c.s[i] = a.s[i] - j;
        if(i <= b.len)  c.s[i] -= b.s[i];
        if(c.s[i] < 0) { j = 1; c.s[i] += 10; } else j = 0;
    }
    c.len = a.len;
    while(c.len > 1 && !c.s[c.len]) c.len--;   
    return  c;
}

BigNum operator*(const BigNum& a, const BigNum& b) {
    int i,  j;
    BigNum  c;
    c.len = a.len + b.len;
    for(i = 1; i <= c.len; i++) c.s[i] = 0;
    for(i = 1; i <= a.len; i++)
        for(j = 1; j <= b.len; j++)
            c.s[i+j-1] += a.s[i] * b.s[j];
    for(i = 1; i < c.len; i++) {
        c.s[i+1] += c.s[i] / 10;
        c.s[i] %= 10;
    }
    while(c.s[i]) {
        c.s[i+1] = c.s[i] / 10;
        c.s[i++] %= 10;
    }
    while(i > 1 && !c.s[i]) c.len = --i;
    return c;
}

BigNum operator/(const BigNum& a, const BigNum& b) {
    int i,  j;  BigNum  d(0), c;
    for(i = a.len; i > 0; i--) {
        if(d.len != 1 || d.s[1]) {
            for(j = d.len; j > 0; j--)
                d.s[j+1] = d.s[j];
            ++d.len;
        }
        d.s[1] = a.s[i];
        c.s[i] = 0;
        while( (j = Compare(d, b)) >= 0 ) {
            d = d - b;
            c.s[i]++;
            if(j == 0) break; 
        }
    }
    c.len = a.len;
    while(c.len > 1 && !c.s[c.len]) c.len--;  
    return c;
}

BigNum operator%(const BigNum& a, const BigNum &b) {
    int i,  j;  BigNum  d(0);
    for(i = a.len; i > 0; i--) {
        if(d.len != 1 || d.s[1]) {
            for(j = d.len; j > 0; j--)
                d.s[j+1] = d.s[j];
            ++d.len; 
        }
        d.s[1] = a.s[i];
        while( (j = Compare(d, b)) >=0 ) {
            d = d - b;
            if(j == 0) break;
        }      
    }   
    return d;
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
