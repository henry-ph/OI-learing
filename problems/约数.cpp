#include<iostream>
#include<cmath>
using namespace std;
long long s;
int yue(int i)
{
	s=0;
	for(int j=1;j<=sqrt(i);j++)
	{
		if(i%j==0)
		{
			s+=2;
			if(j==i/j)
			s--;
		}
	}
	return 0;
}
int main()
{
	long long n,k;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		yue(i);
		sum+=s;	
	}
	cout<<sum<<endl;
	return 0;
}

