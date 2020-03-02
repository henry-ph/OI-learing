#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c,d;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cout<<"("<<a<<","<<i<<")"<<" ";
		cout<<endl;
	for(int i=1;i<=n;i++)	
		cout<<"("<<i<<","<<b<<")"<<" ";
		cout<<endl;
	c=a;
	d=b;
	while(c>1&&d>1)
	{
		c--;
		d--;
	}
	for(int i=1;d<=n&&c<=n&&c>0&&d>0;i++)
	{
		cout<<"("<<c<<","<<d<<")"<<" ";
		c++;
		d++;
	}
	cout<<endl;
	while(b!=1&&a<=n-1)
	{
		a++;
		b--;
	}
	for(int i=1;a<=n&&a>=1&&b<=n;i++)
	{
		cout<<"("<<a<<","<<b<<")"<<" ";
		a--;
		b++;
	}
	cout<<endl;
	return 0;
}
