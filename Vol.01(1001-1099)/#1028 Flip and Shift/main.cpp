// New Edition 
// elf
// 2008-1-4

#include <iostream>
using namespace std; 

int main() {
  int n;
  cin >> n;
  for(; n > 0; n--) {
    int m;
    cin >> m;
    if(m % 2 == 1) {
      for(; m > 0; m--) {
        int x;
        cin >> x; 
      } 
      cout << "YES" << endl;
    }
    else {
      int even = 0, odd = 0;
      for(; m > 0; m--) {
        int x;
        cin >> x;
        if(x == 1) {
          if(m % 2 == 0) even++; 
          if(m % 2 == 1) odd++; 
        } 
      }
      if(even - odd < 2 && even - odd > -2) {
        cout << "YES" << endl;
      }
      else cout << "NO" << endl; 
    }
  }
} 
