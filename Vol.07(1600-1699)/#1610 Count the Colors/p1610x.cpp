// 1866925 2009-05-12 21:41:36 Accepted  1610 C++ 130 184 ´ôÖÍµÄÂý°å 

// Ïß¶ÎÇÐ¸î¹ýµÄ¡£ 

#include <iostream>
#include <deque>
#include <map>
using namespace std;

struct Seg {
    int b, e, c;
    Seg() : c(-1) {}
    Seg(int b, int e, int c) :
        b(b), e(e), c(c) {}
    void get() { scanf("%d%d%d", &b, &e, &c); }
};

bool operator < (Seg x, Seg y) {
    if(x.b < y.b) return true;
    if(x.b > y.b) return false;
    if(x.e < y.e) return true;
    if(x.e > y.e) return false;
    return true;
}

int main() {
    int N;
    deque<Seg> Q;
    while(scanf("%d", &N) != EOF) {
        Q.push_back(Seg());
        for(int i = 0; i < N; ++i) {
            Seg s;
            s.get();
            while(Q.front().c != -1) {
                Seg t = Q.front();
                Q.pop_front();
                if(s.e <= t.b || s.b >= t.e)
                    Q.push_back(t);
                else if(t.b < s.b && t.e > s. e) {
                    Q.push_back(Seg(t.b, s.b, t.c));
                    Q.push_back(Seg(s.e, t.e, t.c));
                }
                else if(t.b < s.b && t.e >= s.b && t.e <= s.e) {
                    Q.push_back(Seg(t.b, s.b, t.c));
                }
                else if(t.b >= s.b && t.b <= s.e && t.e > s.e) {
                    Q.push_back(Seg(s.e, t.e, t.c));
                }
            

            }
            Q.push_back(s);
            Q.push_back(Q.front());
            Q.pop_front();
        }
        Q.pop_back();
        sort(Q.begin(), Q.end());
        
        map<int, int> MP;
        MP.clear();
        MP[Q[0].c] = 1;
        for(int i = 1; i < Q.size(); ++i)
            if(Q[i].c != Q[i-1].c || Q[i].b != Q[i-1].e)
                MP[Q[i].c] += 1;
        Q.clear();
        for(map<int, int>::iterator it = MP.begin(); it != MP.end(); ++it)
            printf("%d %d\n", it->first, it->second);
        puts("");
    }
}
