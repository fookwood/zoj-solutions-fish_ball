// 2919254 2008-05-17 10:48:23 Accepted 1710 C++ 00:00.00 836K 呆滞的慢板 

// 简单模拟，但题目有陷阱，注意下面两句话：
 
// 1. The distance lost to fatigue is always 10% of the first 
//        day's climbing distance.
// （每天上升的减小量是一个常数，为第一天的 F % ） 
// 2. The snail never climbs a negative distance. If the fatigue
//        factor drops the snail's climbing distance below zero,
//        the snail does not climb at all that day
// （假如上升量变成负，必须修正为 0） 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    double  H,  U,  D,  F;
    double  now, uu;
    int     day;

    while( ( cin >> H >> U >> D >> F ) && H ) {
        
        day = 0;
        now = 0.0;
        uu = U;
        F = F * U / 100.0;
        
        while( ++day ) {
            now += uu;
            if( now - 1e-6 > H ) {
                cout << "success on day " << day << endl;
                break;
            }
            uu -= F;
            if( uu < 0.0 )
                uu = 0.0;
            now -= D;
            if( now + 1e-6 < 0.0 ) {
                cout << "failure on day " << day << endl;
                break;
            }
        }
        
    }
    
}
