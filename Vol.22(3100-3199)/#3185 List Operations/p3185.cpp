// 1868812 2009-05-14 15:41:17 Accepted  3185 C++ 0 184 呆滞的慢板 

// 特殊的列表并集差集运算，并集的话直接串接，
// 差集的话将所有右操作列表放到 map 中，然后枚举左操作列表，
// 如果存在于 map 中，删除该 map 中的一个计数，
// 否则，添加到新的列表中，最后将原来的列表替换成新的列表。 

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct List {
    
    vector<string> comp;
    
    bool get() {
        string s;
        cin >> s;
        if(s == ".") return false;
        s = s.substr(1, s.size() - 2);
        comp.clear();
        while(s != "") {
            int pos = s.find_first_of(',');
            if(pos == string::npos) {
                comp.push_back(s);
                s.erase();
            }
            else {
                comp.push_back(s.substr(0, pos));
                s.erase(0, pos + 1);
            }
        }
        return true;
    }
    
    void put() {
        cout << "[";
        int T = 0;
        for(int i = 0; i < comp.size(); ++i) {
            if(T++) cout << ',';
            cout << comp[i];
        }
        cout << "]" << endl;
    }
    
    List sub(const List& rhs) {
        map<string, int> MP;
        for(int i = 0; i < rhs.comp.size(); ++i) {
            MP[rhs.comp[i]]++;
        }
        vector<string> tmp(0);
        for(int i = 0; i < comp.size(); ++i) {
            if(MP[comp[i]]) --MP[comp[i]];
            else tmp.push_back(comp[i]);
        }
        comp = tmp;
        return *this;
    }
    
    List add(const List& rhs) {
        for(int i = 0; i < rhs.comp.size(); ++i) {
            comp.push_back(rhs.comp[i]);
        }
        return *this;
    }
};

int main() {
    List a, b;
    while(a.get()) {
        string ss;
        cin >> ss;
        b.get();
        if(ss == "++") a.add(b).put();
        else a.sub(b).put();
    }

}
