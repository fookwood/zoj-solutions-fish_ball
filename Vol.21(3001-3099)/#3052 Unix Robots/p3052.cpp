#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int abs(int x) {return x<0 ? -x : x; }

struct Point {
    int x, y;
    Point(int x=0, int y=0)
        : x(x), y(y) {}
};

const Point operator-(const Point& a, const Point& b) {return Point(a.x-b.x, a.y-b.y);}

istream& operator>>(istream& is, Point& p) {return is >> p.x >> p.y;}

// rotate the point in the kth quadrant to the first quadrant.
void rot(Point& p, int k) {
    switch(k) {
        case 0: break;
        case 1: swap(p.x, p.y); break;
        case 2: p.y = -p.y; break;
        case 3: swap(p.x, p.y); p.y = - p.y; break;
    }
}

// return the quadrant index.
int quad(const Point& p) {
    if(p.y >= p.x && p.y >= -p.x) return 0;
    if(p.x >= p.y && p.x >= -p.y) return 1;
    if(p.y <= p.x && p.y <= -p.x) return 2;
    if(p.x <= p.y && p.x <= -p.y) return 3;
    return -1;
}

// p Collides with q, at Position(0, y), on time t.
struct Event{
    int p, q, y, t;
    Event() {}
    Event(int p, int q, int y, int t) :
        p(p), q(q), y(y), t(t) {}
};

bool operator<(const Event& lhs, const Event& rhs) {return lhs.t < rhs.t;}

bool operator==(const Event& lhs, const Event& rhs) {return lhs.t == rhs.t;}

int main() {
    
    vector<Point> R[4], J[4];

    Point C, Rob, Jun;
    
    while(cin >> C) {
        
        // clear all the objects
        for(int i = 0; i < 4; ++i) {
            R[i].clear();
            J[i].clear();
        }
        // get all the object from input.
        int N, M;
        for(cin >> N; N--;) {
            cin >> Rob;
            R[quad(Rob-C)].push_back(Rob-C);
        }
        for(cin >> M; M--;) {
            cin >> Jun;
            J[quad(Jun-C)].push_back(Jun-C);
        }

        // the survive flag.
        bool survive = true;
        
        // for the four quadrant, check whether one of it is invalid.
        for(int i = 0; i < 4; ++i) {
            
            // rotate the objects to the first quadrant.
            for(int j = 0; j < R[i].size(); ++j) rot(R[i][j], i);
            for(int j = 0; j < J[i].size(); ++j) rot(J[i][j], i);

            // Robot survive flag vector.
            vector<bool> B(R[i].size(), false);
            
            // clear the effect of all the junks.
            for(int j = 0; j < J[i].size(); ++j) {
                for(int k = 0; k < R[i].size(); ++k) {
                    Point p = R[i][k] - J[i][j];
                    if(J[i][j].x > 0) {
                        if(p.y >= 0 && p.x == p.y)
                            B[k] = true;
                    }
                    else if(J[i][j].x < 0) {
                        if(p.y >= 0 && p.x == -p.y)
                            B[k] = true;
                    }
                    else if(p.y >= 0 && abs(p.x) <= p.y)
                        B[k] = true;
                }
            }
            
            // Event Queue 
            vector<Event> M(0);
            for(int j = 0; j < R[i].size(); ++j) {
                // Event: the robot who arraved at the origin will collide with itself at that moment.
                M.push_back(Event(j, j, 0, R[i][j].y));
                for(int k = j+1; k < R[i].size(); ++k) {
                    if(R[i][j].y != R[i][k].y) continue;
                    else {
                        M.push_back(
                            Event(
                                j,
                                k, 
                                R[i][j].y-max(abs(R[i][j].x), abs(R[i][k].x)),
                                max(abs(R[i][j].x), abs(R[i][k].x))
                            )
                        );
                    }
                }
            }
            
            // sort the event by the time it occurs.
            sort(M.begin(), M.end());
            
            // When an event occurs. It's valid iff. both of the two object collides are not deleted.
            // If an valid event occurs where y=0, It means 'I' was killed.
            // Otherwise, an collide event will produce an extra junk, and kill some remaining robot.
            for(int t = 0; t < M.size(); ++t) {
                if(B[M[t].p] || B[M[t].q]) continue;
                if(M[t].y == 0) {survive = false; break;}
                B[M[t].p] = B[M[t].q] = true;
                for(int k = 0; k < R[i].size(); ++k) {
                    Point p = R[i][k] - Point(0, M[t].y);
                    if(p.y >= 0 && abs(p.x) <= p.y && R[i][k].y >= R[i][M[t].q].y)
                        B[k] = true;
                }
            }
            if(!survive) break;
        }
        puts(survive ? "YES" : "NO");
    }
    
}
