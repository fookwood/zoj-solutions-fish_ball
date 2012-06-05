// 1773721 2009-03-01 15:31:51 Accepted  3170 C++ 0 184 呆滞的慢板 

// 注意题意说是 BST，因此先读取数字，排序。
// 然后用队列法生成二叉树的结构。
// 然后中序遍历把数字填进去，再后序读出来。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int num;
    Node* left;
    Node* right;
    Node() : num(0), left(NULL), right(NULL) {}
};

void fill(vector<int>& V, Node* p) {
    if(p -> left) fill(V, p -> left);
    p -> num = V.back();
    V.pop_back();
    if(p -> right) fill(V, p -> right);
}

void read(vector<int>& V, Node* p) {
    if(p -> left) read(V, p -> left);
    if(p -> right) read(V, p -> right);
    V.push_back(p -> num);
    delete p;
}

int main() {
    int N, L;
    while(cin >> N) {
        vector<int> V(N);
        for(int i = 0; i < N; ++i)
            cin >> V[i];
        sort(V.begin(), V.end());
        reverse(V.begin(), V.end());
        Node* root = new Node();
        vector<Node*> A(0), B(0);
        B.push_back(root);
        cin >> L;
        for(int level = 1; level < L; ++level) {
            A = B;
            B.clear();
            for(int i = 0, cnt; i < A.size(); ++i) {
                cin >> cnt;
                if(cnt > 0) {
                    A[i] -> left = new Node();
                    if(cnt > 1) B.push_back(A[i] -> left);
                }
                cin >> cnt;
                if(cnt > 0) {
                    A[i] -> right = new Node();
                    if(cnt > 1) B.push_back(A[i] -> right);
                }
            }
        }
        fill(V, root);
        read(V, root);
        for(int i = 0; i < N; ++i) {
            if(i) cout << ' ';
            cout << V[i];
        }
        cout << endl;
    }
}
