#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100000001;//��һ���ݳ����󣬻��ǿ���㱣��
int n,len;//n������Ŀ�и���n,�ƶ��Ĳ�����len���ַ�������
char a[maxn];//�ַ���
int main()
{
    scanf("%d",&n);
    cin>>a;//����
    len=strlen(a);//�ⳤ
    for(int i=0;i<len;i++)//��ʼѭ��������ÿ���ַ���Ӧ������
    {
        if(a[i]+n<='z') printf("%c",a[i]+n);//����ƶ�֮��û�г���'z'��˵������ֱ�������
        else printf("%c",(a[i]+n)%122+96);//���������'z'���͵õ�ͷ����'a'��ʼ����
           //ע��1�� mod 122����˼���Ѿ�������'z'����ͷ������ȡʣ�µġ�122��'z'��ASCII��
           //ע��2�� +96����˼�Ǵ�'a'��ʼ�ӡ�96��'a'��ASCII�롣
    }
}
