# include <math.h>
# include <stdio.h>
# include <string.h>
int main()
{
    long a,b,d;
    bool palindrome(long);
    bool prime(long);
    scanf("%ld %ld",&a,&b);                //���������������a(a��5)������b(b��100000000)
    a+=!(a%2);                            //���������ڲ����ܴ���ż����
    b=b>9999999?9999999:b;                //���������ڲ����ܴ��ڰ�λ�����ϵĻ�������
    for(d=a;d<=b;d+=2)
        if(palindrome(d) && prime(d))
            printf("%ld\n",d);            //�����������[a,b]�ڵ����л�������
    return 0;
}
bool palindrome(long d)                    //�ú��������ж�һ����Ȼ��d�Ƿ�Ϊ������
{
    char _d[10],j=0,k;
    sprintf(_d,"%ld",d);                //��dת��Ϊ�ַ���_d
    k=strlen(_d)-1;
    while(j<k)
        if(_d[j++]!=_d[k--])
            return false;
    return true;
}
bool prime(long p)                        //�ú��������ж�һ������1����Ȼ��p�Ƿ�Ϊ����
{
    int _p;
    for(_p=2;_p<=sqrt(p);_p++)
        if(!(p%_p))
            return false;
    return true;
}
