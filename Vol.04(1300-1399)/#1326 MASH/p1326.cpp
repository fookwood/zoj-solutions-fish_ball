// 2907330 2008-05-11 20:24:52 Accepted 1326 C++ 00:00.00 840K 呆滞的慢板 

// 简单模拟，读题认真点就行，用链表操作比较方便 

#include <list>
#include <iostream>
using namespace std;

int main() {
    
    list<int>   L;
    list<int>::iterator iter;
    int     A[20],  pos,    N,  X,  T = 1;

    while( cin >> N >> X ) {
        
        L.clear();
        
        for( pos = 0; pos < 20; ++pos )
            cin >> A[pos];
            
        for( pos = 1; pos <= N; ++pos )
            L.push_back( pos );
            
        cout << "Selection #" << T++ << endl;
            
        iter = L.begin();
        pos = 0;
        while( L.size() > X ) {
            
            for( int i = 1; i < A[pos]; ++i )
                if( ++iter == L.end() )
                    break;
            if( iter != L.end() )
                iter = L.erase( iter );
            if( iter == L.end() ) {
                ++pos;
                iter = L.begin();
            }
        
        }
        
        iter = L.begin();
        cout << *iter;
        while( ++iter != L.end() )
            cout << ' ' << *iter;
            
        cout << endl << endl;

    }
    
}
