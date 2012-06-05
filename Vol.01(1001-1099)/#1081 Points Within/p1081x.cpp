// New Edition
// Elf
// 2008-1-12 

#include <cmath> 
#include <vector> 
#include <iostream>
using namespace std;

const double PI = 2 * acos(double(0)); 

int main() {
  vector<double> x;
  vector<double> y; 
  int M, N, count = 0;
  while(cin >> M) {
    if(!M) break;
    cin >> N;
    if(count) cout << endl; 
    cout << "Problem " << ++count << ":" << endl; 
    while(x.size()) x.pop_back();
    while(y.size()) y.pop_back();
    while(M--) {
      double tx, ty;
      cin >> tx >> ty; 
      x.push_back(tx);
      y.push_back(ty); 
    }
    x.push_back(x.front());
    y.push_back(y.front());
    while(N--) {
      double px, py;
      cin >> px >> py;
      double angle = 0; 
      for(int i = 0; i < x.size() - 1; i++) {
        double x1, y1, x2, y2;
        x1 = x[i] - px;
        y1 = y[i] - py;
        x2 = x[i + 1] - px;
        y2 = y[i + 1] - py;
        // The Point is on the vertex
        if(x1 == 0 && y1 == 0 || x2 == 0 && y2 == 0) {
          cout << "Within" << endl;
          break;
        }
        double dir = x1 * y2 - x2 * y1;
        double alpha = acos((x1 * x2 + y1 * y2) / 
               sqrt((x1 * x1 + y1 * y1) * (x2 * x2 + y2 * y2))) / PI;
        // The Point is on the edge
        if(dir == 0 && alpha == 1) {
          cout << "Within" << endl;
          break;
        }
        // Other cases
        if(dir > 0) {
          angle += alpha;
        }
        else if(dir < 0) {
          angle -= alpha;
        }
        if(i == x.size() - 2) {
          if(angle < 1 && angle > -1)
            cout << "Outside" << endl;
          else
            cout << "Within" <<endl;
        }
      } 
    }
  } 
} 
