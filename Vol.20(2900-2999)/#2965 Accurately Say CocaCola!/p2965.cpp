// 2921749 2008-05-18 20:05:40 Accepted 2965 C++ 00:00.00 840K 呆滞的慢板 

// 简单模拟，ms 题 

#include <iostream>
using namespace std;

bool cocacola( const int& i ) {
    
    return  i % 7 == 0 ||
            i / 100 == 7 ||
            ( i - i / 100 * 100 ) / 10 == 7 ||
            ( i - i / 10 * 10 ) == 7;
    
}

int main() {
    
    int A[200] = { 0 };
    
    int cons = 0;
    int pos = 0;
    
    for( int i = 1; i < 800; ++i ) {
        
        if( cocacola( i ) ) {
            if( cons == 0 ) {
                cons = 1;
                pos = i;
                if( A[1] == 0 )
                    A[1] = pos;
            }
            else {
                if( A[++cons] == 0 )
                    A[cons] = pos;
            }
        }
        else    cons = 0;
        
    }
    
    int T;
    
    for( cin >> T; T--; ) {
        cin >> cons;
        cout << A[cons] << endl;
    }
    
}
