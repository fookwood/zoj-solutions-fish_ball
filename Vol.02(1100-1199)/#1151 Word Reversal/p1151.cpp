#include <string>
#include <iostream>
using namespace std;

int main() {
  int T, N;
  cin >> T;
  while(T--) {
    cin >> N;
    while(N) {
      string s; 
      cin >> s;
      for(int i = s.size() - 1; i >=0; i--)
        cout << s[i];
      if(getchar() == ' ') cout << " ";
      else { cout << endl; N--; } 
    } 
    if(T) cout << endl; 
  } 
} 
