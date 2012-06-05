// 3028828 2008-08-09 20:28:42 Accepted 2207 C++ 00:00.00 840K 呆滞的慢板 

// 直接模拟 

#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

char    A[200][6];
char    word[6],  task[6];
int     seq[5];
int     N;

int rank( const char s1[6], const char s2[6] ) {
    int ans = 0;
    for( int i = 0; i < 5; ++i )
        seq[s1[i]-'A'] = i;
    for( int i = 0; i < 5; ++i )
        for( int j = i + 1; j < 5; ++j )
            if( seq[s2[i]-'A'] > seq[s2[j]-'A'] )
                ++ans;
    return  ans;
}

int main() {

    while( cin >> N && N ) {
        
        for( int i = 0; i < N; ++i )
            cin >> A[i];
        
        int     minVal = INT_MAX;
        strcpy( word, "ABCDE" );
        
        do {
            
            int total = 0;
            for( int i = 0; i < N; ++i )
                total += rank( word, A[i] );
            
            if( total < minVal ) {
                minVal = total;
                strcpy( task, word );
            }

        } while( next_permutation( word, word + 5 ) );
        
        cout << task
             << " is the median ranking with value "
             << minVal << ".\n";
        
    }

}
