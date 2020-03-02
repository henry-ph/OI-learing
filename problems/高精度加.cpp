#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[505],b[505],c[505];
int main()
{
	string x,y;
	int lenx,leny,len;
	cin>>x>>y;
	lenx=x.length();
	leny=y.length(); 
	for(int i=lenx-1,j=0;i>=0,j<lenx;i--,j++) a[j]=x[i]-48;
	for(int i=leny-1,j=0;i>=0,j<leny;i--,j++) b[j]=y[i]-48;
	len=max(lenx,leny);
	for(int i=0;i<len;i++)
	{
		c[i]=a[i]+b[i];
		if(c[i]>=10)
		{
			c[i]-=10;
			a[i+1]++;
			if(i+1==len) len++;
		}
	}
	for(int i=len-1;i>=0;i--) cout<<c[i];
	cout<<endl;
	return 0;
}
