#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2000+1000;
char s1[maxn],s2[maxn];
int a[maxn],b[maxn],c[maxn*maxn];
int main()
{
    scanf("%s%s",s1,s2);//�����ַ����� 
    int l1=strlen(s1),l2=strlen(s2);
    for(int i=0;i<l1;i++) a[i]=s1[l1-i-1]-'0';//ת�浽������ 
    for(int i=0;i<l2;i++) b[i]=s2[l2-i-1]-'0';//��λ��ǰ����λ�ź󣬱��ڽ�λ 
    for(int i=0;i<l1;i++)
        for(int j=0;j<l2;j++) {
            c[i+j]+=a[i]*b[j];//ע����+= ����= ����Ḳ��֮ǰ��λ������ 
            c[i+j+1]+=c[i+j]/10;//��λ��ͬ��ע����+= ����= 
            c[i+j]%=10;
        }
    int l3=l1+l2;
    while(l3>1&&c[l3-1]==0) l3--;//����ǰ���� 
    for(int i=l3-1;i>=0;i--) printf("%d",c[i]);
    return 0;
}
