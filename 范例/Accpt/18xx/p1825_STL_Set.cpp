#include <iostream>
#include <set>
#include <string>

using namespace std;

set <string> Dic , Ans;
set <string> ::iterator     Iter1 , Iter2;

int main(int argc, char *argv[])
{
    string   Str;
    
    Dic.clear () , Ans.clear ();
    while ( cin >> Str ) Dic.insert ( Str );
    
    for ( Iter1 = Dic.begin (); Iter1 != Dic.end (); Iter1 ++ ) {
        for ( Iter2 = Iter1 , Iter2 ++; Iter2 != Dic.end (); Iter2 ++ ) {
            if ( Iter2->compare ( 0 , Iter1->size() , *Iter1 ) ) break;
            Str = Iter2->substr ( Iter1->size () , Iter2->size () - Iter1->size () );
            if ( Dic.find ( Str ) != Dic.end () ) Ans.insert ( *Iter2 );
        }    
    }
    
    for ( Iter1 = Ans.begin (); Iter1 != Ans.end (); Iter1 ++ )
        cout << *Iter1 << endl;
}
