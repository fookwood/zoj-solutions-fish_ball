// 2921924 2008-05-18 20:58:23 Accepted 2971 C++ 00:00.11 900K 呆滞的慢板 

// 稍微蘑菇的模拟题，不难搞定，但得费点时间 

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    
    map<string, int>    val;
    
    val["one"]      = 1;
    val["two"]      = 2;
    val["three"]    = 3;
    val["four"]     = 4;
    val["five"]     = 5;
    val["six"]      = 6;
    val["seven"]    = 7;
    val["eight"]    = 8;
    val["nine"]     = 9;
    val["ten"]      = 10;
    val["eleven"]   = 11;
    val["twelve"]   = 12;
    val["thirteen"] = 13;
    val["fourteen"] = 14;
    val["fifteen"]  = 15;
    val["sixteen"]  = 16;
    val["seventeen"]= 17;
    val["eighteen"] = 18;
    val["nineteen"] = 19;
    val["twenty"]   = 20;
    val["thirty"]   = 30;
    val["forty"]    = 40;
    val["fifty"]    = 50;
    val["sixty"]    = 60;
    val["seventy"]  = 70;
    val["eighty"]   = 80;
    val["ninety"]   = 90;
    

    int     T,  ans,    num;
    string  input,  temp;
    vector<string>  V;
    
    for( cin >> T >> ws; T--; ) {
    
        getline( cin, input );
        
        istringstream   is( input );
        V.clear();
        ans = 0;
        
        while( is >> temp ) {
        
            if( temp == "thousand" ||
                temp == "million" ) {
            
                num = 0;
            
                for( int i = 0; i < V.size(); ++i ) {
                    
                    if( V[i] == "hundred" )
                        num *= 100;
                    
                    else if( V[i] == "and" )
                        continue;
                        
                    else num += val[V[i]];
                        
                }
                
                if( temp == "thousand" )
                    ans += 1000 * num;
                else
                    ans += 1000000 * num;
                    
                V.clear();
            
            }
            
            else    V.push_back( temp );
            
        }
        
        num = 0;
            
        for( int i = 0; i < V.size(); ++i ) {
                    
            if( V[i] == "hundred" )
                num *= 100;
                    
            else if( V[i] == "and" )
                continue;
                        
            else num += val[V[i]];
                        
        }
        
        ans += num;
        
        cout << ans << endl;
    
    }
    
}
