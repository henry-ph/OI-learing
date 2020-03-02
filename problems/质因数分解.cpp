#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n,ans=0;
	cin>>n;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			ans=max(ans,n/i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
