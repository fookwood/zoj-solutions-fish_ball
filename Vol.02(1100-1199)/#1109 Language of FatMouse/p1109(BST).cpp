// BST算法（二叉查找树） 
// average 插入 N*logN 查找 M*logN 
// 如果还TLE就只能用AVL了（高度平衡树） 
// 结果 8.56s AC 了，但肯定不是理想的，仍然可以考虑用 

#include <cstring> 
#include <iostream>
using namespace std;

// Binary search tree 
struct BST {
  BST(): key(word), left(0), right(0) {}
  BST(char *wd) {
    int i = 0; 
    while(*wd)
      word[i++] = *(wd++);
    word[i++] = 0; 
    key = word + i;
    wd++; 
    while(*wd)
      word[i++] = *(wd++);
    word[i] = 0;
  }  
  void output() { cout << key << ' ' << word << endl; } 
  char word[22];
  char* key;
  BST* left;
  BST* right;
};
// 中序显示BST内容 
void inorder(BST* tree) {
  if(tree -> left)
    inorder(tree -> left);
    tree -> output();
  if(tree -> right)
    inorder(tree -> right);
} 
// 搜索关键字串x，返回对应的内容字符串（搜索不到返回0） 
char* search(BST* tree, char* x) {
  while(tree) {
    switch(strcmp(x, tree -> key)) {
      case 0: return tree -> word;
      case 1: tree = tree -> right; break;
      default: tree = tree -> left; 
    }
  }
  return 0; 
}

int main() {
  BST* tree = 0;
  char input[22];
  char temp; 
  while(1) {
    temp = getchar();
    if(temp == '\n')
    break;
    int i = 0, j;
    // 录入字符串 
    while(1) { 
      if(temp == ' ') {
        input[i++] = 0;
        j = i;
      }
      else if(temp == '\n') {
        input[i++] = 0;
        break; 
      }
      else
        input[i++] = temp; 
      temp = getchar(); 
    }  
    // BST插入 
    BST* p = tree; 
    if(!p)
      p = tree = new BST(input); 
    else
      while(1) {
        if(strcmp(input + j, p -> key) == 1)
          if(p -> right == 0) {
            p -> right = new BST(input);
            break; 
          }
          else
            p = p ->right; 
        else
          if(p -> left == 0) {
            p -> left = new BST(input);
            break; 
          }
          else 
            p = p -> left; 
      } 
  }
  // 匹配搜索 
  while(cin >> input) {
    char* op = search(tree, input);
    if(op)
      cout << op << endl;
    else
      cout << "eh" << endl; 
  } 
} 
