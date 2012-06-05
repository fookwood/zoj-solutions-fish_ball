// New Edition
// elf
// 2008-1-4

#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    int a[200];
    for(int i = 0; i < 200; i++) {
      a[i] = 0;
    }
    while(N--) {
      int x, y;
      cin >> x >> y;
      x = (x - 1) / 2;
      y = (y - 1) / 2;
      if(y < x) {
        int temp = x;
        x = y;
        y = temp;
      }
      for(int i = x; i <= y; i++) {
        a[i] += 10;
      }
    }
    int max = 0;
    for(int i = 0; i < 200; i++) {
      if(a[i] > max) max = a[i];
    }
    cout << max << endl;
  }
} 
