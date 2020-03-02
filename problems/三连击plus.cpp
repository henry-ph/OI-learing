#include<iostream>
using namespace std;
bool q[1];
int pd(int a,int b,int c)
{
	int x[10]={0};
	x[a%10]=1;
	x[(a/10)%10]=1;
	x[a/100]=1;
	x[b%10]=1;
	x[(b/10)%10]=1;
	x[b/100]=1;
	x[c%10]=1;
	x[(c/10)%10]=1;
	x[c/100]=1;
	for(int i=1;i<=9;i++)
	{
		if(x[i]==0)
		return 1;
	}
	return 0;
}
int main()
{
	int a,b,c,x=0,y=0,z=0,h;
	cin>>a>>b>>c;
	h=999*a/c;
	for(int i=100;i<=h;i++)
	{
		if(i%a==0)
		{
			x=i;
			y=i/a*b;
			z=i/a*c;
			if(pd(x,y,z)==0)
			{
				cout<<x<<" "<<y<<" "<<z<<endl;
				q[0]=true;
			}
		}
	}
	if(!q[0])
	cout<<"No!!!"<<endl;
	return 0;
}

