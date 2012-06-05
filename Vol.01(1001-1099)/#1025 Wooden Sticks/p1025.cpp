// NEW EDITION
// ELF
// 2008-1-3
// Accepted, But it is nothing but a mess work 
#include <iostream> 
using namespace std;

struct Stick {
  Stick(int m = 0, int n = 0):x(m), y(n), next(0) { }
  int x, y;
  Stick* next; 
  void input() {
    cin >> x >> y; 
    next = 0;
  }
};

void destroy(Stick* &p) {
  Stick *q = p;
  while(p->next) {
    q = p->next;
    delete p;
    p = q;
  }
  delete p;
  p = 0;
}

void disp(Stick* p) {
  while(p->next) {
    cout << "x = " << p->x;
    cout << ",\ty = " << p->y <<endl;
    p = p->next;
  }
}

Stick* largest(Stick* p, Stick q) {
  int xmax = 0, ymax = 0;
  Stick* max = 0;
  while(p->next) {
    if(p->x <= q.x && p->y <= q.y)
    if(p->x > xmax || (p->x == xmax && p->y > ymax)) {
      xmax = p->x;
      ymax = p->y;
      max = p;
    }
    p = p->next;
  }
  Stick* result = 0;
  if(max) {
    result = max->next;
    *max = *result;
    result->x = xmax;
    result->y = ymax;
    result->next = 0;
  }
  return result;
}

int main() {
  int line;
  for(cin >> line; line > 0; line--) {
    Stick* head = new Stick;
    Stick* stk = head;
    head->next = 0;
    int point;
    cin >> point;
    while(point --) {
      stk->input();
      stk->next = new Stick;
      stk = stk->next;
      stk->next = 0;
    }
    bool flag = 1;
    Stick bound(10000, 10000);
    int count = 0; 
    while(flag) { 
      stk = &bound;
      while(stk = largest(head, *stk)) {
        flag = 0; 
      } 
      if(flag = !flag)
        count ++;
    } 
    cout << count << endl; 
  }
} 
