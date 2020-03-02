#include<iostream>
using namespace std;
int main()
{
	int i=0,sum=0;
	while(sum<1000)
	{
		i++;
		sum+=i*i;
	}
	cout<<i-1<<endl;
	return 0;
}
