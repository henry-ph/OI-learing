#include<iostream>
using namespace std;
int main()
{
	int n,x=0,y=0,a,b;
	cin>>n;
	if(n%2==0)
	{
		x=n/4+n%4/2;
		y=n/2;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
