// 2941281 2008-06-04 00:00:18 Accepted 1387 C++ 00:00.95 2188K 呆滞的慢板 

// DP, DP[i] 为 Morse 码前缀 i 串的匹配数
// 建立一个表，记录一个单词 Morse 码累计的个数 M[word]
// 向后扫描，初值 DP[0] = 1
// 假如碰到 DP[i] = 0，跳过
// 如果不是 0 则搜索所有可匹配前缀串，根据乘法原理
// 假设满足要求的前缀为 word
// DP[i + len(word)] += DP[i] * M[word]
// 最终结果为 DP[len(all)], all 为全 Morse 码串 

#include <iostream>
#include <string>
#include <map>
using namespace std;

const char* Morse[] = {
    ".-",   "-...", "-.-.", "-..",
    ".",    "..-.", "--.",  "....",
    "..",   ".---", "-.-",  ".-..",
    "--",   "-.",   "---",  ".--.",
    "--.-", ".-.",  "...",  "-",
    "..-",  "...-", ".--",  "-..-",
    "-.--", "--.."
};

string toCode( const string& word ) {
    string  ans( "" );
    for( int i = 0; i < word.size(); ++i )
        ans += Morse[word[i]-'A']; 
    return  ans;
}

int main() {
    
    string  code,   input;
    
    map<string, int>    M;
    
    int DP[10001],  T,  N,  L,  W;
    
    for( cin >> T; T--; ) {
        
        cin >> code;
        L = code.size();
        
        M.clear();
        fill( DP, DP + L + 1, 0 );
        DP[0] = 1;
        
        for( cin >> W; W--; ) {
            cin >> input;
            ++M[toCode( input )];
        }
        
        map<string, int>::iterator  iter;
        
        for( int i = 0; i < L; ++i ) {
            if( DP[i] ) {
                string  temp = code.substr( i );
                iter = M.upper_bound( temp );
                if( iter != M.begin() )
                while( 1 ) {
                    --iter;
                    if( temp.find( iter -> first ) == 0 ) {
                        DP[i+iter->first.size()] += 
                            DP[i] * iter->second;
                    }
                    if( iter == M.begin() ||
                        iter -> first[0] != temp[0] )
                        break;
                }
            }
        }
        
        cout << DP[L] << endl;
        
    }
    
    
}
