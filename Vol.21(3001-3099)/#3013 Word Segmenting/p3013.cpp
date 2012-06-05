// 3061112 2008-09-06 11:18:12 Accepted 3013 C++ 00:01.04 5204K ´ôÖÍµÄÂý°å 

#include <iostream>
#include <vector>
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


Trie trie;

int D,  T,  V;

char    pattern[10];
char    text[4100];
int     DP[4100], PR[4100];

vector<string>  ans;

int main() {

    while( scanf( "%d%d", &D, &T ) != EOF ) {
        
        trie.clear();
        
        for( int i = 0; i < D; ++i ) {
            scanf( "%s", pattern );
            trie.insert( pattern );
        }
        
        V = 0;
        ans.clear();
        while( T-- ) {
            V = 0;
            scanf( "%s", text );
            int L = strlen( text );
            if( L == 0 ) {
                puts( "" );
                continue;
            }
            fill( DP, DP + L + 1, INT_MAX );
            memset( PR, -1, sizeof( PR ) );
            DP[0] = 0;
            for( int i = 0; i < L; ++i ) {
                if( DP[i+1] > DP[i] + 1 ) {
                    DP[i+1] = DP[i] + 1;
                    PR[i+1] = i;
                }
                for( int j = 1; i + j <= L && j <= 8; ++j ) {
                    if( trie.find( text + i, j ) ) {
                        if( DP[i+j] > DP[i] ) {
                            DP[i+j] = DP[i];
                            PR[i+j] = i;
                        }
                    }
                }
            }
            V += DP[L];
            vector<int> v( 0 );
            int pos = L;
            while( PR[pos] )
                v.push_back( pos = PR[pos] );
            string s = text;
            for( int i = 0; i < v.size(); ++i )
                s.insert( v[i], "#" );
            printf( "%d\n", V );
            puts( s.c_str() );
        }
    }

}
