#include <iostream.h>

main()
{
int a,b;
cin>>a;
while (a>0) {
        b=1;
        while (a%2==0) {
                a=a/2;
                b=b*2;
        }
        cout<<b<<endl;
        cin>>a;
        }

}
 