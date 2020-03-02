#include<iostream>
using namespace std;
int a[5][5]={0,0};
int main()
{
	int m,n,x;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		cin>>a[i][j];
	}
	cin>>m>>n;
	for(int i=1;i<=5;i++)
	{
		if(m==i)
		i=n;
		else if(n==i)
		i=m;
		for(int j=1;j<=5;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
		if(m==i)
		i=n;
		else if(n==i)
		i=m;
	}
	return 0;
}

