#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005,INF=30001;
int a[maxn],dp[maxn];
int cmp1(int a,int b)
{
    return a>=b;
}
int cmp2(int a,int b)
{
    return a>b;
}
int main()
{
    int n=-1;
    while(cin>>a[++n]);//������룬��ʼ��nΪ-1��Ϊ�˷����������֮��n�պ������ݵĸ���
    fill(dp,dp+n,-INF);//����һ��ʼҪ����ǲ��������У���˽�dp�����ʼ��Ϊ-INF
    for(int i=0;i<n;i++)
    {
        *lower_bound(dp,dp+n,a[i],cmp1)=a[i];//����һ������d(k)<a[i]��d(k)���³�a[i]
    }
    cout<<lower_bound(dp,dp+n,-INF,cmp2)-dp<<endl;//�����Ȼ����ֱ�ӵ�������������д�������������֡�����ԭ����Բ��������Ǹ�
    fill(dp,dp+n,INF);//������������е�ʱ��dp��ʼ��ΪINF
    for(int i=0;i<n;i++)
    {
        *lower_bound(dp,dp+n,a[i])=a[i];//����һ������d(k)>=a[i]��d(k)���³�a[i]
    }
    cout<<lower_bound(dp,dp+n,INF)-dp<<endl;//������������Ҫ��������һ������d(k)<INF��kֵ��Ȼ�����k+1���������Ƿ��֣���ʵ��������ľ��ǵ�һ������INF��kֵ�����ֱ�Ӳ���INF����
     return 0;
}
