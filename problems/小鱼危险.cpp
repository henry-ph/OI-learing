#include<iostream>
using namespace std;
int main()
{
	long double s,x;
	double sum=0,sp=7;
	cin>>s>>x;
	while(sum<(s-x))
	{
		sum+=sp;
		sp*=0.98;
	}
	if(sp<(2*x))
	cout<<"y"<<endl;
	else
	cout<<"n"<<endl;
	return 0;	 
}
