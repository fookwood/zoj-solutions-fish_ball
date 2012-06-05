// 修正了建树模式，提高了健壮性，但不知为何仍然 WA 
// 连这样的数据都能过了：()()(A) (ABC)DEF 

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node( Node* left = NULL, Node* right = NULL, int x = 0, int y = 0 ) : 
        left( left ), right( right ), x( x ), y( y ) {}
    int     x,  y;
    Node*   left;
    Node*   right;
};

inline bool isLeaf( Node* const ptr ) {
    return ptr -> left == NULL && ptr -> right == NULL;
}

int eval( Node* const ptr ) {
    if( !ptr )  return  -1;
    if( isLeaf( ptr ) ) return  0;
    // 左/右儿子的累加乘法次数 
    int     cntLeft = 0,  cntRight = 0;
    // 如果左儿子不是叶子
    if( !isLeaf( ptr -> left ) )
        cntLeft = eval( ptr -> left );
    // 如果右儿子不是叶子
    if( !isLeaf( ptr -> right ) )
        cntRight = eval( ptr -> right );
    // 后序处理 
    ptr -> x = ptr -> left  -> x;
    ptr -> y = ptr -> right -> y;
    int     ans = ( ptr -> left -> y == ptr -> right -> x ) ?
                  ( ptr -> x * ptr -> right -> x * ptr -> y ) : -1;
    delete  ptr -> left;
    delete  ptr -> right;
    ptr -> left = NULL;
    ptr -> right= NULL;
    
    if( cntLeft < 0 || cntRight < 0 || ans < 0 )
        return  -1;
    else
        return  ans + cntLeft + cntRight;
}

Node* build( const string& oper, int* X, int* Y ) {

    vector<Node*>       V( 0 );
    
    for( int i = 0; i < oper.length(); i++ ) {
        switch( oper.at( i ) ) {
            
            case '(':
                V.push_back( NULL );
            break;
            
            case ')':
                if( !V.back() ) V.pop_back();
                else {
                    Node*   temp = V.back();
                    V.pop_back();
                    V.pop_back();
                    if( V.size() && V.back() )
                        V.back() = new Node( V.back(), temp );
                    else
                        V.push_back( temp );
                }
            break;
            
            default:
                Node*   temp = new  Node( NULL, NULL, X[oper.at(i)-'A'], Y[oper.at(i)-'A'] );
                if( V.size() && V.back() )
                    V.back() = new  Node( V.back(), temp );
                else
                    V.push_back( temp );
        }
    }
    
    return  V.front();
    
}

int main() {
    
    int     X[26] = {};
    int     Y[26] = {};
    int     N;
    char    C;
    
    cin >> N;
    while( N-- )
        cin >> C >> X[C-'A'] >> Y[C-'A'];

    string  oper;
    
    while( cin >> oper ) {
        
        Node*   root = build( oper, X, Y );
        
        int     value = eval( root );
        
        delete  root;
        
        if( value < 0 )
            cout << "error" << endl;
        else
            cout << value << endl;
    }
    
}
