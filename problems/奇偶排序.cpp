#include<iostream>
#include<algorithm>
using namespace std;
int a[10],b[10];
int main()
{
	int x,s1=0,s2=0;
	for(int i=1;i<=10;i++)
	{
		cin>>x;
		if(x%2==1)
		{
			a[s1]=x;
			s1++;
		}
		else
		{
			a[s2]=x;
			s2++;
		}
	}
	sort(a,a+x);
	sort(b,b+x);
	for(int i=s1-1;i>=0;i++)
	cout<<a[i]<<" ";
	for(int i=0;i<s2;i++)
	cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
