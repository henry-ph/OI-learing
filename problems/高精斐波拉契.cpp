#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<cstring>
using namespace std;
int j=3;
char fib[5001][2000];//������Ž��
void jia(char a1[],char b1[])// �߾��ӷ���������ô������Ͳ�׸���ˣ�
{
    int a[2000]={0},b[2000]={0},c[2000]={0},lena,lenb,lenc,i,x;
    lena=strlen(a1);
    lenb=strlen(b1);
    for(i=0;i<=lena-1;i++)
        a[lena-i]=a1[i]-48;
    for(i=0;i<=lenb-1;i++)
        b[lenb-i]=b1[i]-48;
    lenc=1;
    x=0;
    while(lenc<=lena || lenc<=lenb)
    {
        c[lenc]=a[lenc]+b[lenc]+x;
        x=c[lenc]/10;
        c[lenc]%=10;
        lenc++;
    }
    c[lenc]=x;
    if(c[lenc]==0)
        lenc--;
    for(i=lenc;i>=1;i--)//�Ѽӵõ�����һ�£��Ա����
        fib[j][lenc-i]=c[i]+'0';
    fib[j][lenc]='\0';
} 
int main()
{
    int n,len,i;
    scanf("%d",&n);//��������
    fib[0][0]='0';//��0����0
    fib[1][0]='1';//��1����1
    fib[2][0]='2';//��2����2
    while(j<=n)//���������
        {
            jia(fib[j-1],fib[j-2]);//�������n��
            j++;
        }
    printf("%s",fib[n]);//������
}
