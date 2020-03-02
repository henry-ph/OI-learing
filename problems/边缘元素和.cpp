#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[101][101];
int main()
{
	int m,n,sum=0;
	cin>>m>>n;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[1][i];
		sum+=a[m][i];
	}
	for(int i=2;i<=m-1;i++)
	{
		sum+=a[i][1];
		sum+=a[i][n];
	}
	cout<<sum<<endl;
	return 0;
}
