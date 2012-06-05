#include <stdio.h>
#include <string>
#include <string.h>
#include <map>

#define Self  'Z'
#define Indentify 'A'

using namespace std;

typedef  map < string , int > TMap;


TMap     Dic;
TMap     :: iterator Iter;


main ()
{
     Dic.clear ();
     
     char      Str [20];
     int       len , Final = 0 , Max , i;
     string    State , NewState;
     while ( scanf ( "%s\n" , Str ) != EOF ) {
           State = (string) Str;
           
           len = State.length () , Max = 0;
           
           NewState = State + Self;
           for ( i = 0; i <= len; i ++ ) {
               NewState [len] = Indentify + i;
               Iter = Dic.find ( NewState );
               if ( Iter != Dic.end () && Iter->second > Max ) Max = Iter->second;
           }   // part 1 : Insert
           
           NewState = State.substr ( 1 , len - 1 ) + Self;
           for ( i = 0; i < len; i ++ ) {
               if ( i ) NewState [i - 1] = State [i - 1];
               NewState [len - 1] = Indentify + i;
               Iter = Dic.find ( NewState );
               if ( Iter != Dic.end () && Iter->second > Max ) Max = Iter->second;
               
               NewState [len - 1] = Self;
               Iter = Dic.find ( NewState );
               if ( Iter != Dic.end () && Iter->second > Max ) Max = Iter->second;
           }
           
           Max ++;
           NewState = State + Self;
           Iter = Dic.find ( NewState );
           if ( Iter == Dic.end () ) Dic [NewState] = Max;
           else if ( Max > Iter->second ) Iter->second = Max;
           
           NewState = State.substr ( 1 , len - 1 ) + Self;
           for ( i = 0; i < len; i ++ ) {
               if ( i ) NewState [i - 1] = State [i - 1];
               NewState [len - 1] = Indentify + i;
               Iter = Dic.find ( NewState );
               if ( Iter == Dic.end () ) Dic [NewState] = Max;
               else if ( Max > Iter->second ) Iter->second = Max;
           }
           
           if ( Max > Final ) Final = Max;
     }
     
     printf ( "%d\n" , Final );
}
