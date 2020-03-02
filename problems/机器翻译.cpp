#include<iostream>
#include<cstring>
using namespace std;
int a[105];
int u[1];
int main()
{
	memset(a,-1,sizeof(a));
	int m,n,x,y=1,ans=0;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=m;j++)
		{
			if(a[j]==x)
			{
				u[0]=1;
				break;
			}
		}
		if(u[0]==0)
		{
			ans++;
			if(y==m+1)
			y-=m;	
			a[y]=x;
			y++;
		}
		u[0]=0;
	}
	cout<<ans<<endl;
	return 0;
}
