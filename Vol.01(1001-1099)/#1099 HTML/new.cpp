// New Edition
// Elf
// 2008-1-6

#include <iostream>
#include <string> 
using namespace std;
int main() {
  const string hr = "-----------------------------------------"
  "---------------------------------------"; 
  string input;
  int count = 0; 
  while(cin >> input) {
    if(input == "<br>") {
      cout << "\n";
      count = 0; 
    } 
    else if(input == "<hr>") {
      if(count) cout << "\n" ;
      cout << hr << "\n"; 
      count = 0; 
    } 
    else if(count + input.size() + 1 <= 80) {
      if(count) {
        cout << " ";
        count ++; 
      } 
      cout << input;
      count += input.size(); 
    } 
    else if(count + input.size() + 1 > 80) {
      cout << endl;
      count = input.size();
      cout << input; 
    }
  } 
  cout << endl; 
} 
