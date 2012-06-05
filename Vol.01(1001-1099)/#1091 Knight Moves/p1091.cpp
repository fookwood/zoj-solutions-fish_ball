// PERFORMER: ELF
// DATE: Dec. 18th, 2007
// TITLE: Knight Moves

// 2928074 2008-05-21 22:23:09 Accepted 1091 C++ 00:00.28 1024K 呆滞的慢板 

// 基础 BFS，这是当年裸奔用链表的低效 BFS 
// Refactored in 2008-5-21

#include <iostream>
#include <cmath>
using namespace std;

class Chess {
    
    int     xpos;
    int     ypos;

public:
    
    Chess *next;
    
    Chess() : xpos( -9 ), ypos( -9 ), next( 0 ) {}
    
    Chess( const int& x, const int& y) : 
        xpos(x),ypos(y), next( NULL ) {}
        
    Chess( const string& s) : next( NULL ),
        xpos( s[0]-'a' ), ypos( s[1]-'1' ) {}
    
    Chess findPos( const string& s ) { return Chess(s); }
    
    void disp() {
        cout << xpos << ", " << ypos << endl;
    }
    
    // 判别两个棋子位置是否相等 
    friend bool equal( const Chess& a, const Chess& b ) {
        return  a.xpos == b.xpos && a.ypos == b.ypos;
    }

    // 判别两个点是否相隔一步 
    friend bool match( const Chess& a, const Chess& b ) {
        return abs( ( a.xpos - b.xpos ) *
                    ( a.ypos - b.ypos ) ) == 2;
    }
    
};

// 初始化剩余点阵，输入源点
Chess* init( string s ) {
    
    Chess*  p = new Chess;
    Chess*  head = p;
    
    for( int i = 0; i < 8; i++ ) {
        for( int j = 0; j < 8; j++ ) {
            if( equal( Chess( i, j ), Chess( s ) ) )
                continue;
            *p = Chess( i, j );
            p -> next = new Chess;
            p = p -> next;
        }
    }
    
    return head;

}

// 判别一个点是否在当前点集的移动范围内 
bool valid( Chess *p, Chess q ) {
    
    while( p -> next ) {
        if( match( q, *p ) )
            return true;
        else    p = p->next;
    }
    
    return false;

}

// 释放一个链表 
void destroy( Chess* head ) {
    if( head -> next )
        destroy( head -> next );
    delete  head; 
}

// 显示一个链表 
void display( Chess* head ) {
    while( head -> next ) {
        head -> disp();
        head = head->next;
    }
    cout << endl; 
}

// 从剩余格子里面抽取相邻的格子到当前格子列 
void grab( Chess* &head, Chess* &p ) {
    
    Chess*  a = new Chess;
    Chess*  ah = a;
    Chess*  b = head;
    Chess*  temp = new Chess;
    
    temp -> next = head;
    
    while( b -> next ) {
        
        if( valid( p, *b ) ) {
            *a = *b;
            a -> next = new Chess;
            a = a -> next; 
            
            if( b == head ) {
                delete  temp; 
                temp = head;
                head = b = b -> next; 
            }
            else {
                temp -> next = b -> next;
                delete  b;
                b = temp -> next; 
            } 
        }
        
        else {
            temp = temp -> next;
            b = b -> next; 
        } 
    }
    
    destroy(p);
    p = ah;

}

// 查看一个点是否在当前点集中 
bool reach( Chess *p, Chess q ) {
    while( p -> next ) {
        if( equal( q, *p ) )
            return  true;
        else    p = p -> next;
    }
    return  false;
}


int main() {
    
    string  s,  d;
  
    while( cin >> s >> d ) {
  
        Chess   *head;
        Chess   *p; 
  
        int     cnt = 0; 
        
        head = init( s );
        p = new Chess( s );
        p -> next = new Chess;
        cnt = 0;
        
        while( !reach( p, d) ) {
            grab( head, p );
            ++cnt;
        }
        
        destroy( head );
        destroy( p ); 
    
        cout << "To get from " << s << " to ";
        cout << d << " takes " << cnt; 
        cout << " knight moves." << endl; 
    }

}
