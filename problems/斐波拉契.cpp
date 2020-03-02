#include<iostream>
using namespace std;
int a[30];
int main()
{
	a[1]=1;a[2]=1;
	for(int i=3;i<=30;i++)
	a[i]=a[i-1]+a[i-2];
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cout<<a[x]<<endl;
	}
	return 0;
}
