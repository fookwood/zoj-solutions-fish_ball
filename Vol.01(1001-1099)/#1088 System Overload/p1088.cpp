// PERFORMER: ELF
// DATE: Dec. 17th, 2007
// TITLE: System Overload

// 经典的 Josephe 环模拟
// 模拟即可

// 2927942 2008-05-21 21:12:55 Accepted 1088 C++ 00:00.70 840K 呆滞的慢板 
// Refactored on 2008-5-21 

#include <iostream>
using namespace std;

struct link {
    int     num;
    link*   next;
};

link* create( int n ) {
    
    link*   head = new link;
    link*   p = head;
    
    for( int i = 2; i < n; i++ ) {
        p -> num = i;
        p -> next = new link;
        p = p -> next;
    }
    
    p -> num = n;
    p -> next = head;
    
    return  head;

}

int remove( link* &p, int n ) {
    
    link*   node;
    
    for( int i = 1; i < n - 1; ++i )
        p = p -> next;
        
    node = p -> next -> next;
    
    delete p -> next;
    
    p = p -> next = node;
    
    return( p != p -> next );

}

int main() {
    
    int cnt;
  
    while( ( cin >> cnt ) && cnt ) {
    
        for( int j = 2; ; j++ ) {
            
            link*   root = create( cnt );
        
            while( remove( root, j  ) );
            
            if( root -> num == 2 ) {
                cout << j << endl;
                break;
            }
            
            delete  root;
            
        }
        
    }

}
