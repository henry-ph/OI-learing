#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int a[2];
	for(int i=0;i<2;i++)
	cin>>a[i];
int x,y;
	int b[x],c[y];
	for(int j=0;j<2;j++)
	{
		if(a[j]%2==0)
		b[j]=a[j];
		else
		c[j]=a[j];
	    cout<<b[x]<<" ";
	    cout<<c[y]<<" ";
	}
return 0;
}
