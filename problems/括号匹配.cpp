#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
char a[300];
int main()
{
	int sum;
	stack<char> s;
	scanf("%s",a);
	sum=strlen(a);
	for(int i=1;i<sum;i++)
	{
		if(a[i]=='(')  s.push(a[i]);
		if(a[i]==')')
		{
			if(!s.empty())
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else
			s.pop(); 
		}
	}
	if(!s.empty()) cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	return 0;
}
