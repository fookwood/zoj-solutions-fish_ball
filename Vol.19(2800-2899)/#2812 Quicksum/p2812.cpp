#include <string> 
#include <iostream>
using namespace std;

int main() {
  string s; 
  while(1) {
    getline(cin, s);
    if(s == "#")
      break;
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
      if(s[i] != ' ')
        sum += (i + 1) * (s[i] - 'A' + 1);
    cout << sum << endl;
  }
} 
