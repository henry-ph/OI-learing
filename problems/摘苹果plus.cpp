#include<iostream>
#include<algorithm>
#define max 100000000
using namespace std;
int y[5005];
int main()
{
	int n,s,a,b,h,x,sum=0;
	cin>>n>>s>>a>>b;
	h=a+b;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y[i];
		if(x>h)
		y[i]=max;
	}
	sort(y,y+n);
	for(int i=0;i<n;i++)
	{
		s-=y[i];
		if(s>=0)
		sum++;
		else
		break;
	}
	cout<<sum<<endl;
	return 0;
}
