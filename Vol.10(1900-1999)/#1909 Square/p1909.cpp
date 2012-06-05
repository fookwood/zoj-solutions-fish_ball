// 搜索 + 剪枝，很经典的一道题 
// 2861079 2008-04-22 18:18:43 Accepted 1909 C++ 00:00.01 436K 呆滞的慢板 
#include <cstdio>
#include <algorithm>
#include <iterator>
using namespace std;

typedef pair<int, int>  Stick;
int A[3],   L;
Stick   B[20];
Stick* const begin = B;
Stick*  end;

inline bool gt ( const Stick& s1, const Stick& s2 ) {
    return  s1.first > s2.first;
}

// 由于递减的性质，递归的时候必须在原来的 pos 基础上向下发展
// 而不能每次都重头开始搜，这点对效率的提高很重要 
bool DFS( const int& seg, Stick* pos ) {
    Stick*  iter;
    bool    ans = false;
    if( seg == 3 )  return  true;
    if( A[seg] == 0 )  return  DFS( seg + 1, begin );
    // 如果一个段从未放置木棍，放置最大的 
    if( A[seg] == L ) {
        for( iter = begin; iter != end; iter++ )
            if( iter -> second )
                break;
        A[seg] -= iter -> first;
        iter -> second--;
        ans = DFS( seg, iter );
        iter -> second++;
        A[seg] += iter -> first;
        return  ans;
    }
    // 顺序搜索可能放置的木棍 
    for( iter = pos; iter != end; iter++ ) {
        if( iter -> second && iter -> first <= A[seg] ) {
            // 如果一个段剩余的长度一个木棍可以填满，直接填满 
            if( iter -> first == A[seg] ) {
                A[seg] -= iter -> first;
                iter -> second--;
                ans = DFS( seg + 1, begin );
                iter -> second++;
                A[seg] += iter -> first;
                break;
            }
            // 否则，逐个试探 
            else {
                A[seg] -= iter -> first;
                iter -> second--;
                ans = DFS( seg, iter );
                iter -> second++;
                A[seg] += iter -> first;
                if( ans )   break;
            }
        }
    }
    return  ans;
}

int main() {
    int     T,  temp,   n,  pos;
    Stick*  tp;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &n );
        L = 0;
        end = begin;
        // 输入木棍 
        while( n-- ) {
            scanf( "%d", &temp );
            L += temp;
            for( tp = begin; tp != end; tp++ )
                if( tp -> first == temp )
                    break;
            if( tp == end )
                *(end++) = make_pair( temp, 1 );
            else
                tp -> second++;
        }
        // 前置条件判断 
        if( L % 4 != 0 ) {
            puts( "no" );
            continue;
        } 
        L /= 4;
        A[0] = A[1] = A[2] = L;
        sort( begin, end, gt );
        puts( L >= B[0].first && DFS( 0, begin ) ? "yes" : "no" );
    }
}
