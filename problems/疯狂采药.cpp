#include<cstdio>
#include<algorithm>
using namespace std;
int v[100005],c[100005],dp[100005];
int main()
{
	int t,m;
	scanf("%d%d",&t,&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d",&v[i],&c[i]);
	for(int i=1;i<=m;i++)
	{
		for(int j=v[i];j<=t;j++)
		dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
	}
	printf("%d\n",dp[t]);
	return 0;
}
