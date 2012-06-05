// 2902820 2008-05-10 02:13:19 Accepted 1274 C++ 00:00.01 852K 呆滞的慢板 

// 做这题很需要点音乐背景知识
// 输入三个单音，问这个是什么和弦
// 如果乐理熟悉，那直接 STL 乱搞就行了
// 如果不熟悉，那就不好意思... 

#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {

    map<string, int>    M;
    
    M["B#"] = M["C"]  = 0;
    M["C#"] = M["Db"] = 1;
    M["D"]  =           2;
    M["D#"] = M["Eb"] = 3;
    M["E"]  = M["Fb"] = 4;
    M["E#"] = M["F"]  = 5;
    M["F#"] = M["Gb"] = 6;
    M["G"]  =           7;
    M["G#"] = M["Ab"] = 8;
    M["A"]  =           9;
    M["A#"] = M["Bb"] = 10;
    M["B"]  = M["Cb"] = 11;
    
    string  s[3];
    
    string  table[12] = {  "C", "C#",  "D", "D#",
                           "E",  "F", "F#",  "G",
                          "G#",  "A", "A#",  "B" };
    
    int     val[3], cmp[3];
    
    while( cin >> s[0] >> s[1] >> s[2] ) {
        
        for( int i = 0; i < 3; ++i ) {
            cout << s[i] << ' ';
            s[i][0] = toupper( s[i][0] );
            val[i] = M[s[i]];
        }
        
        sort( val, val + 3 );
        
                sort( val, val + 3 );
        bool    success = false;
        
        for( int i = 0; i < 12; ++i ) {
            cmp[0] = i;
            cmp[1] = ( i + 4 ) % 12;
            cmp[2] = ( i + 7 ) % 12;
            sort( cmp, cmp + 3 );
            if( cmp[0] == val[0] &&
                cmp[1] == val[1] &&
                cmp[2] == val[2] ) {
                success = true;
                cout << "is a " 
                     << table[i]
                     << " Major chord.\n";
                break;
            }
        }

        if( !success ) for( int i = 0; i < 12; ++i ) {
            cmp[0] = i;
            cmp[1] = ( i + 3 ) % 12;
            cmp[2] = ( i + 7 ) % 12;
            sort( cmp, cmp + 3 );
            if( cmp[0] == val[0] &&
                cmp[1] == val[1] &&
                cmp[2] == val[2] ) {
                success = true;
                cout << "is a " 
                     << table[i]
                     << " Minor chord.\n";
                break;
            }
        }

        if( !success )  puts( "is unrecognized." );        
        
    }
    
    
}
