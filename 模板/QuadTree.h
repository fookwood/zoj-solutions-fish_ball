//////////////////////////////////////////////////////
//                  四叉树模板 v1.0                 //
///////////////////Documentation//////////////////////
//                                                  //
// 1. init:     初始化一个母平面，值为 0;           //
// 2. increase: 增加某个坐标点的值;                 //
// 3. query:    查询一个子平面内点值总和;           // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#include <algorithm>
using namespace std;

struct Node {
    int     xmin, xmax, ymin, ymax;
    int     val;
    Node*   son[4];
    Node( int x1=0, int x2=0, int y1=0, int y2=0 ) :
        xmin(x1), xmax(x2), ymin(y1), ymax(y2), val(0) {
        memset(son, 0, sizeof(son));
    }
};

class QuadTree {

    Node*   root;
    
    void clear(Node* node) {
        if(!node)   return;
        for(int i = 0; i < 4; ++i)
            clear(node->son[i]);
        delete node;
        node = NULL;
    }

public:
    
    QuadTree() : root(NULL) {}

    ~QuadTree() { clear(root); }
    
    void init( int xmin=1, int xmax = 20001,
               int ymin=1, int ymax = 20001 ) {
        clear(root);
        root = new Node( xmin, xmax, ymin, ymax );
    }

    void increase( int x, int y, int val ) {
        Node*   n = root;
        root->val += val;
        while( n->xmax - n->xmin > 1 ||
               n->ymax - n->ymin > 1 ) {
            int cx = n->xmax + n->xmin + 1 >> 1,
                cy = n->ymax + n->ymin + 1 >> 1;
            int k;
            if     ( x < cx  && y < cy  ) k = 0;
            else if( x >= cx && y < cy  ) k = 1;
            else if( x < cx  && y >= cy ) k = 2;
            else if( x >= cx && y >= cy ) k = 3;
            if( !n->son[k] ) {
                switch(k) {
                    case 0: n->son[k] = new Node(n->xmin, cx, n->ymin, cy); break;
                    case 1: n->son[k] = new Node(cx, n->xmax, n->ymin, cy); break;
                    case 2: n->son[k] = new Node(n->xmin, cx, cy, n->ymax); break;
                    case 3: n->son[k] = new Node(cx, n->xmax, cy, n->ymax); break;
                }
            }
            n = n->son[k];
            n->val += val;
        }
    }

    int query( int xmin, int xmax,
               int ymin, int ymax, Node* n ) const {
        if( !n )    return  0;
        if( xmin <= n->xmin && xmax >= n->xmax &&
            ymin <= n->ymin && ymax >= n->ymax )
            return  n->val;
        if( xmin >= n->xmax || xmax <= n->xmin ||
            ymin >= n->ymax || ymax <= n->ymin )
            return  0;
        int ans = 0;
        for( int i = 0; i < 4; ++i )
            ans += query( xmin, xmax, ymin, ymax, n->son[i] );
        return  ans;
    }
    
    int query( int xmin, int xmax, int ymin, int ymax ) {
        return  query( xmin, xmax, ymin, ymax, root );
    }
    
};
