#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
bool d[100]={0},b[100]={0},c[100]={0};
int sum=0,a[100];
int m[8][8]={0};
int search(int);
int print();
int main()
{
	search(1);
	return 0;
}
int search(int i)
{
	int j;
	for(j=1;j<=8;j++)
	if((!b[j])&&(!c[i+j])&&(!d[i-j+7]))
	{
		a[i]=j;
		b[j]=1;
		c[i+j]=1;
		d[i-j+7]=1;
		if(i==8) print();
		else search(i+1);
		b[j]=0;
		c[i+j]=0;
		d[i-j+7]=0;
	}
}
int print()
{
	int i,j;
	sum++;
	cout<<"No. "<<sum<<endl;
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			if(j!=a[i])
			cout<<"0"<<" ";
			else
			cout<<"1"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
