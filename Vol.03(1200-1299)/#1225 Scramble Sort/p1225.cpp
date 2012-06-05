// 善用输入输出流，善用 STL
// 2840130 2008-04-12 16:06:34 Accepted 1225 C++ 00:00.00 888K 呆滞的慢板  

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

int toNum;
string  t;

bool isNum( const string& istr ) {
    istringstream   ss( istr );
    ss >> toNum;
    return  ss.eof();
}

bool icmp( string s1, string s2 ) {
    for( int i = 0; i < s1.size(); i++ )
        s1[i] = tolower( s1[i] );
    for( int i = 0; i < s2.size(); i++ )
        s2[i] = tolower( s2[i] );    
    return  s1 < s2;
}

int main() {
    vector<bool>    type;
    vector<int>     num;
    vector<string>  str;
    vector<string>  all;
    string  temp;

    while( 1 ) {
        type.resize( 0 );
        num.resize( 0 );
        str.resize( 0 );
        all.resize( 0 );
        while( cin >> temp ) {
            all.push_back( temp.substr( 0, temp.length() - 1 ) );
            if( isNum( all.back() ) ) {
                type.push_back( true );
                num.push_back( toNum );
            }
            else {
                type.push_back( false );
                str.push_back( all.back() );
            }
            if( temp[temp.length()-1] == '.' )    break;
        }
        if( all.size() == 1 && all[0] == "" )   break;
        sort( num.begin(), num.end() );
        sort( str.begin(), str.end(), icmp );
        int x = 0,  y = 0;
        for( int i = 0; i < type.size(); i++ ) {
            if( type[i] )
                cout << num[x++];
            else
                cout << str[y++];
            if( i == type.size() - 1 )
                cout << ".\n";
            else
                cout << ", ";
        }
    }
}
