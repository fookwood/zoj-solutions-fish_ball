// 1694274 2008-11-09 17:22:34 Accepted  3056 C++ 70 976 呆滞的慢板 

// 核心就是给一个字典，给一个 key 要找出字典中的正确单词，
// 头尾正确，其他打乱，直接 map 就行，当然最好用 Trie，
// 头尾不变，中间排序作为 key，正确字符串作为 value。 
// 注意一点，头尾字符一定是正确的。 

#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, string> M;

int main() {
    string s, w;
    while(cin >> s && s != "DICTIONARY_DEFINE_OVER") {
        w = s;
        if(w.size() > 2)
        sort(w.begin()+1, w.end()-1);
        M[w] = s;
    }
    getline(cin, s);
    w.erase();
    char c;
    while((c = getchar()) != EOF) {
        if(isalpha(c)) w += c;
        else {
            if(w.size() != 0) {
                if(w.size() > 2)
                    sort(w.begin()+1, w.end()-1);
                cout << M[w];
                w.erase();
            }
            putchar(c);
        }
    }
    cout << w;
}
