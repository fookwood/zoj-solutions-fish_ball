// 2887682 2008-05-03 22:04:08 Accepted 1944 C++ 00:00.00 836K 呆滞的慢板 

// 已知树的前序标号以及中序标号，求后序标号
// 递归解决，令 str = inorder，
// 先找出 preorder 中的最早的存在于 str 中的字符
// 这个字符必然在剩余后序表达的最末端
// 将此字符压入后序串，在 preorder 中标记为 0
// 然后令 str 为 inorder 刚才提出元素的右子树，递归调用
// 令 str 为 inorder 刚才提出的元素的左子树，递归调用
// 最后得到的 postorder 串即为所求 

#include <string>
#include <iostream>
using namespace std;

string  pre, in, post;

void getPost( const int& left, const int& right ) {
    
    if( left == right ) return;
    
    int middle;
    for( int i = 0; i < pre.size(); ++i ) {
        if( pre[i] ) {
            middle = -1;
            for( int j = left; j < right; ++j ) {
                if( in[j] == pre[i] ) {
                    middle = j;
                    pre[i] = 0;
                    break;
                }
            }
            if( middle != -1 )
                break;
        }        
    }
    post += in[middle];
    getPost( middle + 1, right );
    getPost( left, middle );
    
}

int main() {
    
    while( cin >> pre >> in ) {
        post.erase();
        getPost( 0, pre.size() );
        int pos = pre.size();
        while( pos-- )
            putchar( post[pos] );
        putchar( '\n' ); 
    }

}
