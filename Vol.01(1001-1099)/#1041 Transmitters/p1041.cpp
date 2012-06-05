// NEW EDITION
// ELF
// 2008-1-3

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double PI = 2 * asin(double(1));
// return the angle of a vector 
double agl(double xx, double yy) {
  double r = sqrt(xx * xx + yy * yy);
  if(xx >= 0 && yy >= 0)
    return asin(yy / r) / PI;
  if(xx >= 0 && yy < 0)
    return asin(yy / r) / PI + 2;
  if(xx < 0 && yy >= 0)
    return acos(xx / r) / PI;
  if(xx < 0 && yy < 0)
    return 2 - acos(xx / r) / PI;  
  return 0;
}

// judge whether two angles are together
bool jdg(double ag1, double ag2) {
  if(ag1 < 0 || ag1 >= 2 || ag2 < 0 || ag2 >=2)
    return 0;     
  if(ag1 < 1)
    return ag2 >= ag1 && ag2 <= ag1 + 1;
  else
    return ag2 >= ag1 || ag2 <= ag1 - 1;
}

// main
int main() {
  double rx, ry, radius;
  while(cin >> rx >> ry >> radius) {
    if(radius < 0) break;
    int num;
    vector<double> angle;
    cin >> num;
    for(int i = 0; i < num; i++) {
      double x, y;
      cin >> x >> y;
      double xx = x - rx;
      double yy = y - ry;
      if(radius >= sqrt(xx * xx + yy * yy)) {
        angle.push_back(agl(xx, yy));
      }
    }
    int max = 0, count;
    for(int i = 0; i < angle.size(); i++) {
      count = 0;
      for(int j = 0; j < angle.size(); j++) {
        if(jdg(angle[i], angle[j]))
        count++;
      }
      if(count > max) max = count;
    }
    cout << max << endl;;
  } 
} 
