#include<cmath>
#include<algorithm>
#include<cstdio>
int main()
{
	double i,j,sum=0;
	for(i=1;i<=100;i++)
	for(j=1;j<=100;j++)
	{
		sum+=((i/j)*(i/j)+1)/((i/j)*(i/j));
		//printf("%d",sum);
	}
	printf("%d",sum);
	return 0;
}
