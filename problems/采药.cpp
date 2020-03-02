#include<iostream>
#include<algorithm>
using namespace std;
int dp[1005],t[105],c[105];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>t[i]>>c[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=t[i];j--)
		dp[j]=max(dp[j],dp[j-t[i]]+c[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}
