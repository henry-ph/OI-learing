#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a,b,sum[10]={0},ans[10]={0};
	for(int i=0;i<7;i++)
	{
		cin>>a>>b;
		sum[i]=a+b;
	}
	for(int i=0;i<7;i++)
	ans[i]=sum[i];
	sort(sum,sum+7);
	for(int i=0;i<7;i++)
	{
		if(ans[i]==sum[6])
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
}
