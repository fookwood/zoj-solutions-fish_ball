// 1788059 2009-03-13 22:51:21 Accepted  1766 C++ 0 184 呆滞的慢板 

// 简单的字符串计数，注意审题：Words consist of the characters {a-z,A-Z,0-9}. Words are separated by whitespace, end-of-line, and punctuation. 

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<string, int> MP;

int cnt = 0;

vector<string> V;

int main() {
    string s;
    while(cin >> s) {
        while(ispunct(s[s.size()-1])) s.erase(s.size()-1);
        while(ispunct(s[0])) s.erase(0, 1);
        for(int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);
        for(int i = 0; i < s.size(); ++i) {
            if(ispunct(s[i])) {
                MP[s.substr(0, i)]++;
                s.erase(0, i + 1);
            }
        }
        MP[s]++;
    }
    for(map<string, int>::iterator it = MP.begin(); it != MP.end(); ++it) {
        if(it->second < cnt) continue;
        if(it->second > cnt) V.clear();
        cnt = it->second;
        V.push_back(it->first);
    }
    sort(V.begin(), V.end());
    cout << cnt << " occurrences" << endl;
    for(int i = 0; i < V.size(); ++i)
        cout << V[i] << endl;
}
