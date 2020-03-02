#include <iostream>
using namespace std;
int a[10]={0},f=0;
string t;
int main(){
cin>>t;
for(int i=0;t[i];i++)
for(int j=2;j<=9;j++)
{
	a[j]=(a[j]*10+t[i]-'0')%j;
	cout<<a[j]<<" ";
}
cout<<endl;
for(int i=2;i<=9;i++)
if (!a[i]){cout<<i<<' ';f=1;}
if (!f) cout<<"none";
return 0;
}
