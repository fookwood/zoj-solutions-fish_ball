// New edition
// elf
// 2008-1-7

#include <iostream>
#include <deque> 
using namespace std; 
 
void rot(string &rotor) {
  deque<int> pswd; 
  for(int i = 0; i < rotor.size(); i++) {
    pswd.push_back(rotor[i] - 'A' - i);
  }
  pswd.push_front(pswd.back());
  pswd.pop_back();
  for(int i = 0; i < pswd.size(); i++) {
    pswd[i] += i;
    if(pswd[i] < 0) pswd[i] += pswd.size();
    if(pswd[i] >= pswd.size()) pswd[i] -= pswd.size();
    rotor[i] = 'A' + pswd[i];
  } 
} 
 
 
 
int main() {
  int N, count = 0;
  string rott[3];
  while(cin >> N) {
    if(N == 0) break;
    else if(count) cout << endl; 
    for(int i = 0; i < 3; i++) {
      cin >> rott[i];
    }   
    cout << "Enigma " << ++count << ":" << endl; 
    int C ;
    cin >> C; 
    while(C--) {
      string temp;
      cin >> temp;
      string rotor[3];
      for(int i = 0; i < 3; i++) {
        rotor[i] = rott[i]; 
      } 
      for(int i = 0; i < temp.size(); i++) {  
        int j; 
        for(j = 0; j < N; j++) {
          if(rotor[2][j] == temp[i]) {
            temp[i] = 'A' + j; 
            break; 
          }
        }
        for(j = 0; j < N; j++) {
          if(rotor[1][j] == temp[i]) {
            temp[i] = 'A' + j; 
            break; 
          }
        }
        for(j = 0; j < N; j++) {
          if(rotor[0][j] == temp[i]) {
            temp[i] = 'a' + j; 
            break; 
          }
        }
        rot(rotor[0]); 
        if(i % N == N - 1) rot(rotor[1]); 
        if(i % (N * N) == (N * N) - 1) rot(rotor[2]); 
      }
      cout << temp << endl; 
    } 
  } 
}
 
