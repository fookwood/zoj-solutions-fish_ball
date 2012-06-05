// 2901232 2008-05-09 15:56:40 Accepted 1012 C++ 00:01.16 1528K 呆滞的慢板 

// 4WA...不难的模拟题，就是蘑菇，没读清楚题目就死翘翘了
// 还好有人翻译了重要的几点，剩下就是小心的事情了 

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

struct Run {

    int     A,  B,  T,  U,  V,  W,  X;
    
    void input() { cin >> A >> B >> T >> U >> V >> W >> X; }
};

bool icmp( const Run& r1, const Run& r2 ) {
    return  r1.T < r2.T || r1.T == r2.T && r1.V > r2.V;
}

int main() {

    int     F,  N,  T = 1;
    int     CPU,    MEM,    income;
    
    vector<Run>     all,    running;
    list<Run>       waiting;
    list<Run>::iterator iter;
    
    while( ( cin >> F ) && F ) {
        
        cin >> CPU >> MEM >> N;
        
        all.resize( N );
        for( int i = 0; i < N; ++i )
            all[i].input();
            
        sort( all.begin(), all.end(), icmp );
        income = 0;
        running.clear();
        waiting.clear();
        
        for( int i = 0, pos = 0; i <= F; ++i ) {

            while( !running.empty() ) {
                income += running.back().V;
                if( i < running.back().U )
                    income += ( running.back().U - i ) * running.back().W;
                else
                    income += ( running.back().U - i ) * running.back().X;
                CPU += running.back().A;
                MEM += running.back().B;
                running.pop_back();
            }
            
            if( i == F ) {
                for( iter = waiting.begin(); iter != waiting.end(); ++iter )
                    if( i > iter -> U )
                        income += ( iter -> U - i ) * iter -> X;
                break;
            }
            
            while( pos < N && all[pos].T == i )
                waiting.push_back( all[pos++] );

            for( iter = waiting.begin(); iter != waiting.end(); ) {
                if( CPU >= iter -> A && MEM >= iter -> B ) {
                    running.push_back( *iter );
                    CPU -= iter -> A;
                    MEM -= iter -> B;
                    iter = waiting.erase( iter );
                }
                else    ++iter;
            }
            
        }
        
        cout << "Case " << T++ << ": " << income << endl << endl;
        
    }

}
