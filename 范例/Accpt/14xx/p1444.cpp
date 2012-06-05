#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#define MAXS    10000
#define MAXP    101

using namespace std;

struct  TNode {
        int     Word;
        TNode   *Next [52];
        TNode ();
}       Root;

TNode :: TNode ()
{
        Word = -1;
        memset ( Next , 0, sizeof ( Next ));
}

int     ProbNum , StudNum;
struct  TStudent {
        int     ProbAC , TotalTime , TimeCost [MAXP];
        char    Name [40] , Name2 [40];
}       Student [MAXS];

int     Order [MAXS];

bool    cmp ( const int &a , const int &b )
{
        return  Student [a].ProbAC == Student [b].ProbAC ?
                Student [a].TotalTime == Student [b].TotalTime ?
                        strcmp ( Student [a].Name2 , Student [b].Name2 ) < 0 : Student [a].TotalTime < Student [b].TotalTime
                : Student [a].ProbAC > Student [b].ProbAC;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        int     i , len , next;
        int     Time , Prob;
        char    Str [40] , State [10];
        TNode   *P;
        TStudent *S;

        memset ( Student , 0 , sizeof ( Student ));
        scanf ( "%d" , &ProbNum ); StudNum = 0;

        while ( scanf ( "%d%s%d%s" , &Time , Str , &Prob , State ) != EOF ) {
                for ( P = &Root , i = 0 , len = strlen ( Str ); i < len; i ++ , P = P->Next [next] ) {
                        next = Str [i] > 'Z' ? Str [i] - 'a' + 26 : Str [i] - 'A';
                        if ( P->Next [next] == NULL ) P->Next [next] = new TNode; 
                }
                if ( P->Word == -1 ) {
                        P->Word = StudNum ++;
                        strcpy ( Student [P->Word].Name , Str );
                        strcpy ( Student [P->Word].Name2 , Str );
                        for ( i = 0; i < len; i ++ ) Student [P->Word].Name2 [i] = tolower ( Str [i] );
                }
                S = &Student [P->Word];
                if ( State [0] == 'A' && S->TimeCost [Prob] >= 0 )
                        S->ProbAC ++ , S->TotalTime += Time + S->TimeCost [Prob] , S->TimeCost [Prob] = -9999999;
                        else S->TimeCost [Prob] += 20;
        }

        for ( i = 0; i < StudNum; i ++ ) Order [i] = i;
        sort ( Order , Order + StudNum , cmp );

        for ( i = 0; i < StudNum; i ++ ) {
                if ( Student [Order [i]].ProbAC == 0 ) break;
                if ( i && Student [Order [i]].ProbAC == Student [Order [i - 1]].ProbAC && Student [Order [i]].TotalTime == Student [Order [i - 1]].TotalTime )
                        printf ( "%10c" , ' ' );
                else printf ( "%-10d" , i + 1 );
                printf ( "%-30s%-10d%d\n" , Student [Order [i]].Name , Student [Order [i]].ProbAC , Student [Order [i]].TotalTime );                
        }
}
 