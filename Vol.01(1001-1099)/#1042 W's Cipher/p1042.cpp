// New Edition
// Elf
// 2008-1-6

#include <deque>
#include <string> 
#include <iostream> 
using namespace std; 

int main() {
  int k[3];
  while(cin >> k[0] >> k[1] >> k[2]) {
    if(!k[0] && !k[1] && !k[2]) break;
    string code;
    cin >> code; 
    deque<char> block; 
    deque<int> index;
    for(int n = 0; n < 3; n++) { 
      for(int i = 0; i < code.size(); i++) {
        switch(n) {
          case 0: if(code[i] >= 'a' && code[i] <= 'i') {
                    block.push_back(code[i]); 
                    index.push_back(i);
                  }
                  break; 
          case 1: if(code[i] >= 'j' && code[i] <= 'r') {
                    block.push_back(code[i]); 
                    index.push_back(i);
                  }
                  break;
          case 2: if(code[i] >= 's' && code[i] <= 'z' || code[i] == '_') {
                    block.push_back(code[i]); 
                    index.push_back(i);
                  }                  
        }
      }
      for(int j = 0; j < k[n]; j++) {
        block.push_front(block.back());
        block.pop_back(); 
      }
      for(int i = 0; i < index.size(); i++) {
        code[index[i]] = block[i];
      }
      while(block.size()) block.pop_back(); 
      while(index.size()) index.pop_back();
    }
    cout << code << endl;
  } 
} 
