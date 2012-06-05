////////////////////////////////////////////////////
//                 大整数模板 v1.1                //
////////////////////////////////////////////////////
//  1. 支持正整数加、减、乘、10进制移位运算;      //
//  2. 支持比较运算符 < 及 == ;                   // 
//  3. 支持流提取及流插入运算;                    // 
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

#include <deque>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

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
    
    friend BigNum  operator -=  ( BigNum num1, int num2 );
    
    friend BigNum  operator << ( BigNum& num, int n );
    
    friend BigNum& operator *= ( BigNum& num, const int& k );
    
    friend BigNum  operator *  ( BigNum& num1, BigNum num2 );
    
    friend bool operator == ( const BigNum& num1, const BigNum& num2 );
    
    friend bool operator <  ( const BigNum& num1, const BigNum& num2 );

    friend bool operator <=  ( const BigNum& num1, const BigNum& num2 );

    friend ostream& operator << ( ostream& os, BigNum num );
    
    friend istream& operator >> ( istream& is, BigNum& num );
    
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

// 相等比较运算符 
bool operator == ( const BigNum& num1, const BigNum& num2 ) {
    
    return  num1.V == num2.V;
    
}

// 小于比较运算符 
bool operator <  ( const BigNum& num1, const BigNum& num2 ) {
    
    if( num1.V.size() < num2.V.size() ) return  true;
    if( num1.V.size() > num2.V.size() ) return  false;
    for( int i = num1.V.size() - 1; i >= 0; --i ) {
        if( num1.V[i] < num2.V[i] ) return  true;
        if( num1.V[i] > num2.V[i] ) return  false;
    }
    return  false;
    
}

// 小于等于比较运算符 
bool operator <= ( const BigNum& num1, const BigNum& num2 ) {
    
    if( num1.V.size() < num2.V.size() ) return  true;
    if( num1.V.size() > num2.V.size() ) return  false;
    for( int i = num1.V.size() - 1; i >= 0; --i ) {
        if( num1.V[i] < num2.V[i] ) return  true;
        if( num1.V[i] > num2.V[i] ) return  false;
    }
    return  true;
    
}

// 重载流插入运算符 
ostream& operator << ( ostream& os, BigNum num ) {
    
    os << num.V.back();
    
    for( int i = num.V.size() - 2; i >= 0; --i )
        os << setw( 4 ) << setfill( '0' ) << num.V[i];
    
    return  os;
    
}

// 重载流提取运算符 
istream& operator >> ( istream& is, BigNum& num ) {
    
    string  input;
    
    is >> input;
    
    num = 0;
    
    for( int i = 0; i < input.size(); ++i ) {
        num = num * 10;
        num = num + ( input[i] - '0' );
    }
    
    return  is;

}
