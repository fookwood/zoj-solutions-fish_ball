// NEW EDITION
// ELF
// 2008-1-3

// Rrefactored on 2008-5-21

#include <iostream>
#include <vector> 
using namespace std;

void pal( int n ) {
    
    vector<int> result; 
    
    for(int i = 2; i <= 16; i++) {
        int temp = n; 
    
        vector<int>* now = new vector<int>; 
    
        while(temp) {
            now -> push_back( temp % i );
            temp /= i; 
        }
    
        bool    flag = true; 
    
        for( int j = 0; j < now->size() / 2; j++ ) {
            if( ( *now)[j] != ( *now)[now->size() - j - 1] ) {
                flag = 0; 
                break;
            } 
        } 
    
        if( flag )
        result.push_back(i); 
    
        delete now; 
  
    }
    
    if(result.size()) {
        cout << " is palindrom in basis";
        for(int i = 0; i < result.size(); i++) {
        cout << " " << result[i]; 
        } 
    }
    
    else    cout << " is not a palindrom";

    cout << endl; 

}
 
int main() {
    
    int n;
    
    while(cin >> n) {
    
        if(n <= 0) break;
    
        cout << "Number " << n;
    
        pal(n); 
    
    }

} 
