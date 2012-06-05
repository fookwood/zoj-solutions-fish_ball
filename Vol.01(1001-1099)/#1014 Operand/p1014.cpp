// New Edition
// Elf
// 2008-1-5

#include <iostream>
#include <string> 
#include <vector>
#include <deque>
using namespace std;

void broke(string &p, int n) {
  vector<int> flag;
  for(int i = 0; i < p.size(); i++)
  { switch(p[i]) {
      case ')': flag.push_back(5); break;
      case '(': flag.push_back(4); break;
      case '^': flag.push_back(3); break;
      case '*': flag.push_back(2); break;
      case '+': flag.push_back(1); break;
      default: flag.push_back(0);
    }
  }
  // Extract the paratheses.
  int para = 0;
  for(int i = 0; i < flag.size(); i++) {
    if(flag[i] == 5) para++;
    if(flag[i] == 4) para--;
    if(para || flag[i] == 5) flag[i] = 0;
  }
  bool allPara = 1;
  for(int i = 0; i < flag.size(); i++) {
    if(flag[i]) {
      allPara = 0;
      break;
    }
  }
  if(allPara) {
    if(flag.size() != 1) {
      p.erase(p.size() - 1, 1);
      p.erase(0, 1);
    }
    return;
  }
  // find the lowest Operand
  int min = 4;
  for(int i = 0; i < flag.size(); i++) {
    if(flag[i] && flag[i] < min)
      min = flag[i];
  }
  // Kill the other
  int count = 1;
  for(int i = 0; i < flag.size(); i++) {
    if(flag[i] == min) count++;
    if(count == n) {
      for(int j = i + 1; j < flag.size() && flag[j]!=min; j++) {
        flag[j] = -1;
      }
      for(int j = i; j >= 0 && flag[j]!=min; j--) {
        flag[j] = -1;
      }
      string sub("");
      for(int k = 0; k < flag.size(); k++) {
        if(flag[k] == -1) sub += p[k];
      }
      p = sub;
      break;
    }
  }
}
// main
int main() {
  string input;
  int count = 0;
  while(cin >> input) {
    char e = input[0];
    if(e == '*') break;
    if(count++ != 0) cout << endl;
    cout << "Expression " << e << ":\n";
    input.erase(0, 3);
    int n;
    cin >> n;
    while(n--) {
      deque<int> oper;
      while(oper.size()) oper.pop_back();
      do {
        int temp;
        cin >> temp;
        oper.push_back(temp);
      } while(getchar() != '\n');
      for(int i = oper.size(); i > 0; i--) {
        cout << "op(";
        cout << oper[i - 1] << ",";
      }
      cout << e;
      for(int i = oper.size(); i > 0; i--)
        cout << ")";
      cout << "=";
      string p = input;
      while(oper.size()) {
        broke(p, oper.front());
        oper.pop_front();
      }
      cout << p << endl;
    }
  } 
} 
