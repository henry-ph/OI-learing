#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n,b,c,d;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int u=1;u<=j;u++)
			{
				for(int o=1;o<=u;o++)
				if(pow(i,3)==pow(j,3)+pow(u,3)+pow(o,3))
				{
					b=min(min(j,u),o);
					d=max(max(j,u),o);
					c=j;
					if(c==b||c==d)
					c=u;
					if(c==b||c==d)
					c=o;
					cout<<"Cube = "<<i<<", "<<"Triple = "<<"("<<b<<","<<c<<","<<d<<")"<<endl;
				}
			}
		}
	}
	return 0;
}
