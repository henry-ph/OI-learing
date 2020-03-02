#include<iostream>
#include<iomanip>
using namespace std;
#define a 0.4463
#define b 0.4663
#define c 0.5663
int main()
{
	int n;
	double ans;
	cin>>n;
	if(n<=150)
	ans=n*a;
	else if(n<=400)
	ans=150*a+b*(n-150);
	else
	ans=150*a+250*b+(n-400)*c;
	cout<<fixed<<setprecision(1)<<ans<<endl;
	return 0;
}
