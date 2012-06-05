// POJ AC
// 二叉树后序遍历得到结果
// ZOJ 的数据不一样，这个程序假设的前提是每个树都用括号括住两个节点
// 也就是不会有 (ABC) 这类情况，ZOJ 的估计就有这种数据
// 要改变建树方式，才能过 ZOJ 

#include <iostream>
using namespace std;

struct Node {
    Node( Node* p = NULL, int x = 0, int y = 0 ) : 
        parent(p), x(x), y(y), left(NULL), right(0) {}
    int     x,  y;
    Node*   parent;
    Node*   left;
    Node*   right;
};

inline bool isLeaf( Node* const ptr ) {
    return ptr -> left == NULL && ptr -> right == NULL;
}

int eval( Node* const ptr ) {
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

void postOrder(Node*root){
    if(root){ postOrder(root->left);
    postOrder(root->right);
        cout<< root -> x<<' '<< root -> y<<endl;
    }
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
    Node*   root;
    Node*   current;
    
    while( cin >> oper ) {
        
        if( oper.length() == 1 ) {
            cout << 0 << endl;
            continue;
        }
        
        current = root = new  Node();
        
        for( int i = 0; i < oper.length() - 1; i++ ) {
            switch( oper[i] ) {
                // 产生新的儿子节点，并转到左儿子节点 
                case '(':
                    current -> left = new Node( current );
                    current -> right = new Node( current );
                    current = current -> left;
                break;
                
                // 回到父节点，使得父节点获得值 
                case ')':
                    current = current -> parent;
                    // 如果父节点是左儿子，则转到右节点 
                    if( current == current -> parent -> left )
                        current = current -> parent -> right;
                break;
                
                // 获得赋值 
                default:
                    current -> x = X[ oper[i] - 'A' ];
                    current -> y = Y[ oper[i] - 'A' ];
                    // 如果是左节点，赋值后转到右节点 
                    if( current == current -> parent -> left )
                        current = current -> parent -> right;
            }
        }
        int     value = eval( root );
        delete  root;
        if( value < 0 )
            cout << "error" << endl;
        else
            cout << value << endl;
    }
    
}
