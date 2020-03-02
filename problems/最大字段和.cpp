#include<iostream>
using namespace std;
int a[200001],b[200001];
int main()
{
    int n,sum=0,big=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    b[1]=a[1];
    big=a[1];
    for(int i=2;i<=n;i++)
    {
        b[i]=max(a[i],b[i-1]+a[i]);//看看取不取这个数。
        if(b[i]>big)
            big=b[i];//最大子段和
    }
    cout<<big<<endl;
    return 0;
	}
