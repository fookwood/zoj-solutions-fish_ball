// 2955653 2008-06-24 10:40:26 Accepted 1667 C++ 00:00.00 392K 呆滞的慢板 

// 模拟骰子的滚动，用 OOP 最为清晰了 

#include <cstring>
#include <cstdio>


class Dice {
    
    int A[6];
    
public:
    
    Dice() {
        A[0] = 1;   // top
        A[1] = 2;   // north
        A[2] = 3;   // west
        A[3] = 5;   // south
        A[4] = 4;   // east
        A[5] = 6;   // bottom
    }
    
    void north() {
        int temp = A[5];
        A[5] = A[1];
        A[1] = A[0];
        A[0] = A[3];
        A[3] = temp;
    }
    
    void south() {
        int temp = A[1];
        A[1] = A[5];
        A[5] = A[3];
        A[3] = A[0];
        A[0] = temp;
    }
    void west() {
        int temp = A[4];
        A[4] = A[5];
        A[5] = A[2];
        A[2] = A[0];
        A[0] = temp;
    }
    
    void east() {
        int temp = A[2];
        A[2] = A[5];
        A[5] = A[4];
        A[4] = A[0];
        A[0] = temp;
    }
    
    int top() { return  A[0]; }
    
};


int main() {
    
    int     N;
    char    S[6];
    
    while( scanf( "%d", &N ) && N ) {
    
        Dice    dice;
    
        while( N-- ) {
            
            scanf( "%s", S );
            
            switch( *S ) {
                case 'n': dice.north(); break;
                case 's': dice.south(); break;
                case 'e': dice.east();  break;
                case 'w': dice.west(); 
            }
            
        }
        
        printf( "%d\n", dice.top() );
    
    }
    
}
