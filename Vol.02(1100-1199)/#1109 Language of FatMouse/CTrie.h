#include <string>
#include <stack>

template<class val_t>
class CTrie {

    // Trie Node Type, and the root of the Trie.
    struct Node {
        char ch;
        Node* next; // next character in string.
        Node* list; // next node in a list.
        Node(char c = '\0') : ch(c),
            next(NULL), list(NULL) {}
    } *trie;

public:
    
    // Constructor.
    CTrie() {trie = new Node();}

    // Returns a node where locates at the key string position.
    val_t* find(const char* key) {
        Node* tmp_node = trie;
        const char* key_next= key;
        while(*key_next) {
            while(tmp_node->ch != *key_next) {
                if(tmp_node->list == NULL) return NULL;
                else tmp_node = tmp_node->list;
            }
            tmp_node = tmp_node->next;
            key_next += 1;
        }
        while(tmp_node->ch) {
            if(tmp_node->list == NULL) return NULL;
            else tmp_node = tmp_node->list;
        }
        return (val_t*)tmp_node->next;
    }

    // Insert a value into a key position, return whether it was done.
    //      (unless it had been a val there)
    bool insert(const char* key, val_t val) {
        Node* tmp_node = trie;
        const char* key_next = key;
        while(true) {
            while(tmp_node->ch != *key_next && tmp_node->list != NULL)
                tmp_node = tmp_node->list;
            if(tmp_node->ch == *key_next) {
                if(*key_next) {
                    tmp_node = tmp_node->next;
                    key_next += 1;
                }
                else return false;
            }
            else break;
        }
        tmp_node->list = new Node(*key_next);
        tmp_node = tmp_node->list;
        while(*key_next) {
            key_next += 1;
            tmp_node->next = new Node(*key_next);
            tmp_node = tmp_node->next;
        }
        tmp_node->next = (Node*)new val_t(val);
        return true;
    }

    // Remove a key string from the trie, return whether it was done.
    //      (unless it does not exist such a key)
    bool remove(const char* key) {
        Node* tmp = trie->list;
        Node* tmp_prev = trie;
        Node* first_del = trie->list;
        Node* last_undel = trie;
        const char* key_next = key;
        if(trie->list == NULL || *key == '\0') return false;
        bool finished = false;
        // branch means whether multi-key is in the some level.
        bool branch = true;
        while(!finished) {
            while(tmp->ch != *key_next) {
                if(tmp->list == NULL) return false;
                tmp_prev = tmp;
                tmp = tmp->list;
                branch = true;
            }
            if(branch || tmp->list) {
                last_undel = tmp_prev;
                first_del = tmp;
                branch = false;
            }
            if(*key_next == '\0')
                finished = true;
            else {
                key_next += 1;
                tmp_prev = tmp;
                tmp = tmp->next;
            }
        }
        delete (val_t*)tmp->next;
        tmp->next = NULL;
        if(first_del == last_undel->next)
            last_undel->next = first_del->list;
        else
            last_undel->list = first_del->list;
        tmp = first_del;
        while(tmp) {
            first_del = tmp->next;
            delete tmp;
            tmp = first_del;
        }
        return true;
    }

    // Clear all the keys and values in the trie.
    void clear() {
        if(trie->list == NULL) return;
        Node* tmp_node;
        std::stack<Node*> stk;
        stk.push(trie->list);
        trie->list = NULL;
        while(!stk.empty()) {
            tmp_node = stk.top();
            stk.pop();
            if(tmp_node->ch != '\0')
                stk.push(tmp_node->next);
            else
                delete (val_t*)tmp_node->next;
            if(tmp_node->list != NULL)
                stk.push(tmp_node->list);
            delete tmp_node;
        }
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
    ~CTrie() {clear();}

};