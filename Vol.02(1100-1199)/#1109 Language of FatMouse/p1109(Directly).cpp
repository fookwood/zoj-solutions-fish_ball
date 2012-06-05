// ≤ª≈≈–Ú÷±Ω”À—À˜ 
// Dictionary length: N; Count of cases: M
// O(M*N) 
// 10s TLE 

#include <iostream>
#include <string>
using namespace std;

int main() {
  string key[100005];
  string word[100005];
  int N = 0;
  char temp;
  while(1) {
    temp = getchar();
    if(temp == '\n')
      break;
    do {
      word[N] += temp;
      temp = getchar();
    } while(temp != ' ');
    while(1) {
      temp = getchar();
      if(temp == '\n')
        break;
      else
        key[N] += temp;
    }
    N++;
  }
  string x;
  while(cin >> x) {
    int i;
    for(i = 0; i < N; i++)
      if(x == key[i])
        break;
    if(i == N)
      cout << "eh" << endl;
    else
      cout << word[i] << endl;
  }
}


