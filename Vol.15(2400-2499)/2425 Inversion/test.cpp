/*
#include <iostream>
#include <queue>
using namespace std;

class HuffmanTree {

    int alphaCnt;
    int alphaFrequency[500000];

    struct Node {
        int frequency;
        Node* left;
        Node* right;
        Node(int x) : frequency(x), left(NULL), right(NULL) {}
    };


    class Cmp {
    public:
        Cmp() {}
        bool operator () (Node* lhs, Node* rhs) {
            return lhs->frequency < rhs->frequency;
        }
    };

    Node* merge(Node* lhs, Node* rhs) {
        Node* ans = new Node(lhs->frequency + rhs->frequency);
        ans->left = lhs;
        ans->right = rhs;
        return ans;
    }

    void destroy(Node* n) {
        if(n == NULL) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

    void countLength(Node* n, int level, int& sum) {
        if(n->left == NULL && n->right == NULL)
            sum += n->frequency * level;
        else {
            countLength(n->left, level + 1, sum);
            countLength(n->right, level + 1, sum);
        }
    }

public:

    bool Read() {
        if(!cin >> alphaCnt) return false;
        for(int i = 0; i < alphaCnt; ++i)
            scanf("%d", alphaFrequency + i);
        return true;
    }

    int CodeLength() {
        priority_queue<Node*, vector<Node*>, Cmp> Q;
        for(int i = 0; i < alphaCnt; ++i)
            Q.push(new Node(alphaFrequency[i]));
        while(Q.size() > 1) {
            Node* lhs = Q.top(); Q.pop();
            Node* rhs = Q.top(); Q.pop();
            Q.push(merge(lhs, rhs));
        }
        Node* root = Q.top(); Q.pop();
        int ans = 0;
        countLength(root, 1, ans);
        destroy(root);
        return ans;
    }

};

HuffmanTree obj;

int main() {

    int T, N;

    for(cin >> T; T--;) {
        obj.Read();
        cout << obj.CodeLength() << endl;
        if(T) puts("");
    }

}
*/