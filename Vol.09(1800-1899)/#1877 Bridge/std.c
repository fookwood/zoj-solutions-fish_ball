/*  Solution for "bridge" problem, a generalization of a problem
    generally believed to be a Microsoft intelligence test.
*/

/*  Algorithm

    Observation 1:  somebody has to get the flashlight back after every
                    forward trip.  This should obviously be the fastest
                    person on the far shore.

    Observation 2:  in the general case, we have 4 or more people, the
                    flashlight is on the starting side. 
                   
                    Consider the two slowest people.
                    there are 2 sensible strategies; we pick the fastest:

                    1. we can send each with the fastest person, who returns
                    with the flashlight.  this takes 2a+x+y time where a is
                    the fastest and x and y are the two slowest

                    2. we can send the fastest & 2nd fastest person, have
                    the fastest return with the flashlight, send the 
                    slowpokes together, have the 2nd fastest return with
                    the flashlight.  This takes a+2b+y where a is fastest,
                    b second fastest, and y slowest

                    BUT WAIT, you say.  What if strategy 1 is better than
                    2 for x and y but perhaps x or y could have been paired
                    with somebody else.  We already know that

                        2a+x+y <= a+2b+y
                             x <= 2b - a

                    Now if we had a different x' and y', it would be
                    the case that x' <= x and y' <= y so

                             x' <= 2b - a

                    so for any other pair 1 will be the best strategy.

                    BUT WAIT, you say again.  What if strategy 2 is better
                    than strategy 1, but prevents strategy 2 from being used
                    later, which would have been even better.

                    Let a,b be the 2 fastest and w,x,y be the slowest.
                    If we do x,y together we (may) force w to be done alone.

                      x,y together:  a+2b+y
                      w alone:       a+w
                      total:         2a+2b+w+y

                    If we do y alone, then w,x together.

                      y alone:       a+y
                      w,x together:  a+2b+x
                      total:         2a+2b+x+y

                    Since x >= w, this is worse so there's no point in
                    deferring the pairing.  


    Observation 3:  The end game.  If there are 3 people left, the fastest
                    shuttles them across.  If there are 2 people left,
                    they go together.

    Observation 4:  One person alone is a special case.  Happens only if
                    this person started alone.

*/


#include <stdio.h>
#include <stdlib.h>

int i,j,k,n;

int t[1000];

char cross[2000][16];
int nc,tot;

compar(int **a, int **b){
   return *a - *b;
}

main(){
   scanf("%d",&n);
   for (i=0;i<n;i++) scanf("%d",&t[i]);

   qsort(t,n,sizeof(int),compar);

   for (i=n-1;i>=3 && 2*t[1] < t[0]+t[i-1];i-=2){
      sprintf(cross[nc++],"%d %d\n",t[0],t[1]);
      sprintf(cross[nc++],"%d\n",t[0]);
      sprintf(cross[nc++],"%d %d\n",t[i-1],t[i]);
      sprintf(cross[nc++],"%d\n",t[1]);
      tot = tot + t[0]+2*t[1]+t[i];
   }
   for (;i>=2;i--){
      sprintf(cross[nc++],"%d %d\n",t[0],t[i]);
      sprintf(cross[nc++],"%d\n",t[0]);
      tot = tot + t[0] + t[i];
   }
   if (i==1) {
      sprintf(cross[nc++],"%d %d\n",t[0],t[1]);
      tot = tot + t[1];
   }else{
      sprintf(cross[nc++],"%d\n",t[0]);
      tot = tot + t[0];
   }
   printf("%d\n",tot);
   for (i=0;i<nc;i++) printf("%s",cross[i]);
}
