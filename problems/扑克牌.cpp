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
    t/=n;//tΪƽ��ֵ
    for(int i=1;i<=n;i++)
    {
        a[i]-=t;//��������
        s+=a[i];//��ĿǰΪֹ�Ĳ�ֵ��
        if(s!=0) m++;//�������ǡ�ò��꣬�ͼ���
    }
    printf("%d\n",m);
    return 0;
}
