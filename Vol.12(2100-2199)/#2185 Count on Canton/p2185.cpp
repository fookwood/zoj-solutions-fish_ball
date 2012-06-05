// 2925845 2008-05-20 23:39:48 Accepted 2185 C++ 00:00.00 844K 呆滞的慢板 

// 把规律找出来，不难，注意题目描述，是 S 型向下数，因此注意奇偶 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int index,  num,  rem;
    
    while( cin >> index ) {
    
        num = int( sqrt( 2.0 * index ) ) - 1;
        
        while( num * ( num + 1 ) / 2 < index )
            ++num;
        
        --num;
        
        rem = index - num * ( num + 1 ) / 2;
        
        if( num % 2 )
            printf( "TERM %d IS %d/%d\n", index, rem, num - rem + 2 );
        else
            printf( "TERM %d IS %d/%d\n", index, num - rem + 2, rem );
    }
    
}
