#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
cin>>a[i];
	int b[12],c[12];
	for(int j=0,x=0;j<10;j++,x++)
	{
		if(a[j]%2==0)
		b[x]=a[j];
		else
		break;
		for(int u =0,y=0;u<10;u++,y++)
		{
			if(a[u]%2==1)
			c[y]=a[u];
			else
			break;
		}
		sort(b,b+12);
		sort(c,c+12,greater<int>());
		int q,p;
		q=-1;
		p=-1;
			while(b[q]!=0)
		{
			q++;
			cout<<b[q]<<" ";
		}
		while(c[p]!=0)
		{
		p++;
		cout<<c[p]<<" ";
	}
	}
return 0;
}
