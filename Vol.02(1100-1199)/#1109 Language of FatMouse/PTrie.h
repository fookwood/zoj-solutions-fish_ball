#include <string>
#include <stack>

template<class val_t>
class PTrie {

    // Trie Node Type, and the root of the Trie.
    struct Node {
        int skip, ref;
        Node* next[256];
        char* sub;
        Node(int sk, char* s) : skip(sk), sub(s), ref(0) {
            memset(next, 0, sizeof(next));
        }
    } *trie;

    // The Ending Node Type.
    struct Obj {
        char* str;
        val_t val;
        Obj(const char* s, val_t v) : val(v),
            str(new char[strlen(s)+1]) {
            strcpy(str, s);
        }
        ~Obj() {delete [] str;}
    };

public:

    // Constructor.
    PTrie() {trie = new Node(0, NULL);}

    void disp(Node* ptr, int level){
        if(ptr == NULL) return;
        for(int i = 0; i < level; ++i) putchar(' ');
        if(ptr->sub) printf("%s: ", ptr->sub);
        else printf("trie: ");
        if(ptr->next[0]) 
            printf("\\0 ");
        for(int i = 1; i < 256; ++i)
            if(ptr->next[i])
                printf("%c ", i);
        printf("\t\t ref = %d", ptr->ref);
        puts("");
        for(int i = 1; i < 256; ++i)
            if(ptr->next[i])
                disp(ptr->next[i], level + ptr->skip);
    }

    void display() {disp(trie, 0);}



    // Returns a node where locates at the key string position.
    val_t* find(const char* key) {
//display();
        Node* tmp = trie;
        int len = strlen(key);
        int pos = 0;
        while(pos < len) {
            tmp = tmp->next[key[pos]];
            if(tmp == NULL) return NULL;
            if(pos + tmp->skip > len) return NULL;
            if(strncmp(key+pos, tmp->sub, tmp->skip) != 0) return NULL;
            pos += tmp->skip;
        }
        tmp = tmp->next['\0'];
        if(tmp == NULL) return NULL;
        return &(reinterpret_cast<Obj*>(tmp)->val);
    }

    // Insert a value into a key position, return whether it was done.
    //      (unless it had been a val there)
    bool insert(const char* key, val_t val) {
        std::stack<Node*> stk;
        Node* tmp = trie;
        stk.push(tmp);
        int len = strlen(key);
        int pos = 0, k;
        while(pos < len) {
            if(tmp->next[key[pos]] == NULL) break;
            Node* last = tmp;
            tmp = tmp->next[key[pos]];
            stk.push(tmp);
            for(k = 0; k < tmp->skip; ++k)
                if(key[pos+k] != tmp->sub[k])
                    break;
            if(k == tmp->skip) {
                pos += k;
                continue;
            }
            else {
                last->next[key[pos]] = new Node(k, tmp->sub);
                last = last->next[key[pos]];
                last->ref = tmp->ref;
                stk.pop();
                stk.push(last);
                tmp->sub += k;
                tmp->skip -= k;
                last->next[tmp->sub[0]] = tmp;
                tmp = last;
                pos += k;
                break;
            }
        }
        if(pos == len) {
            if(tmp->next['\0'] != NULL) return false;
            else tmp->next['\0'] = reinterpret_cast<Node*>(new Obj(key, val));
        }
        else {
            Obj* obj = new Obj(key, val);
            tmp->next[key[pos]] = new Node(len - pos, obj->str + pos);
            tmp = tmp->next[key[pos]];
            stk.push(tmp);
            tmp->next['\0'] = reinterpret_cast<Node*>(obj);
        }
        while(!stk.empty()) {
            tmp = stk.top();
            stk.pop();
            tmp->ref += 1;
        }
        return true;
    }
    
    // Remove a key string from the trie, return whether it was done.
    //      (unless it does not exist such a key)
    bool remove(const char* key) {

        std::stack<Node*> stk;

        Node* tmp = trie;

        stk.push(trie);

        int pos = 0;

        int len = strlen(key);

        while(pos < len) {
            if(tmp->next[key[pos]] == NULL) return false;
            tmp = tmp->next[key[pos]];
            if(len-pos < tmp->skip) return false;
            if(strncmp(key+pos, tmp->sub, tmp->skip) != 0) return false;
            pos += tmp->skip;
            stk.push(tmp);
        }
        if(tmp->next['\0'] == NULL) return false;

        Obj* obj = reinterpret_cast<Obj*>(tmp->next['\0']);
        tmp->next['\0'] = NULL;

        char* buf = NULL;

        while(stk.top() != trie) {

            tmp = stk.top();
            pos -= tmp->skip;
            stk.pop();
            tmp->ref -= 1;


            if(buf == NULL) {

                if(tmp->ref == 0)
                    stk.top()->next[tmp->sub[0]] = NULL;

                if(tmp->ref == 0) delete tmp;

                else {

                    if(tmp->next['\0'] != NULL)
                        buf = reinterpret_cast<Obj*>(tmp->next['\0'])->str + pos;

                    else for(int i = 1; i < 256; ++i) {
                        if(tmp->next[i] != NULL) {
                            buf = tmp->next[i]->sub - tmp->skip;
                            break;
                        }
                    }

                    tmp->sub = buf;

                    if(tmp->ref == tmp->next[tmp->sub[tmp->skip]]->ref) {
                        Node* ptr = tmp;
                        tmp = tmp->next[tmp->sub[tmp->skip]];
                        tmp->skip += ptr->skip;
                        tmp->sub -= ptr->skip;
                        stk.top()->next[tmp->sub[0]] = tmp;
                        delete ptr;
                    }

                }

            }
            
            else {
                buf -= tmp->skip;
                tmp->sub = buf;
//*
                if(tmp->ref == tmp->next[tmp->sub[tmp->skip]]->ref) {
                    Node* ptr = tmp;
                    tmp = tmp->next[tmp->sub[tmp->skip]];
                    tmp->skip += ptr->skip;
                    tmp->sub -= ptr->skip;
                    stk.top()->next[tmp->sub[0]] = tmp;
                    delete ptr;
                }
//*/
            }
        }

        trie->ref -= 1;

        delete obj;
        return true;
    }

    // Clear all the keys and values in the trie.
    void clear() {
        Node* tmp = trie;
        std::stack<Node*> stk;
        stk.push(trie);
        while(!stk.empty()) {
            tmp = stk.top();
            stk.pop();
            if(tmp->next[0])
                delete reinterpret_cast<Obj*>(tmp->next[0]);
            for(int i = 1; i < 256; i++)
                if(tmp->next[i])
                    stk.push(tmp->next[i]);
            delete tmp;
        }
        trie = new Node(0, NULL);
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
    ~PTrie() {clear(); delete trie;}

};
