#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1000000;
int s[maxn];
int ans;
int work (long long int& n,int& m){
    memset(s,0,sizeof(s));
    while (n>0){
        int i;
        for (i=0;;i++){                         //先将它转换成m进制 
            s[i]+=(n%m)+0;
            n/=m;
            if (s[i]==0&&n==0) 
            {
                break;
            }
         }
         for (int j=0;j<=i+1;j++){                //小于等于i+1是为了防止进位的影响； 
             if (j%2&&s[j]!=0){                  //偶数次幂的地方不变，奇数次幂变为m-s[j]，上一位再+1；
              s[j]=m-s[j];
              s[j+1]+=1;
              }
              while (s[j]>=m){                  //进位 
                  s[j]-=m;
                  s[j+1]+=1;
              }
         }
         for (int k=i+1;k>=i-1;k--){             //统计到底有多少位，防止前面多输出0； 
                  if (s[k]!=0){
                      ans=k;
                      break;
                  }
         }
    }
}
int main(){
    long long int n,nn;
    int m,mm;
    bool cs;
    cin>>n>>m;
    nn=n;
    m=0-m;                        //负数不太好处理，初始化成正数； 
    if (n<0){
        n=0-n;
        for (int i=0;;i++){       //这就是如果n是负数的两种情况，上方都已解释； 
            if (pow(m,i)>=n){
                if (i%2){
                    s[i]+=1;
                    break;
                }
                if (i%2==0){
                cs=true;
                n=pow(m,i)-n;
                break;
                }
            }
        }
    }
    work(n,m);
    if (cs) ans--;
    cout<<nn<<"=";
    for (int i=ans;i>=0;i--){
        if (s[i]==10) printf("A");
        else if (s[i]==11) printf ("B");
        else if (s[i]==12) printf ("C");
        else if (s[i]==13) printf ("D");
        else if (s[i]==14) printf ("E");
        else if (s[i]==15) printf ("F");
        else if (s[i]==16) printf ("G");
        else if (s[i]==17) printf ("H");
        else if (s[i]==18) printf ("I");
        else if (s[i]==19) printf ("J");
        else if (s[i]==20) printf ("K");
        else printf ("%d",s[i]);
    }
    m=0-m;
    cout<<"("<<"base"<<m<<")";
    return 0;
}
