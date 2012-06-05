// 写得我好痛苦啊！！ 
// 先字符串处理 + 数据结构，造出来一个任意个儿子的有根树
// 然后转化成图邻接矩阵 
// 然后一个一个删掉，汗啊！！这绝对不是一个最好的解决办法！！
// 2829098 2008-04-07 16:40:23 Accepted 1097 C++ 00:00.04 884K 呆滞的慢板  

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int     value;
    Node*   child;
    Node*   parent;
    Node*   sibling;
    Node( int v = 0, Node* p = NULL, Node* c = NULL, Node* s = NULL ) :
        value(v), parent(p), child(c), sibling(s) {}
    bool isLeaf() { return child == NULL; }
};

string& trim( string& oper ) {
    for( int i = 0; i < oper.length(); ) {
        if( oper[i] == ' ' )
            oper.erase( i, 1 );
        else
            i++;
    }
    return  oper;
}

int toInt( const string& str ) {
    stringstream    ss( str );
    int ans;
    ss >> ans;
    return  ans;
}

Node* build( string oper, Node* parent ) {
    oper.erase( 0, 1 );
    oper.erase( oper.length() - 1 );
    Node*   root = new  Node( toInt( oper ), parent );
    Node*   current = root;
    int     head,   count = 0,  son = 0;
    for( head = 0; head < oper.size() && oper[head] != '('; head++ );
    for( int i = head; i < oper.size(); i++ ) {
        if( oper[i] == '(' )
            count++;
        if( oper[i] == ')' )
            count--;
        if( count == 0 ) {
            if( son++ == 0 ) {
                current -> child = build( oper.substr( head, i - head + 1 ), root );
                current = current -> child;
            }
            else {
                current -> sibling = build( oper.substr( head, i - head + 1 ), root );
                current = current -> sibling;
            }
            head = i + 1;
        }
    }
    return  root;
}

void postOrder( Node* ptr, bool A[][51] ) {
    if( ptr -> child )
        postOrder( ptr -> child, A );
    if( ptr -> sibling )
        postOrder( ptr -> sibling, A );
    if( ptr -> parent ) {
        A[ptr -> value][ptr -> parent -> value] =
        A[ptr -> parent -> value][ptr -> value] = true;
    }
    delete  ptr;
}

int main() {
    string  str;
    bool    A[51][51];
    while( getline( cin, str ) ) {
        Node*   root = build( trim( str ), NULL );
        for( int i = 1; i <= 50; i++ )
            for( int j = 1; j <= 50; j++ )
                A[i][j] = false;
        postOrder( root, A );
        int     n = 0;
        for( int i = 1; i <= 50; i++ )
            for( int j = 1; j <= 50; j++ )
                n += A[i][j];
        n = n / 2 + 1;
        vector<int> ans( 0 );
        for( int v = 1; v < n; v++ ) {
            for( int i = 1; i <= n; i++ ) {
                int     sum = 0;
                int     pos = -1;
                for( int j = 1; j <= n; j++ ) {
                    if( A[i][j] ) {
                        sum++;
                        pos = j;
                    }
                }
                if( sum == 1 ) {
                    ans.push_back( pos );
                    A[i][pos] = A[pos][i] = false;
                    break;
                }
            }
        }
        if( ans.size() == 0 )
            cout << endl;
        else for( int i = 0; i < ans.size(); i++ ) {
            cout << ans[i];
            if( i == ans.size() - 1 )
                cout << endl;
            else
                cout << ' ';
        }
    }
}

