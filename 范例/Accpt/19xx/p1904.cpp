#include<stdio.h>
#include<math.h>
int main()
{
	double D,V;
	while(scanf("%lf%lf",&D,&V),D||V)
	printf("%0.3lf\n",pow(D*D*D-V*1.9098593497,1.0/3));//6/PI
	return 0;
}