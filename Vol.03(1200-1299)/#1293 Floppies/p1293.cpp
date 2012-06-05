// 2905278 2008-05-11 00:25:16 Accepted 1293 C++ 00:00.00 832K 呆滞的慢板 

// 很弱的题，除法，对于不整除者进一处理 

#include <iostream>
using namespace std;

int main() {
    
    int     N,  T = 0;
    
    while( ( cin >> N ) && N ) {
        
        cout << "File #" << ++T << endl;
        
        N = ( N + 1 ) / 2;
        N = N + ( N + 1 ) / 2;
        
        if( N % 62 )    N = N / 62 + 1;
        else            N /= 62;
        
        if( N % 30000 ) N = N / 30000 + 1;
        else            N /= 30000;
        
        cout << "John needs " << N << " floppies.\n" << endl;
        
    }
    
}
