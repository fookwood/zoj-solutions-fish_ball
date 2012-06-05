#include <iostream>
using namespace std;

struct poly {
  int      n;
  bool     x[2000];
    
  void input();
  void output();
  void mul(poly g);
  void rem(poly g);
};

int main() {
  poly     f,      g;
  int      N;    
  cin  >>  N;
  while(N--) {
    f.input();
    g.input();
    f.mul(g);
    g.input();
    f.rem(g);
    f.output();
  }
} 

void poly::input()  {
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> x[i];
}

void poly::output()  {
  cout << n << ' ';
  for(int i = 0; i < n - 1; i++)
    cout << x[i] << ' ';
  cout << x[n - 1] << endl;
}

void poly::mul(poly g) {
  for(int i = n; i < n + g.n; i++)
    x[i] = 0;
  for(int i = n - 1; i >= 0; i--)
    if(x[i])
      for(int j = 1; j < g.n; j++)
        x[i + j] ^= g.x[j];
  n += (g.n - 1);
}

void poly::rem(poly g) {
  bool* p = x;
  while(n >= g.n) {
    for(int j = 0; j < g.n; j++)
      *(p + j) ^= g.x[j];
    while(!*p) { 
        p++;
        n--;
    }
  }
  for(int i = 0; i < n; i++)
    x[i] = *(p + i);
}
