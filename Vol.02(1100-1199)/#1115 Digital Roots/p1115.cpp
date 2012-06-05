#include <cstdio>

struct Digit {
  int x[1000];
  int N; 
  
  bool add(int x);
}; 

bool Digit::add(int y) {
  int div, rem;
  div = (x[0] + y) / 10;
  x[0] = (x[0] + y) % 10;
  if(div) {
    x[N++] = 0;
    int i = 1;
    while(x[i] == 9)
      x[i++] = 0;
    x[i]++;
    if(x[N - 1] == 0)
      N--;
  }
  return N != 1;
}

bool input(Digit& num) {
  num.N = 0;
  char temp; 
  while(temp = getchar()) {
    if(temp != '\n')
      num.x[num.N++] = int(temp - '0');
    else
      break;
  }
  return num.N != 1 || num.x[0] != 0; 
}

int pack(Digit num) {
  Digit temp;
  temp.x[0] = 0;
  temp.N = 1;
  for(int i = 0; i < num.N - 1; i++)
    temp.add(num.x[i]);
  if(temp.add(num.x[num.N - 1]))
    return pack(temp);
  else return temp.x[0];
} 

int main() {
  Digit num; 
  while(input(num))
    printf("%d\n", pack(num));
} 
