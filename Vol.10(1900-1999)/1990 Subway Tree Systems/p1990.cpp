#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BT {
    struct Node {
        Node *up, *left, *right;
        Node(Node* up = NULL) : up(up),
            left(NULL), right(NULL) {}
    } *root;
public:
    BT() {root = new BT(NULL);}
    ~BT() {clear();}
};
