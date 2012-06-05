#include <stdio.h>

char fname[100];
FILE *dat, *diff;

int who[2][101];
int best, cbest, time;
char buf[1000];

int i,j,k,n,here;
int a,b;

main(int argc, char **argv){
   strcpy(fname,argv[0]);
   strcpy(fname+strlen(fname)-3,"dat");
   dat = fopen(fname,"r");
   if (!dat) { 
      perror("no .dat file");
      abort();
   }
   strcpy(fname+strlen(fname)-3,"diffx");
   diff = fopen(fname,"r");
   if (!diff) {
      perror("no .dif file");
      abort();
   }

   fscanf(diff,"%d",&best);
   scanf("%d ",&cbest);

   fscanf(dat,"%d",&n);
   for (i=0;i<n;i++) {
      fscanf(dat,"%d",&j);
      who[0][j]++;
   }

   while (gets(buf)) {
      a=b=0;
      i = sscanf(buf,"%d%d",&a,&b);
      if (i < 1) {
         printf("mangled line: %s\n",buf);
         exit(1);
      }
      if (a<1 || a>100 || !who[here][a]--) {
         printf("move invalid a person %s\n",buf);
         exit(1);
      }
      if (i == 2 && (b<1 || b >100 || !who[here][b]--)){
         printf("moved invalid b person %s\n",buf);
         exit(1);
      }
      here = !here;
      who[here][a]++;
      who[here][b]++;
      if (b > a) time += b; else time += a;
   }
   if (best != time) {
      printf("total time:  judge %d calculated %d\n",best,time);
      exit(1);
   }

   for (i=1;i<=100;i++) if (who[0][i]) {
      printf("person %d did not get across\n",i);
      exit(1);
   }

   if (best != cbest) {
      printf("total time:  judge %d submission %d\n",best,cbest);
      exit(1);
   } 

   printf("correct submission; time is %d\n",time);
   exit(0);
}
