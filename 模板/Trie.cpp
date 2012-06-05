#include <iostream>
#include <string>
using namespace std;

struct Node {
    bool    val;
    Node*   son[26];
    Node() : val(false) { memset(son, 0, sizeof(son)); }
};

class Trie {
    
    Node* root;
    
    void destroy( Node* n ) {
        if( !n ) return;
        for( int i = 0; i < 26; ++i )
            destroy( n->son[i] );
        delete  n;
    }
    
public:
    
    Trie() : root(NULL) {}
    
    ~Trie() { destroy( root ); }
    
    void clear() {
        destroy( root );
        root = new Node();
    }
    
    void insert( char* s ) {
        Node* n = root;
        for( int i = 0; s[i]; ++i ) {
            if( !n->son[s[i]-'a'] )
                n->son[s[i]-'a'] = new Node();
            n = n->son[s[i]-'a'];
        }
        n->val = true;
    }

    bool find( char* s ) {
        Node* n = root;
        for( int i = 0; s[i]; ++i ) {
            if( !n->son[s[i]-'a'] )
                return  false;
            n = n->son[s[i]-'a'];
        }
        return  n->val;
    }
    
    bool find( char* s, int len ) {
        Node* n = root;
        for( int i = 0; i < len; ++i ) {
            if( !n->son[s[i]-'a'] )
                return  false;
            n = n->son[s[i]-'a'];
        }
        return  n->val;
    }

};
