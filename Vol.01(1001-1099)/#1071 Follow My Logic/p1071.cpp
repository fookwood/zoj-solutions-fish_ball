// 1783477 2009-03-09 22:43:34 Accepted  1071 C++ 0 184 呆滞的慢板 

// 恶心模拟题，到了什么程度了捏？看看下面！一个晚上，一道题交出了所有的错误。。
 
/*
1783477 2009-03-09 22:43:34 Accepted  1071 C++ 0 184 呆滞的慢板 
1783474 2009-03-09 22:41:45 Presentation Error  1071 C++ 0 184 呆滞的慢板 
1783470 2009-03-09 22:40:16 Runtime Error  1071 C++ 0 0 呆滞的慢板 
1783465 2009-03-09 22:35:18 Memory Limit Exceeded  1071 C++ 0 32769 呆滞的慢板 
1783464 2009-03-09 22:34:25 Memory Limit Exceeded  1071 C++ 0 32769 呆滞的慢板 
1783451 2009-03-09 22:20:42 Output Limit Exceeded  1071 C++ 0 0 呆滞的慢板 
1783446 2009-03-09 22:17:47 Output Limit Exceeded  1071 C++ 0 0 呆滞的慢板 
1783443 2009-03-09 22:15:47 Output Limit Exceeded  1071 C++ 0 0 呆滞的慢板 
1783442 2009-03-09 22:15:39 Output Limit Exceeded  1071 C++ 0 0 呆滞的慢板 
1783429 2009-03-09 22:04:46 Segmentation Fault  1071 C++ 0 0 呆滞的慢板 
1783416 2009-03-09 21:58:53 Segmentation Fault  1071 C++ 0 0 呆滞的慢板 
1783415 2009-03-09 21:57:58 Output Limit Exceeded  1071 C++ 0 0 呆滞的慢板 
*/

// 算法：从 ? 开始，跟着路径往前走，碰到 o 记录一次反转； 
// 碰到 ) 和 > 插入一个节点，然后构造二叉树； 
// 构造完之后再读入字符串后序求值就行了，中间处理细节做得想吐。 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LogicGraph {

    vector<string> G;

    int Rows() const {
        return G.size();
    }

    int Cols(int row) const {
        return G[row].size();
    }

    bool Inside(int row, int col) {
        return row >= 0 && row < Rows() &&
               col >= 0 && col < Cols(row);
    }
       
    struct TreeNode {
        bool flip;
        enum { AND = 1, OR = 0 } type;
        char val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() :
            flip(false), val('?'),
            left(NULL), right(NULL), type(OR) {}
    };

    pair<int, int> track(int x, int y, bool& flip) {
//cout << "x = " << x << ", y = " << y << endl;
//system("pause");
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        if(G[x][y] == 'o') flip ^= true;
        for(int d = 0; d < 4; ++d) {
            if(G[x][y] == '-' && (d == 2 || d == 3)) continue;
            if(G[x][y] == '|' && (d == 0 || d == 1)) continue;
            x += dx[d];
            y += dy[d];
            if(Inside(x, y)) {
                if(d > 1 && G[x][y] == '|' ||
                   d <= 1 && G[x][y] == '-' ||
                   G[x][y] == '+') {
                    G[x-dx[d]][y-dy[d]] = ' ';
                    return track(x, y, flip);
                }
                else if(G[x][y] == 'o') {
                    G[x][y] = '+';
                    flip ^= true;
                    G[x-dx[d]][y-dy[d]] = ' ';
                    return track(x, y, flip);
                }
                else if(G[x][y] == ')' || G[x][y] == '>' || isalpha(G[x][y])) {
//{cout<<"found: x = " << x<< ", y = " << y << endl;
                    
                    G[x-dx[d]][y-dy[d]] = ' ';
                    return make_pair(x, y);
                }
//}
            }
            x -= dx[d];
            y -= dy[d];
        }
        while(1) puts("OLE!!");
    }

    static void Destroy(TreeNode* ptr) {
        if(ptr == NULL) return;
        Destroy(ptr->left);
        Destroy(ptr->right);
        delete ptr;
    }

    void TraceInto(int x, int y, TreeNode* node) {
//cout << "x = " << x << ", y = " << y << endl;
//for(int i = 0; i < Rows(); ++i) puts(G[i].c_str());
//cout << "G[x][y] = " << G[x][y] << endl;
//system("pause");
        if(isalpha(G[x][y])) {
            node->val = G[x][y];
            return;
        }
        else {
            node->type = G[x][y] == ')' ? TreeNode::AND : TreeNode::OR;
            pair<int, int> pos;
            node->left = new TreeNode;
            pos = track(x - 1, y - 3, node->left->flip);
            TraceInto(pos.first, pos.second, node->left);
            node->right = new TreeNode;
            pos = track(x + 1, y - 3, node->right->flip);
            TraceInto(pos.first, pos.second, node->right);
        }
    }

    TreeNode* root;

    void Build(int bx, int by, bool flip) {
        root = new TreeNode;
        root->flip = flip;
        TraceInto(bx, by, root);
    }

    bool Evaluate(TreeNode* node, const string& s) {
        if(node->left == NULL && node->right == NULL)
            return (s[node->val-'A'] - '0') ^ node->flip;
        else {
            if(node->type == TreeNode::AND)
                return (Evaluate(node->left, s) && Evaluate(node->right, s)) ^ node->flip;
            if(node->type == TreeNode::OR)
                return (Evaluate(node->left, s) || Evaluate(node->right, s)) ^ node->flip;
        }
        //while(1) {new int[1000];}
        return 9999;
    }


public:

    LogicGraph() : G(0), root(NULL) {}

    bool ReadGraph() {
        G.clear();
        for(string s; ;){
            if(!getline(cin, s)) return false;
            if(s == "*") return true;
            G.push_back(s);
        }
    }

    void BuildTree() {
        int bx, by;
        for(int i = 0; i < Rows(); ++i) {
            for(int j = 0; j < Cols(i); ++j) {
                if(G[i][j] == '?') {
                    bx = i;
                    by = j;
                }
            }
        }
//cout << "x = " << bx << ", y = " << by << endl;
        Destroy(root);
        root = NULL;
        bool flip = false;
        pair<int, int> pos = track(bx, by, flip);
//cout << "px = " << pos.first << ", py = " << pos.second << endl;
        Build(pos.first, pos.second, flip);
    }

    bool Evaluate(const string& s) {
        return Evaluate(root, s);
    }

    void output(TreeNode* nd) {
        cout << "flip = " << nd->flip;
        cout << ", val = " << nd->val;
        cout << ", type = " << (nd->type==TreeNode::AND?"AND":"OR") << endl;
        if(nd->left) output(nd->left);
        if(nd->right) output(nd->right); 
    }
    
    void output() {output(root);}

};


int main() {
//    freopen("ooo.txt", "w",stdout);
    int c = 0;
    while(true) {
        LogicGraph obj;
        if(!obj.ReadGraph()) break;
        if(c++) puts("");
        obj.BuildTree();
//system("pause");
//        obj.output();
        for(string s; getline(cin, s) && s != "*";)
            cout << obj.Evaluate(s) << endl;
//        string s;getline(cin, s);
    }
}
