#include<iostream>
using namespace std;
int main()
{
	int j,sum,n,i,a;
	cin>>n;
	for(i=1;i<=n;i++)
{
		sum=0;
		cin>>a;
		for(j=1;j<=a;j++)
		{
		sum=sum+j;
	}
cout<<sum<<endl<<endl;
}
	return 0;	
}
