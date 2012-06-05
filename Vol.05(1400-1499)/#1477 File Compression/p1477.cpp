// 1930558 2009-07-18 14:35:42 Accepted  1477 C++ 200 184 呆滞的慢板 

// 字符串加解密，主要难在解密逻辑。
// 加密的话蛮力解决，但注意排序法则是只看首字符，并且是稳定排序。 
// 解密的话贪心处理：
// 由排序方式可知，排头的字母肯定是字符串排序后得到的。
// 因此对加密串排序，则排序后与排序前的两个串分别是加密最后一步得到的矩阵首列和尾列。
// 称此二序列为 s1 和 s2。 
// 不难分析得到，s2[i] 在明文的后继就是 s1[i]。
// 而且如果给出明文的第一个字符是 c，那么由于排序的稳定性，
// 可以找出这第一个串字符所在的位置就是 pos = s1.find_first_of(c)。
// 而它的前驱则是确定的，就是 s2[i]，而且我知道这时候 s2[i] 是最后一个字符。
// 那么，要找到 s2[i] 实际所在字符串的位置就应该是 pos' = s1.find_last_of(s2[pos])， 
// 因为这个字符是最后的，他在排序之后肯定也要处于同样开头的字符串中的最后。
// 然后将 pos' 代入 pos，重复进行操作。 
// 另：每次从 s1 中查找到一个 pos 之后，必须执行 s1[pos] = ' '，把它擦掉。
// 这样一来，第二次找上去的，就是 "倒数第二个"，如此类推。 

/*
encode YSFHCISYFSBX
decode SHSYFCYIFBXSY

encode TDBBNICNISUMUXNTURBWNMBYUTBCNOFINMIFBYTDTNDYUCTNDFLMSS
decode DBRMTFIBUTTNNOIDNNFMFUNNLBCXWCITTNUIMSSNUYDCSMTYYBUBBDT
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b) {
    return a[0] < b[0];
}

string encode(string str) {
    int N = str.size();
    vector<string> MAT(N);
    for(int i = 0; i < N; ++i) {
        MAT[i] = str;
        str = str.substr(1) + str[0];
    }
    stable_sort(MAT.begin(), MAT.end(), cmp);
    string ans("");
    for(int i = 0; i < N; ++i)
        ans += MAT[i][N-1];
    return ans;
}


string decode(string str) {
    int N = str.size() - 1;
    char c = str[N];
    str.erase(N);
    string seq = str;
    sort(seq.begin(), seq.end());
    int pos = seq.find_first_of(c);
    string ans("");
    for(int i = 0; i < N; ++i) {
        ans = str[pos] + ans;
        seq[pos] = ' ';
        pos = seq.find_last_of(str[pos]);
    }
    return ans;
}

int main() {
    
    string op, str;
    
    while(cin >> op >> str) {
        if(op == "encode")
            puts(encode(str).c_str());
        else
            puts(decode(str).c_str());
    }
    
}
