// 1830836 2009-04-12 12:35:16 Accepted  1408 C++ 0 184 呆滞的慢板 

// 数论搜索 + 剪枝，任意符号二进制数的表示还原。要留意数字的极限和输入是负数的情况。

#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long i64;

int T, L;
long long N;
string S, A;
i64 up[65], down[65];

bool dfs(int p, i64 rem, i64 bit, bool sign) {

    /* 输出搜索过程 
        cout << "dfs(" << p << ", " <<
            (sign?"":"-") <<rem << ", " <<
            bit << ")" <<endl;
    //*/
    if(rem == 0) return true;
    if(sign ? rem > up[p] : rem > down[p]) return false;
    
    bool ns;
    i64 nr;
    if(S[p] == 'n') {
        if(sign) {
            ns = true;
            nr = rem + bit;
        }
        else if(!sign && rem > bit) {
            ns = false;
            nr = rem - bit;
        }
        else if(!sign && rem <= bit) {
            ns = true;
            nr = bit - rem;
        }
        //Exception
        else while(1) puts("OLE!! NO.1");
    }
    else {
        if(!sign) {
            ns = false;
            nr = rem + bit;
        }
        else if(sign && rem > bit) {
            ns = true;
            nr = rem - bit;
        }
        else if(sign && rem <= bit) {
            ns = false;
            nr = bit - rem;
        }
        //Exception
        else while(1) puts("OLE!! NO.2");
    }
    A[p] = '1';
    if(dfs(p+1, nr, (bit>>i64(1)), ns)) return true;
    A[p] = '0';

    return dfs(p+1, rem, (bit>>i64(1)), sign);
}

int main() {
    for(cin >> T; T--;) {
        cin >> L >> S >> N;
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        for(int i = 0; i < L; ++i) {
            down[L-i-1] = down[L-i];
            up[L-i-1] = up[L-i];
            if(S[L-i-1] == 'n')
                down[L-i-1] += (i64(1)<<i64(i));
            else if(S[L-i-1] == 'p')
                up[L-i-1] += (i64(1)<<i64(i));
            //Exception
            else while(1) puts("OLE!! No.3");
        }
        /* 输出生成的剪枝数组 
            for(int i = 0; i <= L; ++i)
                cout << up[i] << ' ';
            cout << endl;
            for(int i = 0; i <= L; ++i)
                cout << down[i] << ' ';
            cout << endl;
        //*/
        A = string(L, '0');
        if(!dfs(0, N >= 0 ? N : -N, (i64(1)<<i64(L-1)), N >= 0))
            puts("Impossible");
        else cout << A << endl;
    }
}
