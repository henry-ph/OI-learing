#include<iostream>
#include<algorithm>
using namespace std;
int dp[30005][30],p[30005],c[30005];
int main()
{
	int n,m,pr,im;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>pr>>im;
		p[i]=pr;
		c[i]=pr*im;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=p[i];j--)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-p[i]]+c[i]);
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}
