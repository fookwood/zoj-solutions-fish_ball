#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int code[128];

void init() {
    memset(code, 0, sizeof(code));
    code['1'] = 1; code['2'] = 2; code['3'] = 3;
    code['4'] = 4; code['5'] = 5; code['6'] = 6;
    code['7'] = 7; code['8'] = 8; code['x'] = 0;
}

class Trie {

    // Trie Node Type, and the root of the Trie.
    struct Node {
        Node* next[9];
        char val;
        Node() : val(0) {memset(next, 0, sizeof(next));}
    } *trie;

    void destroy(Node* tmp) {
        if(tmp == NULL) return;
        for(int i = 0; i < 9; ++i)
            destroy(tmp->next[i]);
        delete tmp;
    }

public:

    // Constructor.
    Trie() {trie = new Node();}

    // Returns a node where locates at the key string position.
    char find(const char* key) {
        Node* tmp = trie;
        for(int i = 0; key[i]; ++i) {
            if(tmp->next[code[key[i]]])
                tmp = tmp->next[code[key[i]]];
            else return -1;
        }
        if(tmp->val) return tmp->val;
        else return -1;
    }

    // Insert a value into a key position, return whether it was done.
    //      (unless it had been a val there)
    bool insert(const char* key, char val) {
        Node* tmp = trie;
        for(int i = 0; key[i]; ++i) {
            if(tmp->next[code[key[i]]] == NULL)
                tmp->next[code[key[i]]] = new Node();
            tmp = tmp->next[code[key[i]]];
        }
        if(tmp->val) return false;
        else {
            tmp->val = val;
            return true;
        }
    }

    // Clear all the keys and values in the trie.
    void clear() {
        destroy(trie);
        trie = new Node();
    }

    // Reload version for the C++ string type.
    char find(std::string key) {
        return find(key.c_str());
    }
    bool insert(std::string key, char val) {
        return insert(key.c_str(), val);
    }

    // Destructor.
    ~Trie() {clear(); delete trie;}

};

int main() {

    init();
    
    for(string s; getline(cin, s);) {
        
        if(s == "") break;
        
        for(int i = 0, j = 0; i < s.size(); ++i)
            if(s[i] != ' ') s[j++] = s[i];

        s.erase(9);
        
        Trie MP;
        queue<string> Q;
        
        MP.clear();
        while(!Q.empty()) Q.pop();
        MP.insert(s, '?');
        Q.push(s);

        while(!Q.empty()) {
            string now = Q.front();
            if(now == "12345678x") break;
            Q.pop();
            int pos = now.find('x');
            if(pos + 3 < 9) {
                swap(now[pos], now[pos+3]);
                if(MP.find(now) == -1) {
                    MP.insert(now, 'u');
                    Q.push(now);
                }
                swap(now[pos], now[pos+3]);
            }
            if(pos - 3 >= 0) {
                swap(now[pos], now[pos-3]);
                if(MP.find(now) == -1) {
                    MP.insert(now, 'd');
                    Q.push(now);
                }
                swap(now[pos], now[pos-3]);
            }
            if(pos % 3 < 2) {
                swap(now[pos], now[pos+1]);
                if(MP.find(now) == -1) {
                    MP.insert(now, 'l');
                    Q.push(now);
                }
                swap(now[pos], now[pos+1]);
            }
            if(pos % 3 > 0) {
                swap(now[pos], now[pos-1]);
                if(MP.find(now) == -1) {
                    MP.insert(now, 'r');
                    Q.push(now);
                }
                swap(now[pos], now[pos-1]);
            }
        }
        
        if(Q.empty()) puts("unsolvable");
        else {
            string now = "12345678x";
            string ans("");
            char c;
            while((c = MP.find(now)) != '?') {
                ans = c + ans;
                int pos = now.find('x');
                switch(c) {
                    case 'u': swap(now[pos], now[pos-3]); break;
                    case 'd': swap(now[pos], now[pos+3]); break;
                    case 'l': swap(now[pos], now[pos-1]); break;
                    case 'r': swap(now[pos], now[pos+1]); break;
                    default: while(1) puts("Fault(OLE): Unexpected trace.");
                }
            }
            cout << ans << endl;
        }

    }
    
}
