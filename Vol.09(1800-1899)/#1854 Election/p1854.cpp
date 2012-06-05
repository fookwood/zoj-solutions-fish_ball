// 2952988 2008-06-20 01:41:19 Accepted 1854 C++ 00:00.07 864K ´ôÖÍµÄÂý°å 

// ²ËÌâ£¬×Öµä

#include <map>
#include <string>
#include <iostream> 
using namespace std; 

int main() {
    
    int M,  N;
    map<string, string> name;
    map<string, int>    ballot;
    map<string, int>::iterator  iter; 
    
    string  s1, s2; 
    
    while( cin >> M ) {
        
        getline( cin, s1 );
    
        name.clear();
        ballot.clear();
        
        while( M-- ) { 
            getline( cin, s1 );
            getline( cin, s2 );
            name[s1] = s2;
            ballot[s1] = 0; 
        } 
        
        int tp, mx = 0, cnt = 0;
        
        for( cin >> N >> ws; N--; ) {
            getline( cin, s1 );
            iter = ballot.find( s1 );
            if( iter != ballot.end() ) {
                tp = ++iter -> second;
                if( tp > mx ) {
                    mx = tp; 
                    cnt = 1;
                    s2 = iter -> first; 
                }
                else if( tp == mx )
                    ++cnt;
            } 
        }
        
        if( cnt != 1 )
            cout << "tie\n";
        else
            cout << name[s2] << endl; 

    } 
    
} 
