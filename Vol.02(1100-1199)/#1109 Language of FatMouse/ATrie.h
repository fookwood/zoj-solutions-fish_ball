#include <string>
#include <stack>

template<class val_t>
class ATrie {

    // Trie Node Type, and the root of the Trie.
    struct Node {
        Node* next[16];
        val_t* val;
        int ref_cnt;
        Node(int ref = 0) : val(NULL), ref_cnt(ref) 
            {memset(next, 0, sizeof(next));}
    } *trie;

    static int high(char c) {return c>>4;}
    static int low(char c) {return c&0xf;}

public:
    
    // Constructor.
    ATrie() {trie = new Node();}

    // Returns a node where locates at the key string position.
    val_t* find(const char* key, int len = -1) {
        Node* tmp1 = trie;
        Node* tmp2;
        if(len == -1) len = strlen(key);
        for(int pos = 0; pos < len; ++pos) {
            tmp2 = tmp1->next[high(key[pos])];
            if(tmp2 == NULL) return NULL;
            tmp1 = tmp2;
            tmp2 = tmp1->next[low(key[pos])];
            if(tmp2 == NULL) return NULL;
            tmp1 = tmp2;
        }
        return tmp1->val;
    }

    // Insert a value into a key position, return whether it was done.
    //      (unless it had been a val there)
    bool insert(const char* key, val_t val, int len = -1) {
        Node* tmp1 = trie;
        Node* tmp2;
        if(len == -1) len = strlen(key);
        for(int pos = 0, sub; pos < (len<<1); ++pos) {
            sub = pos % 2 ? low(key[pos>>1]) : high(key[pos>>1]);
            tmp2 = tmp1->next[sub];
            if(tmp2 != NULL) tmp1 = tmp2;
            else {
                tmp1->next[sub] = new Node();
                tmp1->ref_cnt += 1;
                tmp1 = tmp1->next[sub];
            }
        }
        if(tmp1->val) return false;
        else {
            tmp1->val = new val_t(val);
            tmp1->ref_cnt += 1;
        }
        return true;
    }

    // Remove a key string from the trie, return whether it was done.
    //      (unless it does not exist such a key)
    bool remove(const char* key, int len = -1) {
        Node* tmp1 = trie;
        Node* tmp2;
        Node* start_node = trie;
        int start_pos = 0;
        if(len == -1) len = strlen(key);
        for(int pos = 0, sub; pos < (len<<1); ++pos) {
            sub = pos % 2 ? low(key[pos>>1]) : high(key[pos>>1]);
            tmp2 = tmp1->next[sub];
            if(tmp2 != NULL) {
                if(tmp1->ref_cnt > 1) {
                    start_node = tmp1;
                    start_pos = pos;
                }
                tmp1 = tmp2;
            }
            else return false;
        }
        if(tmp1->val == NULL) return NULL;
        tmp1->ref_cnt -= 1;
        delete tmp1->val;
        tmp1->val = NULL;
        if(tmp1->ref_cnt == 0) {
            tmp1 = start_node;
            for(int pos = start_pos, sub; pos < (len<<1); ++pos) {
                sub = pos % 2 ? low(key[pos>>1]) : high(key[pos>>1]);
                tmp2 = tmp1->next[sub];
                tmp1->next[sub] = NULL;
                tmp1->ref_cnt -= 1;
                if(tmp1->ref_cnt == 0)
                    delete tmp1;
                tmp1 = tmp2;
            }
            delete tmp1;
        }
        return true;
    }

    // Clear all the keys and values in the trie.
    void clear() {
        Node* tmp;
        std::stack<Node*> stk;
        stk.push(trie);
        while(!stk.empty()) {
            tmp = stk.top();
            stk.pop();
            for(int i = 0; i < 16; ++i)
                if(tmp->next[i])
                    stk.push(tmp->next[i]);
            if(tmp->val) delete tmp->val;
            delete tmp;
        }
        trie = new Node();
    }
    
    // Reload version for the C++ string type.
    val_t* find(std::string key) {
        return find(key.c_str(), key.length());
    }
    bool insert(std::string key, val_t val) {
        return insert(key.c_str(), val, key.length());
    }
    bool remove(std::string key) {
        return remove(key.c_str(), key.length());
    }


    // Destructor.
    ~ATrie() {clear();}

};