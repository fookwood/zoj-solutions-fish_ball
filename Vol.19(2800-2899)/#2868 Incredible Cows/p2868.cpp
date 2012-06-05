// 2865026 2008-04-23 22:32:39 Accepted 2868 C++ 00:00.67 6516K 呆滞的慢板  

// 超超经典的题，枚举 + 二分
// 先转化问题，求一堆数里面总和最接近 half 的值
// 思路：直接 DP，每次增加一个元素，求出所有可能的和 
// 这样的时空效率是 2^n，MLE + TLE
// 然后转换思路，将这堆数一分为二之后，分别生成所有可能的和
// 然后枚举第一份，二分搜索第二份
// 这样的复杂度：空间 m = 2^(n/2)，时间 m log m 
// 这样的操作用 set 实现正好合适

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    vector<int> cow, temp, cow1, cow2;
    set<int> val1, val2;
    int     T,  N,  total, half;
    cin >> T;
    while( T-- ) {
        cow.clear();
        total = 0;
        cin >> N;
        for( int i = 0; i < N; i++ ) {
            int  num;
            cin >> num;
            cow.push_back( num );
            total += num;
        }
        half = total / 2;
        
        set<int>::iterator iter, ptr;
        
        val1.clear();
        val1.insert( 0 );
        val2.clear();
        val2.insert( 0 );
        
        for( int i = 0; i < N / 2; ++i ) {
            temp.clear();
            for( iter = val1.begin(); iter != val1.end(); ++iter )
                temp.push_back( *iter + cow[i] );
            for( int j = 0; j < temp.size(); ++j )
                if( temp[j] <= half )
                    val1.insert( temp[j] );
                else    break;
        }

        for( int i = N / 2; i < cow.size(); ++i ) {
            temp.clear();
            for( iter = val2.begin(); iter != val2.end(); ++iter )
                temp.push_back( *iter + cow[i] );
            for( int j = 0; j < temp.size(); ++j )
                if( temp[j] <= half )
                    val2.insert( temp[j] );
                else    break;
        }
        
        int minimum = half;
        for( iter = val1.begin(); iter != val1.end(); ++iter ) {
            int remain = half - *iter;
            ptr = val2.upper_bound( remain );
            --ptr;


            if( remain - *ptr < minimum )
                minimum = remain - *ptr;
        }

        cout << total - 2 * ( half - minimum ) << endl;

    }
}
