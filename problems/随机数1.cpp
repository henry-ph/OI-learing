#include<cstdio>
#include<cstdlib> 
#include<ctime>
using namespace std;
int main()
{
	int n;
	srand((unsigned)time(NULL));
	while(getchar())
	{
		n=1+rand()%53;
		if(n==13||n==19) continue;
		else
		printf("ÓÐÇë%dºÅ",n);
	}
	return 0;
} 
