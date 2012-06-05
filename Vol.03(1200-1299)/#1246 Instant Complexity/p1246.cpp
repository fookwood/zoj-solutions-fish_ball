// 1688457 2008-11-03 23:38:06 Accepted  1246 C++ 0 184 呆滞的慢板 

// 计算循环程序的多项式时间复杂度，递归一下即可。 

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int T;
string s;

void add(deque<int>& a, const deque<int>& b) {
    if(a.size() < b.size())
        a.resize(b.size(), 0);
    for(int i = 0; i < b.size(); ++i)
        a[i] += b[i];
}

deque<int> proc(int type) {
    deque<int> now(0);
    int val;
    while(cin >> s >> ws) {
        if(s == "END") break;
        else if(s == "OP") {
            cin >> val;
            add(now, deque<int>(1, val));
        }
        else if(s == "LOOP") {
            if(cin.peek() == 'n') {
                cin >> s >> ws;
                add(now, proc(-1));
            }
            else {
                cin >> val;
                add(now, proc(val));
            }
        }
    }
    if(type == -2) return now;
    else if(type == -1) {
        now.push_front(0);
        return now;
    }
    else {
        for(int i = 0; i < now.size(); ++i)
            now[i] *=  type;
        return now;
    }
}

int main() {
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> s >> ws;
        deque<int> val = proc(-2);
        while(val.size() > 0 && val.back() == 0) val.pop_back();
        printf("Program #%d\n", t);
        printf("Runtime = ");
        if(val.empty()) cout << '0';
        else for(int i = val.size()-1, p = 0; i >= 0; --i) {
            if(val[i] == 0) continue;
            if(p++) putchar('+');
            if(i == 0) printf("%d", val[i]);
            else {
                if(val[i] != 1)
                    printf("%d*", val[i]);
                putchar('n');
                if(i != 1)
                    printf("^%d", i);
            }
        }
        puts("\n");
    }
}
