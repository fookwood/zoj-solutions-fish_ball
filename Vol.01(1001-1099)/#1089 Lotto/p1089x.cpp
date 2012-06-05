// PERFORMER: ELF
// DATE: Dec. 20th, 2007
// TITLE: Lotto
#include <iostream>
#include <stack> 
#include <vector>
using namespace std;

int search(vector<int> rem, int num) {
  for(int i = 0; i < rem.size(); i++) {
    if(rem[i] == num)
      return i;
  }
  return -1;
}

void disp(vector<int> rem, vector<bool> status) {
  int count = 0;
  for(int i = 0; i < rem.size(); i++) {
    if(!status[i]) {
      cout << rem[i];
      if(count++ < 5)
        cout << " ";
    }
  }
  cout << endl;
}

int main() {
  int n; 
  cin >> n;
  while(1) {
    if(n <= 0) break;
    int m;
    vector<int> stk; 
    vector<int> rem;
    vector<bool> status;
    for(int i = 0; i < n; i++) {
      cin >> m;
      rem.push_back(m);
      status.push_back(1);
    }
    int index = 0;
    while(1) {
      #ifdef DEBUG       
      for(int i = 0; i < status.size(); i++) {
        cout << status[i] << " ";
      }
      cout << endl;
      system("pause");
      #endif
      // Full, pop
      if(stk.size() == 6) {
        disp(rem, status);
        status[search(rem, stk.back())] = 1;
        stk.pop_back();
      }
      // requires another pop
      else if(index == status.size()) {
        if(!stk.size()) break; // Finish
        int temp = search(rem, stk.back());
        status[temp] = 1;
        stk.pop_back();
        index = temp + 1;
      }
      // can do a push
      else if(status[index]) {
        stk.push_back(rem[index]);
        status[index++] = 0;
      }
      // cannot do a push
      else index++;
    }
    stk.clear();
    rem.clear();
    status.clear();
    cin >> n;
    if(n > 0) cout << endl;
  } 
} 
