#include<iostream>
using namespace std;
int main()
{
	int a[105][105]={0};
	int n,s1=0,s2=0,x=0,y=0,b,c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			s1++;
		}
		if(s1%2==1)
		{
			b=i;
			x++;
		}
		s1=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==1)
			s2++;
		}
		if(s2%2==1)
		{
			c=i;
			y++;
		}
		s2=0;
	}
	if(x==0&&y==0)
	cout<<"OK"<<endl;
	else if(x==1&&y==1)
	{
		cout<<b<<" "<<c<<endl;
	}
	else
	cout<<"Corrupt"<<endl;
	return 0;
}
