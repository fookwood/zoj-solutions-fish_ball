// NEW EDITION
// ELF
// 2008-1-3

#include <iostream>
using namespace std;
 
int main() {
  int num, a, b;
  cin >> num;
  for(int i = 0; i < num; i++) {
    cin >> a >> b; 
    cout << "Scenario #" << i + 1 << ":" <<endl;
    cout << a * b << ".";
    if(a % 2 == 1 && b % 2 == 1)
      cout << "41\n" << endl;
    else
      cout << "00\n" << endl; 
  } 
}
