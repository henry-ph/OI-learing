#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[100005],a[100005];
int f(int x)
{
	return (1890*x+143)%10007;
}
int main()
{
	int n,sum=0,ans=0,org=0;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		ans=0;
		sum=0;
		org=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i]=-a[i]+f(a[i]);
		org+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=dp[i];
		ans=max(ans,sum);
		if(sum<0) sum=0;
	}
	ans+=org;
	printf("%d\n",ans);
	}
	return 0;
}
