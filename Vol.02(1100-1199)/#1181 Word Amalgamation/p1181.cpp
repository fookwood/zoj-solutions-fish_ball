// 2902797 2008-05-10 01:33:19 Accepted 1181 C++ 00:00.00 852K 呆滞的慢板 

// 又是一道 STL ms 题... 不说了 

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void disp( const string& str ) {
    cout << str << '\n';
}

int main() {
    
    string  str, key;
    
    map<string, set<string> >    M;
    map<string, set<string> >::iterator iter;
    
    while( ( cin >> str ) && str[0] != 'X' ) {
    
        key = str;
        sort( key.begin(), key.end() );
        M[key].insert( str );
    
    }
    
    while( ( cin >> str ) && str[0] != 'X' ) {
        
        sort( str.begin(), str.end() );
        
        iter = M.find( str );
        if( iter != M.end() )
            for_each( iter -> second.begin(), 
                      iter -> second.end(), disp );
        else    puts( "NOT A VALID WORD" );
        puts( "******" );
    
    }
    
}
