#include <iostream>
#include <deque>
#include <string>
using namespace std;

int count(int x) {
	x=(x&0x55555555)+((x>>1)&0x55555555);
	x=(x&0x33333333)+((x>>2)&0x33333333);
	x=(x&0x0F0F0F0F)+((x>>4)&0x0F0F0F0F);
	x=(x&0x00FF00FF)+((x>>8)&0x00FF00FF);
	x=(x&0x0000FFFF)+((x>>16)&0x0000FFFF);
	return x;
}

inline void set(int& x, int p) {x |= 1<<p;}

inline void reset(int& x, int p) {x &= ~(1<<p);}

inline bool yes(int x, int p) {return x & (1<<p);}

struct Board {
    int x, y;
    Board() {}
    Board(int x, int y) :
        x(x), y(y) {}
    void get() {
        string s(""), d;
        x = 0; y = 0;
        for(int i = 0; i < 4; ++i) {
            cin >> d;
            s += d;
        }
        for(int i = 0; i < 16; ++i) {
            switch(s[i]) {
                case 'x': set(x, i);
                case 'o': set(y, i);
            }
        }
    }
};

const int D[] = {
    0x000F, 0x00F0, 0x0F00, 0xF000,
    0x1111, 0x2222, 0x4444, 0x8888,
    0x1248, 0x8421
};

bool win(const Board& b) {
    int x = b.x & b.y;
    for(int i = 0; i < 10; ++i)
        if((x & D[i]) == D[i])
            return true;
    return false;
}

bool lose(const Board& b) {
    int x = ~b.x & b.y;
    for(int i = 0; i < 10; ++i)
        if((x & D[i]) == D[i])
            return true;
    return false;
}
int cnt;
bool dfs(Board x) {
    if(cnt++ > 10) return false;
/*
for(int i = 0; i < 16; ++i) {
    if(!yes(x.y, i)) putchar('.');
    else if(yes(x.x, i)) putchar('x');
    else putchar('o');
    if(i % 4 == 3) putchar('\n');
}
system("pause");
//*/
    if(win(x)) return true;
    bool ans = false;
    for(int i = 0; i < 16; ++i) {
        if(!yes(x.y, i)) {
            set(x.y, i);
            if(lose(x)) return false;
            if(!ans);
            for(int j = 0; j < 16; ++j) {
                if(!yes(x.y, j)) {
                    set(x.x, j);
                    set(x.y, j);
                    cnt=0;
                    if(dfs(x)) ans = true;
                    reset(x.y, j);
                    reset(x.x, j);
                }
            }
            reset(x.y, i);
        }
    }
    return ans;
}

int main() {
    Board b;
    char c;
    while(cin >> c && c != '$') {
        b.get();
        int i;
        for(i = 0; i < 16; ++i) {
            if(!yes(b.y, i)) {
                set(b.x, i);
                set(b.y, i);
                cnt = 0;
                if(dfs(b));
                break;
                reset(b.x, i);
                reset(b.y, i);
            }
        }
        if(i == 16) puts("#####");
        else printf("(%d,%d)\n", i / 4, i % 4);
    }
}
