#include <stdio.h>
#include <string>
#include <map>

#define MAXN  1010

using namespace std;

typedef map < string , int > TMap;

struct  TNode {
        int   depth;
        TNode *Father;
};

TMap    Tree;
int     N , M , Which [MAXN];
TNode   Data [MAXN];

bool    init ();
void    work ();
TNode * Nearest ( TNode * , TNode * );

main ()
{
     while ( init () ) {
           work ();
           printf ( "\n" );
     }
}

TNode * Nearest ( TNode * A , TNode * B )
{
      if ( A == B ) return A;
      if ( A->depth > B->depth ) return Nearest ( A->Father , B );
      else return Nearest ( A , B->Father );
}

void work ()
{
     char Str [200] , Name [200] , State [200];
     int  a , b , j;
     TNode * Father;
     bool  Yes;
     
     for ( int i = 0; i < M; i ++ ) {
         gets ( Str );
         sscanf ( Str , "%s" , Name );
         j = strlen ( Name ) + 1;
         while ( Str [j ++] != 'a' );
         if ( Str [j] != ' ' ) j ++;
         a = Tree [Name];
         
         sscanf ( Str + j , "%s" , State );
         j += strlen ( State ) + 1;
         while ( Str [j ++] != 'f' );
         sscanf ( Str + j , "%s" , Name );
         Name [strlen ( Name ) - 1] = '\0';
         b = Tree [Name];
//         printf ( "%d %d %s\n" , a , b, State );
         
         Yes = false;
         Father = Nearest ( & Data [a] , & Data [b] );
         switch ( State [0] ) {
                case 'c' : Yes = (&Data [b] == Father) && Data [a].depth == Data [b].depth + 1; break;
                case 'e' : Yes = (&Data [a] == Father) && Data [a].depth + 1 == Data [b].depth; break;
                case 's' : Yes = ( a != b ) && ( Data [a].depth == Data [b].depth ) && Father->depth + 1 == Data [a].depth; break;
                case 'd' : Yes = ( Data [a].depth > Data [b].depth ) && ( &Data [b] == Father ); break;
                case 'a' : Yes = ( Data [a].depth < Data [b].depth ) && ( &Data [a] == Father ); break;
         }
         printf ( "%s\n" , Yes ? "True" : "False" );
     }
}

bool init ()
{
     char Str [200] , Name [200];
     int  s;
     
     scanf ( "%d%d\n" , &N , &M );
     if ( N == 0 && M == 0 ) return false;
     Which [0] = 0 , Data [0].depth = 0;
     for ( int i = 1; i <= N; i ++ ) {
         gets ( Str );
         for ( s = 0; Str [s] == ' '; s ++ );
         Data [i].Father = & Data [Which [s]];
         Data [i].depth = Data [i].Father->depth + 1;
         Which [s + 1] = i;
         sscanf ( Str , "%s" , Name );
         Tree [(string) Name] = i;
     }
     return true;
}
