// 3015629 2008-07-31 18:55:41 Accepted 1978 C++ 00:00.36 1100K ´ôÖÍµÄÂı°å 

#include <iostream>
#include <vector>
using namespace std;

vector<int> A,  B;

int main() {
    
    for( int i = 2; i < 40000; ++i )
        A.push_back( i );
        
    while( A.size() ) {
        B.push_back( A.front() );
        int N = 0;
        for( int i = 1; i < A.size(); ++i )
            if( i % B.back() ) A[N++] = A[i];
        A.resize( N );
    }
    
    int     N;
    while( cin >> N && N )
        cout << B[N-1] << endl;
    
}
