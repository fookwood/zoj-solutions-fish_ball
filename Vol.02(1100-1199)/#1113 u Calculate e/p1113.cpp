#include <iostream>
using namespace std;
 
int main() {
  cout.precision(9); 
  cout << "n e\n- -----------\n";
  long double ans = 1, fct = 1;
  for(int i = 0; i < 10; ) {
    if(i > 2) cout.setf(ios::fixed); 
    cout << i << " ";
    cout << ans << endl;
    ans += (fct /= ++i);
  } 
} 
