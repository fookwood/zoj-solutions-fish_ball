#include <iostream.h>

long long       num[50001];
long            ans[50001];
long            n;
long long       m;

void makenum();
void print();

void print()
{
long    l,r,mid,i;
long long   leave;
l=1;r=n;
num[0]=0;
while (l<r) {
        mid=(l + r) /2;
        if (num[mid]==m) {
                l=r=mid;
        }
        else
        if (num[mid]>m) {
                r=mid-1;
        }
        else
        l=mid+1;
}

if (num[l]>=m) l--;

leave=m-num[l];

for (i=1;i<=n-l;i++) ans[i]=i;
ans[n-l]=n-l+leave;
/*for (i=n-l;i<=n-leave-1;i++) ans[i]=n+n-1-l-i;
ans[n-leave]=n;

for (i=n-leave+1;i<=n;i++) ans[i]=n+n-l-i;
*/
for (i=n-l+1;i<=n;i++) {
        ans[i]=n+n-l-i;
        if (ans[i]>=ans[n-l]) ans[i]++;
}
cout<<ans[1];
for (i=2;i<=n;i++) cout<<' '<<ans[i];
cout<<endl;
}

void makenum()
{
num[1]=0;
for (long i=2;i<=50000;i++) num[i]=num[i-1]+i-1;
}


main()
{
makenum();
while (cin>>n>>m && n!=-1 && m!=-1) {
        print();
}
}
 