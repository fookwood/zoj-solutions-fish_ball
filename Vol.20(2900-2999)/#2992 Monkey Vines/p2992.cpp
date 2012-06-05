// 2955002 2008-06-22 22:20:03 Accepted 2992 C++ 00:00.00 860K 呆滞的慢板 

// 树形搜索，其实肯定有用一个栈搞定的办法，不想想了，直接作个树模拟 

// 用树搞的办法是，构造一个空二叉树（光有结构没有内容的）
// 然后用函数 weight 后序遍历
// 如果 weight 是空，返回 1
// 否则，递归左右子数求出其权值，取其最大者的两倍返回
// 最后的返回值就是该子树的权值

// 构造树的时候，先建立最外层一个节点，当前指针指向这个节点 
// 忽略最外的括号，如果是前括号，往下拓展一个节点
//  （如果左子树空则左子树先建节点，当前指针指向左子树，否则是右子树） 
// 如果是后括号，指针指向他的父亲 

// 最后，记得销毁树（当然也可以任之内存泄漏）

// 还有，当输入空串的时候结果为 1 

#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node*   left;
    Node*   right;
    Node*   parent;
    Node( Node* p ) : parent( p ),
        left( NULL ), right( NULL ) {}
};

int weight( Node* ptr ) {
    
    if( !ptr )  return 1;
    
    int x = weight( ptr -> left ),
        y = weight( ptr -> right );
    
    return  ( x < y ) ? 2 * y : 2 * x;
    
}

void destroy( Node* ptr ) {
    
    if( ptr -> left )
        destroy( ptr -> left );
        
    if( ptr -> right )
        destroy( ptr -> right );
        
    delete  ptr;
    ptr = NULL; 
    
}
    
int main() {
    
    int     T;
    string  S;
    
    cin >> T;
    getline( cin, S );
    
    for( int t = 1; t <= T; ++t ) {
        
        getline( cin, S );
        cout << t << ' ';
        
        if( S == "" ) {
            puts( "1" );
            continue; 
        }        
        
        Node*   root = new Node( NULL );
        Node*   ptr = root;
        
        for( int i = 1; i + 1 < S.size(); ++i ) {
            if( S[i] == '[' ) {
                if( !ptr -> left ) {
                    ptr -> left = new Node( ptr );
                    ptr = ptr -> left;
                }
                else {
                    ptr -> right = new Node( ptr );
                    ptr = ptr -> right;
                }
            }
            else    ptr = ptr -> parent;
        }
        
        cout << weight( root ) << endl;

        destroy( root );
        
    }
    
}
