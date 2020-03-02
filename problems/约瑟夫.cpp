#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105];
int main()
{
	int n,m,j=0,s=0,i=0;
	cin>>n>>m;
	s=n;
	while(n!=0)
	{
		i++;
		if(i>s) 
		{
			i=0;
			continue;
		}
		if(!a[i]) j++;
		if(j==m)
		{
			cout<<i<<" ";
			a[i]=1;
			j=0;
			n--;
		}
	}
	return 0;
}
