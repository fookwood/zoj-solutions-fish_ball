// 3014428 2008-07-30 19:22:11 Accepted 1188 C++ 00:00.03 860K ´ôÖÍµÄÂý°å 

// OOP

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class DNA {
    string  str;
    int     inv;
public:
    void get() {
        inv = 0;
        cin >> str;
        for( int i = 0; i < str.size(); ++i )
            for( int j = i + 1; j < str.size(); ++j )
                inv += ( str[j] < str[i] );
    }
    void put() { cout << str << endl; }
    friend bool operator < ( const DNA& a, const DNA& b ) {
        return  a.inv < b.inv;
    }
};

int main() {
    
    DNA dna[100];
    
    int M,  T;
    
    for( cin >> T; T--; ) {
        cin >> M >> M;
        for( int i = 0; i < M; ++i )
            dna[i].get();
        stable_sort( dna, dna + M );
        for( int i = 0; i < M; ++i )
            dna[i].put();
        if( T ) puts( "" );
    }
    
}
