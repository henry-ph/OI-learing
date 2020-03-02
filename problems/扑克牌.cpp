#include<stdio.h>
int n,a[110],t=0,m=0,s=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        t+=a[i];
    }
    t/=n;//t为平均值
    for(int i=1;i<=n;i++)
    {
        a[i]-=t;//计算差多少
        s+=a[i];//求到目前为止的差值和
        if(s!=0) m++;//如果不能恰好补完，就加上
    }
    printf("%d\n",m);
    return 0;
}
