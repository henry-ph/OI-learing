#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int y,a,b,i;
	while(y!=0)
	{
		for(i=-100;i<=0;i++)
		{
			a=pow(i+8,2013);
			b=pow(i,2013);
			y==a+b+2*i+8;
			cout<<i<<" "<<y<<endl;
		}
	}
	
	return 0;
}
