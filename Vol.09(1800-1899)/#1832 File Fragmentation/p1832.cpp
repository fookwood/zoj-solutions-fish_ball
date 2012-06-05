// 3066263 2008-09-11 10:14:32 Accepted 1832 C++ 00:00.00 868K 呆滞的慢板 

// 字符串 DFS，先生成可能的 Pattern，然后回溯法分配。

// 字符串搜索，把一组字符串配对，使得合并之后相同。
// 先对所有串 V[N] 字典序排好序，枚举前缀V[i]，
// 那么必须 V[i] 是 V[i+N/2-1] 的前缀，否则剪掉。
// 然后找到长度能与 V[i] 配对的后缀 V[j]，得到 Pattern，然后 DFS 回溯验证。 

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>  V;
set<string>     S; 

string pattern, str;

bool    B[500];
int     len,    cnt;

bool isPrefix( const string& a, const string& b ) {
    return  a.size() <= b.size() && 
        equal(a.begin(), a.end(), b.begin());
}

bool DFS(int k, int rem) {
    if( rem == 0 ) return  true;
    if( k >= cnt ) return  false;
    if( B[k] || !isPrefix(V[k], pattern) ) return DFS( k+1, rem );
    if( DFS(k+1, rem) ) return  true;
    string  remain = pattern.substr( V[k].size() );
    int p = lower_bound( V.begin(), V.end(), remain ) - V.begin();
    while(B[p] || p==k) p++;
    if( V[p] != remain ) return false;
    B[k] = B[p] = true;
    if( DFS( k+1, rem-1 ) ) return  true;
    B[k] = B[p] = false;
}

int main() {

    while( getline( cin, str ) ) {

        V.clear();
        S.clear();

        len = 0;
        cnt = 0;

        do {
            ++cnt;
            len += str.length();
            V.push_back( str );
        } while( getline( cin, str ) && str != "" );

        len = len * 2 / cnt;

        sort( V.begin(), V.end() );

        for( int i = 0; i + i < cnt; ++i) {
            bool found = false;
            if( !isPrefix(V[i], V[i+cnt/2-1]) ) continue;
            for( int j = 0; j < cnt; ++j ) {
                if( j == i || V[j].size() + V[i].size() != len ) continue;
                pattern = V[i] + V[j];
                if( S.find( pattern ) != S.end() ) continue;
                S.insert( pattern );
                memset( B, 0, sizeof( B ) );
                B[i] = B[j] = true;
                if( DFS(i+1, cnt/2-1) ) {
                    found = true;
                    break;
                }
            }
            if( found ) {
                cout << pattern << endl;
                break;
            }
        }

    }

}
