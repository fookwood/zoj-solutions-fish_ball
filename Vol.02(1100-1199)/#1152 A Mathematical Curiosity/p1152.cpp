// 2968741 2008-07-09 21:12:32 Accepted 1152 C++ 00:00.31 836K ´ôÖÍµÄÂı°å 

#include <iostream> 
using namespace std;

int main() {
    
    int T,  N;
    
    for( cin >> T; T--; ) {
    
        int m,  n;
        N = 0;
    
        while( cin >> n >> m ) {
        
            if(n == 0 && m == 0)    break; 
        
            int count = 0; 
      
            for(int i = 1; i < n - 1; i++)
                for(int j = i + 1; j < n; j++)
                    if( ( i * i + j * j + m ) % ( j * i ) == 0 )
                        count++; 
        
      
            cout << "Case " << ++N << ": " << count << endl;
        
        }       
    
        if( T ) cout << endl;
    }
     
} 
