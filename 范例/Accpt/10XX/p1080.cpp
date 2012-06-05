//#define DEBUG

#include <iostream>

#ifdef DEBUG
#include <fstream>
#endif

using namespace std;

#ifdef DEBUG
        ifstream fin ( "p.in" );
        istream & in = fin;
        ofstream fdebug ( "Debug.txt" );
        ofstream fout ( "p.out" );
        ostream & out = fout;

#else
        istream & in = cin;
        ostream & out = cout;
#endif

const   int MAX_N = 20;

struct  Matrix
{
        int     size;
        char    data [MAX_N] [MAX_N];

        Matrix () {
                memset ( data , 0 , sizeof ( data ));
                size = 0;
        }
};

ostream & operator << ( ostream & out , const Matrix & y )
{
        int     i , j;
        for ( i = 0; i < y.size; i ++ ) {
                for ( j = 0; j < y.size; j ++ )
                        out << y.data [i] [j];
                out << endl;
        }
        return out;
}

char    DoSub ( Matrix & A , Matrix & B , int i , int j ,  Matrix & C )
{
        int     x , y;
        for ( x = -1; x <= 1; x ++ )
                for ( y = -1; y <= 1; y ++ )
                        if ( A.data [i + x] [j + y] == '0' && B.data [1 + x] [1 + y] == '1' ) return '0';

        for ( x = -1; x <= 1; x ++ )
                for ( y = -1; y <= 1; y ++ )
                        if ( A.data [i + x] [j + y] == '1' && B.data [1 + x] [1 + y] == '1' ) C.data [i + x] [j + y] = 1;
                        
        return '1';
}

bool    Subtraction ( Matrix & A , Matrix & B , Matrix & C )
{
        int     i , j;
        Matrix  Vilad;

        Vilad.size = A.size;
        C.size = A.size - 2;
        for ( i = 0; i < C.size; i ++ )
                for ( j = 0; j < C.size; j ++ )
                        C.data [i] [j] = DoSub ( A , B , i + 1 , j + 1 , Vilad );

        for ( i = 0; i < A.size; i ++ )
                for ( j = 0; j < A.size; j ++ )
                        if ( A.data [i] [j] == '1' && Vilad.data [i] [j] == 0 ) return false;

        return true;
}

bool    Solve ( Matrix & A , Matrix & B , int depth )
{
        if ( A.size % 2 == 0 ) return false;
        if ( A.size < 3 ) return false;
        if ( A.size == 3 ) return true;

        if ( depth == 9 ) {
        
                Matrix  C , D;

                if ( Subtraction ( A , B , C )) return Solve ( C , D , 0 );
                else return false; 
        }

        int     i , j;
        i = depth / 3;
        j = depth % 3;

        B.data [i] [j] = '0';
        if ( Solve ( A , B , depth + 1 )) return true;

        B.data [i] [j] = '1';
        if ( Solve ( A , B , depth + 1 )) return true;

        return false;
}


main ()
{
        int     step = 0;
        int     i , j;
        Matrix  A , B;
        
        while ( in >> A.size , A.size ) {
                step ++;
                for ( i = 0; i < A.size; i ++ )
                        for ( j = 0; j < A.size; j ++ )
                                in >> A.data [i] [j];

                out << "Instance " << step << ":" << endl;

                B.size = 3;
                if ( Solve ( A , B , 0 ) )
                        out << "Yes" << endl;
                else    out << "No" << endl;

        }
}
