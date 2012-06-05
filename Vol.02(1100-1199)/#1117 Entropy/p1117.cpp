// 1666078 2008-10-14 18:13:20 Accepted  1117 C++ 0 184 ´ôÖÍµÄÂı°å 

// ¾­µäÌ°ĞÄ£¬¹ş·òÂü±àÂë¡£ 

#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> V;

struct Node {
    int len;
    Node* right;
    Node* left;
    Node(int x = 0) : 
        len(x), right(NULL), left(NULL) {}
};

class Op {
public:
    bool operator()(Node* const lhs, Node* const rhs) {
        return lhs->len > rhs->len;
    }
};

priority_queue<Node*, vector<Node*>, Op> Q;

int dfs(Node* p, int level) {
    if(!p) return 0;
    if(p -> left || p -> right)
        return dfs(p->left, level + 1) +
            dfs(p->right, level + 1);
    else return p->len * level;
}

void destroy(Node* p) {
    if(!p) return;
    destroy(p->left);
    destroy(p->right);
    delete p;
}

int main() {
    int C[128];
    string s;
    while(getline(cin, s) && s != "END") {
        memset(C, 0, sizeof(C));
        for(int i = 0; i < s.size(); ++i)
            C[s[i]] += 1;
        for(int i = 1; i < 128; ++i)
            if(C[i]) Q.push(new Node(C[i]));
        Node *x, *y, *z;
        while(!Q.empty()) {
            x = Q.top();
            Q.pop();
            if(Q.empty()) break;
            y = Q.top();
            Q.pop();
            z = new Node(x->len+y->len);
            z -> left = x;
            z -> right = y;
            Q.push(z);
        }
        int p = dfs(x, 0), q = 8 * s.size();
        if(x->left == NULL && x->right == NULL) p = x -> len;
        destroy(x);
        printf("%d %d %.1lf\n", q, p, double(q)/p);
    }
}
