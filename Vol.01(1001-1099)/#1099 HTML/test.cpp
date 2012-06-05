// New Edition
// Elf
// 2008-1-6

#include <iostream>
#include <fstream> 
#include <string> 
using namespace std;
int main() {
  const string hr = "-----------------------------------------"
  "---------------------------------------"; 
  ofstream out("out.txt"); 
  string input;
  int count = 0; 
  while(cin >> input) {
    if(input == "<br>") {
      out << "\n";
      count = 0; 
    } 
    else if(input == "<hr>") {
      if(count) out << "\n" ;
      out << hr << "\n"; 
      count = 0; 
    } 
    else if(count + input.size() + 1 <= 80) {
      if(count) {
        out << " ";
        count ++; 
      } 
      out << input;
      count += input.size(); 
    } 
    else if(count + input.size() + 1 > 80) {
      out << endl;
      count = input.size();
      out << input; 
    }
  } 
  out << endl; 
  out.close(); 
} 
