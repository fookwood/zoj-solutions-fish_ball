// NEW EDITION
// ELF
// 2008-1-3

#include <iostream>
#include <string> 
using namespace std;

#define FINISH 2
// Check a filted grids' perimeter
int perimeter(int grid[22][22], int x, int y) {
  bool xx[21][21] = {}, yy[21][21] = {};
  for(int i = 1; i <= x; i++) {
    for(int j = 1; j <= y; j++) {
      if(grid[i][j] == FINISH) {
        xx[i][j] = !xx[i][j];
        xx[i - 1][j] = !xx[i - 1][j];
        yy[i][j] = !yy[i][j];
        yy[i][j - 1] = !yy[i][j - 1];
      }
    } 
  }
  int result = 0; 
  for(int i = 0; i < 21; i++) {
    for(int j = 0; j < 21; j++) {
      result += xx[i][j];
      result += yy[i][j]; 
    }
  }
  return result;
}
// Set the grid to a next status
bool next(int grid[22][22], int x, int y) {
  bool flag = 0;
  for(int i = 1; i <= x; i++) {
    for(int j = 1; j <= y; j++) {
      if(grid[i][j] == 1)
      if(grid[i][j - 1] == 2 ||
         grid[i - 1][j] == 2 ||
         grid[i][j + 1] == 2 ||
         grid[i + 1][j] == 2 ||
         grid[i + 1][j - 1] == 2 ||
         grid[i - 1][j + 1] == 2 ||
         grid[i + 1][j + 1] == 2 ||
         grid[i - 1][j - 1] == 2 ) {
        grid[i][j] = 2;
        flag = 1;
      }
    }
  }
  return flag;
}
// main
int main(){
  int x, y, a, b;
  int grid[22][22];
  while(cin >> x >> y >> a >> b) {
    if(!(x && y && a && b)) break;
    string temp;
    for(int i = 0; i <= x + 1; i++) {
      if(i != 0 && i != x + 1)
        cin >> temp;
      for(int j = 0; j <= y + 1; j++) {
        if(i == 0 || j == 0 || i == x + 1 || j == y + 1)
          grid[i][j] = 0;
        else
          grid[i][j] = (temp[j - 1] == 'X');
      }
    }
    grid[a][b] = 2;
    while(next(grid, x, y));
    cout << perimeter(grid, x, y) << endl;
  } 
} 


