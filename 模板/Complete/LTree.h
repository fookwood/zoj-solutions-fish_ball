/////////////////////////////////////////////////
//              左偏树模板 v1.0                //
/////////////////////////////////////////////////
//                                             //
//               Documentation                 //
//                                             //
// ## 该模板类维护一个左偏树实现的可合并堆;    //
//                                             //
// * 模板原型: LTree<class T, class Op>;       //
// 1) T, 堆元素的类型;                         //
// 2) Op, 堆优先的比较准则，二元函数对象;      //
//      默认为 less<T>                         //
//                                             //
// * 支持操作:                                 //
// 1) LTree()，产生一个空左偏树-堆;            //
// 2) LTree( T Elem )，产生一个单节点堆;       //
// 3) LT.size()，返回堆元素个数;               //
// 4) LT.empty()，判空;                        // 
// 5) LT.top()，返回堆顶部元素;     O(1)       //
// 6) LT.pop()，弹出堆顶元素;       O(logn)    // 
// 7) LT.insert(Elem)，插入新元素;  O(logn)    //
// 8) merge(LT1, LT2)，合并两个堆;  O(logn)    //
// 9) LT.clear()，清空当前堆;       O(n)       //
//                                             //
// * 备注:                                     //
// 1) 进行对合并时，输入两个堆引用 LT1，LT2,   //
//    合并结果保存到 LT1，LT2 被置空;          // 
//                                             // 
/////////////////////////////////////////////////
//          2008 CopyRight(c) by elf           //
/////////////////////////////////////////////////

#include <functional>
#include <algorithm>
using namespace std;

/////////////// Inside Node Struct //////////////
//          左偏树结点的内部实现               // 
/////////////////////////////////////////////////
template<class T, class Op = less<T> >
struct Node {
    T   key;
    int dist;
    Node<T, Op>*   L;
    Node<T, Op>*   R;
    // Constructor
    Node() : L( NULL ), R( NULL ) {}
    Node( T k, int d = 0 ) :
        key( k ), dist( d ),
        L( NULL ), R( NULL ) {}
};

template<class T, class Op>
void merge( Node<T, Op>* &A, Node<T, Op>* &B ) {
    
    if( A == NULL ) { swap( A, B ); return; }
    if( B == NULL ) return;
    
    if( Op()( B -> key, A -> key ) )
        swap( A, B );
    merge( A -> R, B );
    
    if( A -> L == NULL ||
        A -> R != NULL &&
        A -> R -> dist >
        A -> L -> dist ) {
        swap( A -> R, A -> L );
    }
    
    if( A -> R == NULL )    A -> dist = 0;
    else   A -> dist = A -> R -> dist + 1;
    
    B = NULL;
    
}

template<class T, class Op>
void destroy( Node<T, Op>* &tree ) {
    if( tree -> L ) destroy( tree -> L );
    if( tree -> R ) destroy( tree -> R );
    delete  tree;
    tree = NULL;
}



////////// Complete Class Declarations //////////
//                左偏树模板类                 // 
/////////////////////////////////////////////////

// Predeclaration For Friend
template<class T, class Op>
class LTree;

template<class T, class Op>
void merge( LTree<T, Op>&, LTree<T, Op>& );

// Class Declarations 
template<class T, class Op = less<T> >
class LTree {
    
    Node<T, Op>*   root;
    size_t  SZ;

public:
    
    T top() const { return root -> key; }
    bool empty() const { return root == NULL; }
    size_t size() const { return SZ; }
    friend void merge<>( LTree<T, Op>&, LTree<T, Op>& );
    void pop();
    void insert( T val );
    
    LTree() : root( NULL ), SZ( 0 ) {}
    LTree( const T& elem ) : SZ( 1 )
        { root = new Node<T, Op>( elem ); }
    void clear() { if( root ) destroy( root ); SZ = 0; }
    ~LTree() { if( root ) destroy( root ); }
    
};



//////// Complete Class Implemtentation /////////
//              左偏树模板类实现               // 
/////////////////////////////////////////////////

// 合并操作 
template<class T, class Op>
void merge( LTree<T, Op>& A, LTree<T, Op>& B ) {
    merge( A.root, B.root );
    A.SZ += B.SZ;
    B.SZ = 0;
}

// 插入节点操作 
template<class T, class Op>
void LTree<T, Op>::insert( T val ) {
    Node<T, Op>* newTree = new Node<T, Op>( val );
    merge( root, newTree );
    ++SZ;
}

// 删除顶部节点操作 
template<class T, class Op>
void LTree<T, Op>::pop() {
    merge( root -> L, root -> R );
    Node<T, Op>* newRoot = root -> L;
    delete  root;
    root = newRoot;
    --SZ;
}


/////////////////////////////////////////////////
//        Copyright(c) 2008 by elf, zzu        // 
/////////////////////////////////////////////////
