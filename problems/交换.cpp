#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105];
int main()
{
	int n,minx=99999999;
	while(scanf("%d",&n)&&n!=0)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			minx=min(minx,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==minx)
			{
				int temp;
				temp=a[i];
				a[i]=a[1];
				a[1]=temp;
			} 
		}
		for(int i=1;i<n;i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}
