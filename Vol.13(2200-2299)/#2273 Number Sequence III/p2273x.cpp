#include <list>
#include <iostream>
using namespace std;

char ans[100000] = {'1'};

char query(int N) {
    if(ans[N]) return ans[N];
    else return ans[N] = query(N-1);
}

int main() {
    freopen("table.cpp", "w", stdout);
    printf("#include <cstdio>\n\nint main() {\n    char* c = \"");
    char S[6];
    list<pair<char, int> > L;
    for(int i = 1; i <= 99999; ++i) {
        sprintf(S, "%d", i);
        for(int j = 0; S[j]; ++j)
            L.push_back(make_pair(S[j], i));
    }
    int rem = L.size();
    for(int k = 0; rem > 1; k = 1 - k) {
        list<pair<char, int> >::iterator it = L.begin(), it2 = it;
        ++it2;
        if(it->second != it2->second)
            ans[it->second] = it->first;
        if(k == 0) ++it;
        while(it != L.end()) {
            it = L.erase(it);
            --rem;
            if(it != L.end()) ++it;
        }
    }
    for(int N = 1; N <= 99999; ++N) cout << query(N);
    puts("\";");
    puts("    int N;\n"
         "    while(scanf(\"%d\", &N) != EOF)\n"
         "        printf(\"%c\\n\", c[N-1]);\n"
         "}");
}
