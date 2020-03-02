#include<iostream>
using namespace std;
int a[105];
bool x[105];
int main()
{
	int n;
	cin>>n;
	for(int i=n;i>=0;i--)
	{
		cin>>a[i];
		if(a[i]<0)
		{
			a[i]=-a[i];
			x[i]=true;
		}
	}
	for(int i=n;i>1;i--)
	{
		if(a[i]!=0)
		{
			if(i==n)
		{
			if(x[i])
			{
				if(a[i]==1)
				{
					cout<<"-x^"<<i;
					continue;
				}
				else
				{
					cout<<"-"<<a[i]<<"x^"<<i;
					continue;
				}
			}
			else
			{
				if(a[i]==1)
				{
					cout<<"x^"<<i;
					continue;
				}
				else
				{
					cout<<a[i]<<"x^"<<i;
					continue;
				}
			}
		}
		if(a[i]==1&&x[i])
		{
			cout<<"-"<<"x^"<<i;
			continue;
		}
		if(a[i]==1&&(!x[i]))
		{
			cout<<"+"<<"x^"<<i;	
			continue;
		}
		if(x[i])
		{
			cout<<"-"<<a[i]<<"x^"<<i;
			continue;
		}
		else
		{
			cout<<"+"<<a[i]<<"x^"<<i;
			continue;
		}
		}
	}
	if(a[1]!=0)
	{
		if(x[1])
	{
		if(a[1]==1)
		cout<<"-x";
		else
		cout<<"-"<<a[1]<<"x";
	}
	else
	{
		if(a[1]==1)
		cout<<"+x";
		else
		cout<<"+"<<a[1]<<"x";
	}
	}
	if(a[0]==0)
	return 0;
	if(x[0])
	cout<<"-"<<a[0];
	else
	cout<<"+"<<a[0];
	cout<<endl;
	return 0;
}
