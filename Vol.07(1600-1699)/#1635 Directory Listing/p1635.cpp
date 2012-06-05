// 2935338 2008-05-28 20:27:19 Accepted 1635 C++ 00:00.00 868K 呆滞的慢板 

// 相当有力的数据结构 + 模拟题，注意模型的建立以及树的处理 

#include <iostream>
#include <string>
#include <deque>
using namespace std;

struct Node {
    
    int     val;
    int     cnt;
    string  name;
    Node*   son[10];
    
    Node( int v = 0, int c = 0, string nm = "" ) :
        val( v ), cnt( c ), name( nm ) {}
    
};

void pre( Node* nd ) {
    cout << nd -> name << ' ' << nd -> val << endl;
    for( int i = 0; i < nd -> cnt; ++i )
        pre( nd -> son[i] );
}

int fix( Node* nd ) {
    for( int i = 0; i < nd -> cnt; ++i )
        nd -> val += fix( nd -> son[i] );
    return  nd -> val;
}

void draw( Node* nd, string head ) {
    for( int i = 0; i < nd -> cnt; ++i ) {
        cout << head;
        printf( "|_%s[%d]\n", 
            nd->son[i]->name.c_str(),
            nd->son[i]->val );
        if( i != nd -> cnt - 1 )
            head += "|       ";
        else
            head += "        ";
        draw( nd -> son[i], head );
        head.erase( head.size() - 8 );
    }
}

void destroy( Node* nd ) {
    for( int i = 0; i < nd -> cnt; ++i )
        destroy( nd -> son[i] );
    delete  nd;
}

int main() {
    
    string  input;
    int     value;

    while( cin >> input >> value >> ws ) {
        
        Node*   root = new Node( value, 0, input );
        Node*   temp;
        
        deque<Node*>    P,  Q;
        Q.clear();
        P.clear();
        P.push_back( root );
        
        // 吃掉前括号 
        getchar();
        
        while( !P.empty() ) {
            
            // 获取一个字段及值 
            cin >> input;
            if( input == ")" )  // 处理空括号的情况 
                P.pop_front();  
            else {
                cin >> value;
            
                // 压入等待通道 
                P.front() -> son[P.front() -> cnt++] =
                    temp = new Node( value, 0, input );

                // 假如是目录，加入下一层通道
                if( input[0] == '*' )
                    Q.push_back( temp );

                // 判别是否结束 
                if( getchar() == ')' )
                    P.pop_front();
                else  continue;
            }

            // 若当前通道已耗尽，替换下一层通道 
            if( P.empty() ) {
                P = Q;
                Q.clear(); 
                if( !P.empty() ) {
                    cin >> ws;
                    getchar();
                }
            }
            else {
                cin >> ws;
                getchar();
            }
            
        }
        
        // 建树完毕，调整节点值 
        fix( root );
        
        // 开始绘制树 
        printf( "|_%s[%d]\n", root->name.c_str(), root->val );
        string  head( 8, ' ' );
        draw( root, head );
        
    }
    
}
