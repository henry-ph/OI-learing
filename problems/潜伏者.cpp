#include<iostream>
#include<cstring>
using namespace std;
int a[26];
int main()
{
	int len,lenx;
	string mi,yu,x;
	cin>>mi>>yu>>x;
	len=mi.size();
	lenx=x.size();
	for(int i=0;i<len;i++)	
	{
		a[yu[i]-65]=1;
		for(int j=0;j<len;j++)
		{
			if(mi[j]==mi[i]&&yu[j]!=yu[i])
			{
				cout<<"Failed"<<endl;
				return 0;
			}
		}
	}
	for(int i=0;i<26;i++)
	{
		if(a[i]==0)
		{
			cout<<"Failed"<<endl;
			return 0;
		}
	}
	for(int i=0;i<lenx;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(mi[j]==x[i])
			{
				cout<<yu[j];
				break;
			}
		}
	}
	cout<<endl;
	return 0;
}
