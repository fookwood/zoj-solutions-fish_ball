// 2958957 2008-06-30 21:38:35 Accepted 2731 C++ 00:00.10 860K 呆滞的慢板 

// 先模拟，模拟到当前要杀掉 Josephus 的时候停止
// 然后，假设剩下 x 个，那么用 J 函数求出 x - 1 剩下最后一个的编号是多少
// 假设 x - 1 个杀到最后第 y 个存活，就应该杀掉一个人，
//     使得 Josephus 在杀了他之后位于第 y 的位置
// 那么，假设模拟结束的时候剩下 L 个，指针指着 Josephus
// 要将 Jpsephus 放到该位置，就应该将指针后移 x - J(x-1, n) - 1
// 这时指针指着的就是该杀的人 

#include <iostream>
#include <list>
using namespace std;

int J( int n, int k ) {
    
    int s = 0;
    
    for ( int i = 2; i <= n; i++ )
        s = ( s + k ) % i;
    
    return  s;
    
}

int main() {
    
    int m,  n,  p;
    
    list<int>   L;
    
    while( cin >> m >> n >> p && m ) {
        
        L.clear();
        
        for( int i = 1; i <= m; ++i )
            L.push_back( i );
        
        list<int>::iterator iter = L.begin();

        while( L.size() ) {
            
            for( int n1 = ( n - 1 ) % L.size(); n1--; ) {
                if( ++iter == L.end() )
                    iter = L.begin();
            }
            
            if( *iter == p )    break;

            iter = L.erase( iter );

            if( iter == L.end() )
                iter = L.begin();

        }
        
        if( L.size() == 1 ) {
            cout << p << endl;
            continue;
        }
        
        int x = L.size() - J( L.size() - 1, n ) - 1;
        
        for( int i = 0; i < x; ++i ) {
            if( ++iter == L.end() )
                iter = L.begin();
        }
        
        cout << *iter << endl;
        
    }
    
}
