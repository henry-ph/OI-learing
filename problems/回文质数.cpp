# include <math.h>
# include <stdio.h>
# include <string.h>
int main()
{
    long a,b,d;
    bool palindrome(long);
    bool prime(long);
    scanf("%ld %ld",&a,&b);                //输入给定区间下限a(a≥5)和上限b(b≤100000000)
    a+=!(a%2);                            //给定区间内不可能存在偶质数
    b=b>9999999?9999999:b;                //给定区间内不可能存在八位数以上的回文质数
    for(d=a;d<=b;d+=2)
        if(palindrome(d) && prime(d))
            printf("%ld\n",d);            //输出给定区间[a,b]内的所有回文质数
    return 0;
}
bool palindrome(long d)                    //该函数用于判断一个自然数d是否为回文数
{
    char _d[10],j=0,k;
    sprintf(_d,"%ld",d);                //将d转换为字符串_d
    k=strlen(_d)-1;
    while(j<k)
        if(_d[j++]!=_d[k--])
            return false;
    return true;
}
bool prime(long p)                        //该函数用于判断一个大于1的自然数p是否为质数
{
    int _p;
    for(_p=2;_p<=sqrt(p);_p++)
        if(!(p%_p))
            return false;
    return true;
}
