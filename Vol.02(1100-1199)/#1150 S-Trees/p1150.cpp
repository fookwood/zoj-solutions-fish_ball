// 1707052 2008-11-22 21:45:17 Accepted  1150 C++ 0 184 呆滞的慢板 

// 直接模拟即可。 

#include <iostream>
#include <string>
using namespace std;

int N, T = 1, P[8], Q;
string s, v, p;

int main() {
    while(cin >> N && N) {
        for(int i = 0; i < N; ++i) {
            cin >> v;
            P[i] = atoi(v.c_str()+1)-1;
        }
        printf("S-Tree #%d:\n", T++);
        cin >> p;
        for(cin >> Q; Q--;) {
            cin >> v;
            s = v;
            for(int i = 0; i < N; ++i)
                s[i] = v[P[i]];
            int t = 0;
            for(int i = 0; i < N; ++i) {
                t <<= 1;
                if(s[i] == '1')
                    t += 1;
            }
            putchar(p[t]);
        }
        puts("\n");
    }
}
