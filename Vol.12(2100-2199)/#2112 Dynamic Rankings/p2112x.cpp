/*#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 1000000000
using namespace std;
int a[60000];
int main()
{
int test,n,m,i,j;
scanf("%d",&test);
while(test--)
{
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)
   {
    scanf("%d",&a[i]);
   }
   while(m--)
   {
    char pro[5];
    scanf("%s",&pro);
    int num;
    if(pro[0]=='Q')
    {
     int fro,to,xu[50005],visit[50005],visit1[50005];
     memset(visit1,0,sizeof(visit1));
     scanf("%d%d%d",&fro,&to,&num);
     int sign=0;
     {
     // for(i=fro-1;i<num;i++)
      i=fro-1;
      sign=0;
      visit[sign]=i;
      //sign++;
      int mid=-1,dis=MAX;
      if((fro+mid)/2>num)// search it from the position i know
      {
       while(1)
       {
        for(j=fro-1;j<to-1;j++)
        {
         if(mid<a[j]&&a[j]-mid<dis)
         {
          dis=a[j]-mid;
          visit[sign]=j;
         }
       
        }
        mid=a[visit[sign]];
         dis=MAX;
        sign++;
        if(sign==num)
         break;
       }
       printf("%d\n",a[visit[num-1]]);
      }
      else
      {
       dis=MAX;mid=MAX;
       while(1)
       {
        for(j=fro-1;j<to;j++)
        {
         if(mid>a[j]&&mid-a[j]<dis)
         {
          dis=mid-a[j];
          visit[sign]=j;
         }
       
        }
        mid=a[visit[sign]];
         dis=MAX;
        sign++;
        if(sign==to-num+1)
         break;
       }
       printf("%d\n",a[visit[to-fro+1-num]]);
      }
     }
    }
    else
    {
     int se,num;
     scanf("%d%d",&se,&num);
     a[se-1]=num;
    }
   }
}

return 0;
}
*/
// the total amount of time i need is 10000*50000*n^k



// the right code
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 1000000000
using namespace std;
struct mm
{
int map ;
int sign;
}a[60000],temp;
bool com(mm c,mm d)
{
return c.map<d.map;
}
int n;
/*int search(int m)
{
int start=0,end=n-1,mid,i;
while(end>=start)
{
   mid=(end+start)/2;
   if(mid==n-1)
    return mid;
   if(mid==0)
    return mid;
   if(a[mid-1].map <= m && a[mid+1].map >= m &&mid-1 >= 0 && mid+1 < n)
   {
    return mid;
   }
   else if (a[mid].map < m)
    start=mid+1;
   else
    end=mid-1;
}
}*/   
// 太晕了，居然这里没有想到，这样交换是不行的
int main()
{
int test,m,i,j;
scanf("%d",&test);
while(test--)
{
   scanf("%d%d",&n,&m);
   for(i=0;i<n;i++)
   {
    scanf("%d",&a[i].map);
    a[i].sign=i;
   }
   sort(&a[0],&a[n],com);
   char pro[5];
   while(m--)
   {
    scanf("%s",&pro);
    int num;
    if(pro[0]=='Q')
    {
     int fro,to,k;
     scanf("%d%d%d",&fro,&to,&k);
     fro--;
     to--;
     int num=0;
     for(i=0;i<n;i++)
     {
      if(a[i].sign >= fro&&a[i].sign<= to)// pay attention to this kind
       // of operation
      {
       num++;
       if(num==k)
        break;
      }
     }
     printf("%d\n",a[i].map);
    }
    else
    {
     int sign1,num;
     scanf("%d%d",&sign1,&num);
    /* int c=search(num),tag;
     temp = a[c];
       a[c].map = num;
     tag=a[sign1-1].sign ;
     a[c].sign = tag;
     a[sign1-1] = temp;*/
     //sort(&a[0],&a[n],com);
     for(i=0;i<n;i++)
     {
      if(a[i].sign == sign1-1)
      {
       a[i].map=num;
       break;
      }
     }
     while(a[i].map>a[i+1].map && i+1<n)
     {
      temp=a[i];
      a[i]=a[i+1];
      a[i+1]=temp;
      i++;
     }
     while(a[i].map<a[i-1].map )
     {
      temp=a[i];
      a[i]=a[i-1];
      a[i-1]=temp;
      i--;
     }
    }
   } 
}
return 0;
}

