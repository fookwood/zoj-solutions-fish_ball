// 1796610 2009-03-21 15:04:30 Accepted  2684 C++ 0 184 呆滞的慢板 

// 给出一个二叉树，节点要么是叶子，要么有两个儿子。
// 从左到右给出所有相邻儿子之间的路径长度，然后做一次查询，
// 求给定两个儿子之间的路径有多长。 
// 根据给定关系即可构造出整个二叉树，然后 O(N) 求最近公共祖先即可。 

// 具体构造方法：先新增一个节点，然后如果下一个离当前节点距离为 d
// 先走第一步，向父节点走一步，如果父节点没有定义，新增一个。
// 然后走剩下的 d-1 步，按如下优先级走：左->右->父节点； 
// 走完 d-1 步之后到达的节点即为新的叶子。
// 按照这种方法构造出来的树就是所描述的树。

// 第二步是求最近公共祖先，假如查询的两个节点为 x 和 y： 
// 用一个 map 存放指针和一个 int，从 x 上溯到根。
// 中途每一个节点 x' 的指针和到 x 的路径 xi 长放进 map 中。
// 然后从 y 上溯到根：对每一个遍历到的节点 y'，查其是否在 map 中。
// 如果在，结果即为当前 y' 到 y 的路径长 yi + MAP[y']。

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    Node() : left(NULL), right(NULL), parent(NULL) {}
};

int T, N;

Node* current;

vector<Node*> all, leaves;

map<Node*, int> path;

int main() {
    for(cin >> T; T--;) {
        cin >> N;
        current = new Node();
        all.push_back(current);
        leaves.push_back(current);
        for(int i = 1, d; i < N; ++i) {
            cin >> d;
            if(current->parent == NULL) {
                current->parent = new Node();
                current->parent->left = current;
                all.push_back(current->parent);
            }
            current = current->parent;
            for(int j = 1; j < d; ++j) {
                if(current->left == NULL) {
                    current->left = new Node();
                    current->left->parent = current;
                    all.push_back(current->left);
                    current = current->left;
                }
                else if(current->right == NULL) {
                    current->right = new Node();
                    current->right->parent = current;
                    all.push_back(current->right);
                    current = current->right;
                }
                else {
                    if(current->parent == NULL) {
                        current->parent = new Node();
                        current->parent->left = current;
                        all.push_back(current->parent);
                    }
                    current = current->parent;
                }
            }
            leaves.push_back(current);
        }
        int x, y, ans;
        cin >> x >> y;
        path.clear();
        current = leaves[x - 1];
        for(int i = 1; current->parent != NULL; ++i) {
            path[current->parent] = i;
            current = current->parent;
        }
        current = leaves[y - 1];
        for(int i = 1; current->parent != NULL; ++i) {
            if(path.find(current->parent) != path.end()) {
                ans = i + path[current->parent];
                break;
            }
            current = current->parent;
        }
        cout << ans << endl;
        for(int i = 0; i < all.size(); ++i)
            delete all[i];
        all.clear();
        leaves.clear();
    }
}
