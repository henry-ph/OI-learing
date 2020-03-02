#include<iostream>
using namespace std;
int main()
{
	int m,n,sum,a,i,j;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>a;
		sum=0;
		for(n=1;n<=a;n++)
		{
			cin>>j;
			sum+=j;
		}
cout<<sum<<endl;		
}
return 0;
}
