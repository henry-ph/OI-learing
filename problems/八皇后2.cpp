#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100],b[100],c[100],d[100],p[100];
int sum=0;
int dfs(int i);
int print();
int main()
{
	int n,k;
	cin>>n;
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		cout<<p[k-1]<<endl;
	}
	return 0;
}
int dfs(int i)
{
	for(int j=1;j<=8;j++)
	{
		if((!b[j])&&(!c[i+j])&&(!d[i-j+7]))
		{
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i-j+7]=1;
			if(i==8) print();
			else dfs(i+1);
			b[j]=0;
			c[i+j]=0;
			d[i-j+7]=0;
		}
	}
	return 0;
}
int print()
{
	int s=0;
	for(int i=8;i>=1;i--)
	s+=a[i]*pow(10,8-i);
	p[sum]=s;
	sum++;
	return 0;
}
