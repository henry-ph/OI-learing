#include<iostream>
using namespace std;
int a[100005];
int main()
{
	int m,n,sum=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>m)
		{
			ans++;
			i--;
			sum=0;
		}
		
	}
	cout<<ans+1<<endl;
	return 0;
}
