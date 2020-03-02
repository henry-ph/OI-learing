#include<iostream>
#include<algorithm>
using namespace std;
int a[105],n,m;
void ch(int x)
{
	if(a[x+1]==a[x])
	{
		m--;
		a[x]=1001;
	}
	return;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	m=n;
	for(int i=0;i<n-1;i++)
	ch(i);
	cout<<m<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=1001)
		cout<<a[i]<<" ";	
	}
	cout<<endl;
	return 0;
}
