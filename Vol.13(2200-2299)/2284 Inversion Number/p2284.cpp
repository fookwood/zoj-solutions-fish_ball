#include <deque>
#include <iostream>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////
//                 大整数模板 v1.0                //
////////////////////////////////////////////////////
//  1. 只支持正整数加、乘、10进制移位运算;        //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

class BigNum {

    deque<int>  V;

public:
    
    BigNum() : V( 1, 0 ) {}
    
    BigNum( const BigNum& num ) : V( num.V ) {}
    
    BigNum( int val ) : V( 0 ) {
        while( val > 10000 ) {
            V.push_back( val % 10000 );
            val /= 10000;
        }
        V.push_back( val );
    }
    
    friend BigNum& operator += ( BigNum& num1, BigNum num2 );
    
    friend BigNum  operator +  ( BigNum num1, BigNum num2 );
    
    friend BigNum  operator << ( BigNum& num, int n );
    
    friend BigNum& operator *= ( BigNum& num, const int& k );
    
    friend BigNum  operator *  ( BigNum& num1, BigNum num2 );
    
    friend ostream& operator << ( ostream& os, BigNum num );

};

// 相加自增量运算符 
BigNum& operator += ( BigNum& num1, BigNum num2 ) {
    
    if( num1.V.size() > num2.V.size() )
        num2.V.resize( num1.V.size() );
    else
        num1.V.resize( num2.V.size() );

    int carry = 0;
    
    for( int i = 0; i < num1.V.size(); ++i ) {
        num1.V[i] += ( num2.V[i] + carry );
        carry = num1.V[i] / 10000;
        num1.V[i] %= 10000;
    }

    if( carry ) num1.V.push_back( 1 );
    
    return  num1;

}

// 相加运算符 
BigNum operator + ( BigNum num1, BigNum num2 ) {
    
    if( num1.V.size() > num2.V.size() )
        num2.V.resize( num1.V.size() );
    else
        num1.V.resize( num2.V.size() );

    int carry = 0;
    
    for( int i = 0; i < num1.V.size(); ++i ) {
        num1.V[i] += ( num2.V[i] + carry );
        carry = num1.V[i] / 10000;
        num1.V[i] %= 10000;
    }

    if( carry ) num1.V.push_back( 1 );
    
    return  num1;

}

// 重载左移运算符 
BigNum operator << ( BigNum& num, int n ) {

    BigNum  ans( num );
    while( n-- > 0 )
        ans.V.push_front( 0 );
    return  ans;

}

// 数乘自赋值运算符 
BigNum& operator *= ( BigNum& num, const int& k ) {

    int carry = 0;
    for( int i = 0; i < num.V.size(); ++i ) {
        num.V[i] *= k;
        num.V[i] += carry;
        carry = num.V[i] / 10000;
        num.V[i] %= 10000; 
    }
    if( carry ) num.V.push_back( carry );
    return  num;

}

// 相乘运算符 
BigNum operator * ( BigNum& num1, BigNum num2 ) {

    BigNum  temp,   ans;

    for( int i = 0; i < num1.V.size(); ++i ) {
        temp = num2 << i;
        temp *= num1.V[i];
        ans += temp;
    }
    
    return  ans;

}

// 重载流插入运算符 
ostream& operator << ( ostream& os, BigNum num ) {
    
    os << num.V.back();
    
    for( int i = num.V.size() - 2; i >= 0; --i )
        os << setw( 4 ) << setfill( '0' ) << num.V[i];
    
    return  os;
    
}

////////////////////////////////////////////////////////

int A[21][201] = {};

int main() {
    
    for( int i = 1; i < 21; ++i ) {
        A[i][0] = 1;
//        cout << 1 << ' ';
        for( int j = 1; j <= i * ( i - 1 ) / 2; ++j ) {
            A[i][j] = 0;
            for( int k = j; k > j - i; --k )
                A[i][j] += A[i - 1][k];
//            cout << A[i][j] << ' ';
        }
//        cout << endl;
    }
    
    int M,  N;
    while( ( cin >> M >> N ) && ( M || N ) )
        cout << A[M][N] << endl;
    
}
