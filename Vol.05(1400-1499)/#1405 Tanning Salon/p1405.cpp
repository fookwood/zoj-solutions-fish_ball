#include <iostream>
using namespace std;

int main() {
    int	N;
    string	s;
    int	A[26];
    while( cin >> N ) {
        if( !N ) break;
        int	count = 0; 
        for( int i = 0; i < 26; i++ )	A[i] = 0; 
        cin >> s;
        for( int i = 0; i < s.size(); i++ ) {
            if( A[s[i] - 'A'] == 0 ) {
                if( N ) {
                    N--;
                    A[s[i] - 'A'] = 1; 
                }
                else {
                    count++;
                    A[s[i] - 'A'] = -1;
                }
            }
            else if( A[s[i] - 'A'] == 1 ) N++;
        } 
        if( !count )  cout << "All customers tanned successfully.\n";
        else          cout << count << " customer(s) walked away.\n";
    }
} 
