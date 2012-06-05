// 3013007 2008-07-29 21:11:46 Accepted 1913 C++ 00:00.00 840K 呆滞的慢板 

// 博弈，找必输点，过程类似求 gcd 的过程（辗转相除） 
// 例如:
    
// m  n     div     status 
// 24 15    1       lose
// 15 9     1       win
// 9  6     1       lose
// 6  3     2       win
// 3  0     -       lose(initial) 

// m  n     div     status
// 34 12    1       win
// 12 10    1       lose
// 10 2     5       win
// 2  0     -       lose(initial) 

// 算法流程：在辗转相除法的时候，用一个栈储存各个 m / n 的值 
// 最后的位置是 lose_pose，因为已经被对手取光了； 
// 然后往前推，如果一个位置数字 > 1，那么它是 win_pose，
//   因为他可以自由决定对手下一手的位置（取完或剩一个）
// 如果这个位置数字 == 1，那么它是下一个位置的反向。

// 如此倒推回去，可以求出栈空的时候状态值，也就是开始的两个数的 pose 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> V;

int     M,  N,  R;

bool    win;

int main() {
    
    while( cin >> M >> N && M ) {
        
        if( N > M ) swap( N, M );
        V.clear();
        
        while( N ) {
            V.push_back( M / N );
            R = M % N;
            M = N;
            N = R;
        }
        
        V.pop_back();
        win = true;
        while( V.size() ) {
            if( V.back() == 1 )
                win ^= 1;
            else win = true;
            V.pop_back();
        }
       
        puts( win ? "Stan wins" : "Ollie wins" );
        
    }
    
}
