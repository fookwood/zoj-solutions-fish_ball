// 1665817 2008-10-14 12:56:46 Accepted  1111 C++ 0 184 呆滞的慢板 

// 有点小麻烦的模拟题，梭哈，同花顺，两手牌比大小。以不变应万变是上策。 

#include <iostream>
#include <algorithm>
using namespace std;

int B[5], W[5];

int v[128];

void init() {
    char* suit = "CDHS";
    char* rank = "23456789TJQKA";
    for(int i = 0; suit[i]; ++i)
        v[suit[i]] = i;
    for(int i = 0; rank[i]; ++i)
        v[rank[i]] = i;
}

bool input() {
    char c[3];
    for(int i = 0; i < 5; ++i) {
        if(!(cin >> c)) return false;
        B[i] = v[c[0]] * 4 + v[c[1]];
    }
    for(int i = 0; i < 5; ++i) {
        if(!(cin >> c)) return false;
        W[i] = v[c[0]] * 4 + v[c[1]];
    }
    sort(B, B + 5);
    sort(W, W + 5);
    return true;
}

int flush(int* D) {
    for(int i = 0; i < 4; ++i)
        if(D[i] % 4 != D[i+1] % 4)
            return -1;
    return D[4] / 4;
}

int straight(int* D) {
    for(int i = 0; i < 4; ++i)
        if(D[i] / 4 + 1 != D[i+1] / 4)
            return -1;
    return D[4] / 4;
}

int straightFlush(int* D) {
    if(flush(D) == -1) return -1;
    return straight(D);
}

int four(int* D) {
    if(D[1] / 4 == D[2] / 4 &&
        D[2] / 4 == D[3] / 4) {
        if(D[0] / 4 == D[1] / 4)
            return D[0] / 4;
        if(D[4] / 4 == D[3] / 4)
            return D[4] / 4;
    }
    return -1;
}

int fullHouse(int* D) {
    if(D[1] / 4 == D[0] / 4 &&
        D[4] / 4 == D[4] / 4) {
        if(D[2] / 4 == D[1] / 4 ||
            D[2] / 4 == D[3] / 4)
            return D[2] / 4;
    }
    return -1;
}

int three(int* D) {
    if(D[0] / 4 == D[1] / 4 &&
        D[1] / 4 == D[2] / 4)
        return D[0] / 4;
    if(D[1] / 4 == D[2] / 4 &&
        D[2] / 4 == D[3] / 4)
        return D[1] / 4;
    if(D[2] / 4 == D[3] / 4 &&
        D[3] / 4 == D[4] / 4)
        return D[2] / 4;
    return -1;
}

int twoPairs(int* D) {
    if(D[0] / 4 == D[1] / 4 &&
        D[2] / 4 == D[3] / 4)
        return D[2]/4*169+D[0]/4*13+D[4];
    if(D[0] / 4 == D[1] / 4 &&
        D[4] / 4 == D[3] / 4)
        return D[4]/4*169+D[0]/4*13+D[2];
    if(D[1] / 4 == D[2] / 4 &&
        D[4] / 4 == D[3] / 4)
        return D[2]/4*169+D[3]/4*13+D[0];
    return -1;
}

int onePair(int* D) {
    int x = 0, y = 0;
    bool found = false;
    for(int i = 0; i < 4;) {
        if(D[i] / 4 == D[i+1] / 4) {
            found = true;
            y = D[i] / 4;
            i += 2;
        }
        else {
            x *= 13;
            x += D[i] / 4;
            i += 1;
        }
    }
    if(!found) return -1;
    return y*13*13*13 + x;
}

int highCard(int* D) {
    int ans = 0;
    for(int i = 4; i >= 0; --i) {
        ans *= 13;
        ans += D[i] / 4;
    }
    return ans;
}

typedef int (*fun)(int*);

fun ptr[9] = {
    straightFlush,
    four,
    fullHouse,
    flush,
    straight,
    three,
    twoPairs,
    onePair,
    highCard
}; 

char* name[] = {
    "straightFlush",
    "four",
    "fullHouse",
    "flush",
    "straight",
    "three",
    "twoPairs",
    "onePair",
    "highCard"
};

int judge() {
    for(int i = 0; i < 9; ++i) {
    #ifndef ONLINE_JUDGE
        cout << i << " " << name[i] << endl;
        cout << "BLACK: " << ptr[i](B) << endl;
        cout << "WHITE: " << ptr[i](W) << endl;
    #endif
        if(ptr[i](B) > ptr[i](W)) return 1;
        if(ptr[i](B) < ptr[i](W)) return -1;
    }
    return 0;
}

int main() {
    init();
    while(input()) {
        switch(judge()) {
            case 1: puts("Black wins."); break;
            case -1: puts("White wins."); break;
            case 0: puts("Tie."); break;
        }
    }
}
