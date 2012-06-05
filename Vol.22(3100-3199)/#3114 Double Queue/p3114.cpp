// 1740724 2009-01-10 19:54:04 Accepted  3114 C++ 100 184 呆滞的慢板 

// 双端的堆，用一个 BST 就可以了。 

#include <iostream>
#include <map>
using namespace std;

int main() {
    int N, K, P;
    map<int, int> MP;
    while(scanf("%d", &N) && N) {
        switch(N) {
            case 1:
                scanf("%d%d", &K, &P);
                MP[P] = K;
            break;
            case 2:
                if(MP.empty()) puts("0");
                else {
                    map<int, int>::iterator it = MP.end();
                    --it;
                    printf("%d\n", it->second);
                    MP.erase(it);
                }
            break;
            case 3:
                if(MP.empty()) puts("0");
                else {
                    map<int, int>::iterator it = MP.begin();
                    printf("%d\n", it->second);
                    MP.erase(it);
                }
            break;
        }
    }
}
