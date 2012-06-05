// New Edition
// Elf
#include <deque>
#include <string>
#include <iostream>
using namespace std;

struct Point {
    int x, y; 
    Point(int m = 0, int n = 0) :
        x(m), y(n) {}
};

int main() {
    int n;
    while(cin >> n) {
        if(n == 0) break;
        string str; 
        cin >> str;
        bool grid[50][50];
        for(int i = 0; i < 50; i++) {
            for(int j = 0; j < 50; j++) {
                grid[i][j] = 0;
            }
        }
        deque<Point> worm;
        while(worm.size()) worm.pop_back();
        for(int i = 10; i <= 29; i++) {
            grid[24][i] = 1;
            worm.push_back(Point(24, i)); 
        }
        int     move = 0,   flag = 0;
        for(int i = 0; i < str.size(); i++) {
            move++;
            grid[worm.front().x][worm.front().y] = 0;
            worm.pop_front();
            switch(str[i]) {
                case 'W':
                    worm.push_back(Point(worm.back().x, worm.back().y - 1));
                break;
                case 'E':
                    worm.push_back(Point(worm.back().x, worm.back().y + 1));
                break;
                case 'N':
                    worm.push_back(Point(worm.back().x - 1, worm.back().y));
                break;
                case 'S':
                    worm.push_back(Point(worm.back().x + 1, worm.back().y));
            } 
            if( worm.back().x < 0 ||
                worm.back().y < 0 ||
                worm.back().x >= 50 ||
                worm.back().y >= 50 ) {
                flag = 1;
                break;
            }
            else if(grid[worm.back().x][worm.back().y]) {
                flag = 2;
                break;
            }
            else grid[worm.back().x][worm.back().y] = 1;
        }
        switch(flag) {
            case 0:
                cout << "The worm successfully made all "
                     << n <<" moves." << endl;
            break;
            case 1:
                cout << "The worm ran off the board on move "
                     << move << "." << endl;
            break;
            case 2:
                cout << "The worm ran into itself on move "
                     << move << "." << endl;
        }
    } 
}   
