#include <string>
#include <stack>

template<class val_t>
class Trie {

    // Trie Node Type, and the root of the Trie.
    struct Node {
        Node* next[256];
        Node() {memset(next, 0, sizeof(next));}
    } *trie;

public:

    // Constructor.
    Trie() {trie = new Node();}

    // Returns a node where locates at the key string position.
    val_t* find(const char* key) {
        Node* tmp_node = trie;
        char* key_next = key;
        while(*key_next) {
            if(tmp_node->next[*key_next] == NULL)
                return NULL;
            else {
                tmp_node = tmp_node->next[*key_next];
                key_next += 1;
            }
        }
        return (val_t*)tmp_node->next['\0'];
    }

    // Insert a value into a key position, return whether it was done.
    //      (unless it had been a val there)
    bool insert(const char* key, val_t val) {
        Node *tmp_node = trie;
        char* key_next = key;
        while(*key_next) {
            if(tmp_node->next[*key_next] == NULL)
                tmp_node->next[*key_next] = new Node();
            tmp_node = tmp_node->next[*key_next];
            key_next += 1;
        }
        if(tmp_node->next['\0']) return false;
        tmp_node->next['\0'] = (Node*)new val_t(val);
        return true;
    }
    
    // Remove a key string from the trie, return whether it was done.
    //      (unless it does not exist such a key)
    bool remove(const char* key) {
        Node* tmp_node = trie;
        char* key_next = key;
        std::stack<Node*> stk;
        while(*key_next) {
            if(tmp_node->next[*key_next] == NULL)
                return false;
            tmp_node = tmp_node->next[*key_next];
            key_next += 1;
            stk.push(tmp_node);
        }
        if(tmp_node->next['\0'] == NULL) return false;
        delete (val_t*)tmp_node->next['\0'];
        tmp_node->next['\0'] = NULL;
        bool finished = false;
        while(!stk.empty() && !finished) {
            tmp_node = stk.top();
            stk.pop();
            tmp_node->next[*key_next] = NULL;
            for(int i = 0; i < 256; i++)
                finished = finished || (tmp_node->next[i] != NULL);
            if(!finished) {
                delete tmp_node;
                key_next -= 1;
            }
        }
        return true;
    }

    // Clear all the keys and values in the trie.
    void clear() {
        Node* tmp_node = trie;
        std::stack<Node*> stk;
        stk.push(trie);
        while(!stk.empty()) {
            tmp_node = stk.top();
            stk.pop();
            if(tmp_node->next[0])
                delete (val_t*)tmp_node->next[0];
            for(int i = 1; i < 256; i++)
                if(tmp_node->next[i])
                    stk.push(tmp_node->next[i]);
            delete tmp_node;
        }
        trie = new Node();
    }

    // Reload version for the C++ string type.
    val_t* find(std::string key) {
        return find(key.c_str());
    }
    bool insert(std::string key, val_t val) {
        return insert(key.c_str(), val);
    }
    bool remove(std::string key) {
        return remove(key.c_str());
    }


    // Destructor.
    ~Trie() {clear();}

};