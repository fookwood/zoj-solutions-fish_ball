// zju 1405

#include <iostream>
#include <fstream>

using namespace std;

//ifstream in ( "p.in" );
//ofstream out ( "p.out" );
istream &in = cin;
ostream &out = cout;

int     Limit;
char    Data [255];
bool    Leave [255];
int     len;

main ()
{
        int     i , have , Ans;
        while ( in >> Limit , Limit ) {
                in >> Data;
                len = strlen ( Data );

                memset ( Leave , 0 , sizeof ( Leave ));
                for ( Ans = i = have = 0; i < len; i ++ ) {
                        if ( !Leave [Data [i]] ) {
                                Leave [Data [i]] = 1;
                                have ++;
                                if ( have > Limit ) Ans ++;
                        } else {
                                Leave [Data [i]] = 0;
                                have --;
                        }
                }
                if ( Ans ) out << Ans << " customer(s) walked away.\n";
                        else out << "All customers tanned successfully.\n";

        }
}
 