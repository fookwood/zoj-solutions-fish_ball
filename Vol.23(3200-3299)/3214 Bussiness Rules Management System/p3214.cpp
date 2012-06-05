#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct Rule {
    int priority;
    int index;
    int addtime;
};

void disp(Rule r) {
    cout << "pri: " << r.priority <<
            "  idx: " << r.index <<
            "  adt: " << r.addtime << endl;
}

bool gt(const Rule& lhs, const Rule& rhs) {
    if(lhs.priority > rhs.priority) return true;
    if(lhs.priority < rhs.priority) return false;
    return lhs.addtime > rhs.addtime;
}

int T, M, N, P;
char buf[30];

map<string, Rule> MP;
string HP[10001];
int SZ, TM;

int main() {
    for(scanf("%d", &T); T--;) {
        MP.clear();
        for(scanf("%d", &N); N--;) {
            scanf("%s%d", buf, &P);
            Rule ru;
            ru.index = -1;
            ru.priority = P;
            MP[buf] = ru;
        }
        SZ = TM = 0;
        for(scanf("%d", &M); M--;) {
            scanf("%s", buf);
            if(*buf == 'a') {
                scanf("%s", buf);
                Rule& ru = MP[buf];
                ru.addtime = TM++;
                ru.index = ++SZ;
                HP[ru.index] = buf;
                while(ru.index > 1) {
                    Rule& r2 = MP[HP[ru.index>>1]];
                    if(gt(ru, r2)) {
                        swap(HP[ru.index], HP[ru.index>>1]);
                        swap(ru.index, r2.index);
                    }
                    else break;
                }
            }
            else if(*buf == 'd') {
                scanf("%s", buf);
                Rule& ru = MP[buf];
                if(ru.index == SZ) {
                    ru.index = -1;
                    SZ--;
                    continue;
                } 
                Rule& r2 = MP[HP[SZ--]];
                swap(HP[ru.index], HP[r2.index]);
                r2.index = ru.index;
                ru.index = -1;
                while((r2.index<<1) <= SZ) {
                    // 只有左儿子 
                    if((r2.index<<1) == SZ) {
                        Rule& r3 = MP[HP[r2.index<<1]];
                        if(gt(r3, r2)) {
                            swap(HP[r2.index], HP[r3.index]);
                            swap(r2.index, r3.index);
                        }
                        else break;
                    }
                    // 两个儿子都有
                    else {
                        Rule& r3 = MP[HP[r2.index<<1]];
                        Rule& r4 = MP[HP[(r2.index<<1)+1]];
                        Rule& r5 = gt(r3, r4) ? r3 : r4;
                        if(gt(r5, r2)) {
                            swap(HP[r2.index], HP[r5.index]);
                            swap(r2.index, r5.index);
                        }
                        else break;
                    }
                }
            }
            else if(*buf == 'g') {
            
                if(SZ == 0) {
                    puts("<empty>");
                    continue;
                }
                puts(HP[1].c_str());
                                
                Rule& ru = MP[HP[1]];
                
                if(ru.index == SZ) {
                    ru.index = -1;
                    SZ--;
                    continue;
                } 
                Rule& r2 = MP[HP[SZ--]];
                swap(HP[ru.index], HP[r2.index]);
                r2.index = ru.index;
                ru.index = -1;
                while((r2.index<<1) <= SZ) {
                    // 只有左儿子 
                    if((r2.index<<1) == SZ) {
                        Rule& r3 = MP[HP[r2.index<<1]];
                        if(gt(r3, r2)) {
                            swap(HP[r2.index], HP[r3.index]);
                            swap(r2.index, r3.index);
                        }
                        else break;
                    }
                    // 两个儿子都有
                    else {
                        Rule& r3 = MP[HP[r2.index<<1]];
                        Rule& r4 = MP[HP[(r2.index<<1)+1]];
                        Rule& r5 = gt(r3, r4) ? r3 : r4;
                        if(gt(r5, r2)) {
                            swap(HP[r2.index], HP[r5.index]);
                            swap(r2.index, r5.index);
                        }
                        else break;
                    }
                }
            }
//            cout << "MAP:  ";
//            for(map<string, Rule>::iterator it = MP.begin(); it !=MP.end(); ++it) {
//                cout << "    " ;
//                cout << it->first << ": ";
//                disp(it->second);
//            }
//            cout << "HEAP: "; for(int i = 1; i <= SZ; ++i) cout << HP[i] << ' ';puts("");
//

        }
    }
}
