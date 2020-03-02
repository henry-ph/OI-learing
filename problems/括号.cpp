#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
	string a;
	cin>>a;
	int n;
	n=a.length();
	for(int i=0;i!='@';++i)
	{
		if(a[i]=='(') s.push(a[i]);
		if(a[i]==')')
		{
			if(s.empty()) 
			{
				cout<<"NO"<<endl;
				return 0;
			}
			else s.pop();
		} 
	}
	if(!s.empty())
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}

