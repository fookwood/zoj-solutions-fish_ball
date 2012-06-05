// New Edition 
// Elf
// 2008-1-6

// Refactored on 2008-5-21

#include <vector> 
#include <iostream>
using namespace std; 

struct Exon {
    
    int index,  prev,   count;
    int xx,     yy;

    Exon( int pv = -1, int cnt = 1, int x = 0, int y = 0 ) :
        prev(pv), count(cnt), xx(x), yy(y) {}

}; 


int main() {

    int N;
    
    while( ( cin >> N ) && N ) {
        
        vector<Exon> set;
        int index = 1;
        while( N-- ) {
            
            Exon temp;
            
            cin >> temp.xx >> temp.yy;
            
            temp.index = index++;
            
            set.push_back(temp);
        
        }
        
        for( int i = set.size() - 1; i > 0; i-- ) {
        
            for( int j = 0; j < i; j++ ) {
        
                if( set[j].xx > set[j + 1].xx ) {
                    Exon temp = set[j];
                    set[j] = set[j + 1];
                    set[j + 1] = temp;
                }
        
            }
        
        }
    
        for( int i = 1; i < set.size(); i++ ) {
            int max = 0;
            for( int j = i - 1; j >= 0; j-- ) {
                if( set[j].yy < set[i].xx ) {
                    if( set[j].count > max ) {
                        set[i].prev = j;
                        max = set[j].count;
                    }
                }
            }
            if( set[i].prev >= 0 )
                set[i].count = set[set[i].prev].count + 1;
        }
        
        vector<int> result;
        
        while( result.size() ) result.pop_back();
        
        int max = 0, pt;
    
        for( int i = 1; i < set.size(); i++ ) {
            if( set[i].count > max ) {
                pt = i;
                max = set[i].count;
            }
        }
        
        while(set[pt].count > 1) {
            result.push_back( set[pt].index );
            pt = set[pt].prev;
        }
        
        result.push_back( set[pt].index );
    
        for( int i = result.size() - 1; i >= 0; i-- ) {
            cout << result[i];
            if( i ) cout << " ";
        }
    
        cout << endl;
    
    }

} 
