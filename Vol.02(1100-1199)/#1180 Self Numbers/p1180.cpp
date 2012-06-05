#include <vector> 
#include <iostream>
using namespace std; 

int self(int x) {
  int ans = x;
  while(x) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int main() {
  vector<bool> X;
  X.resize(1000001,0);
  for(int i = 1; i <= 1000000; i++) {
    int a = self(i);     
    if(a < 1000000)
      X[a] = 1;
    if(!X[i])
      cout << i << endl;
  }
} 
