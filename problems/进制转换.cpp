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
        for (i=0;;i++){                         //�Ƚ���ת����m���� 
            s[i]+=(n%m)+0;
            n/=m;
            if (s[i]==0&&n==0) 
            {
                break;
            }
         }
         for (int j=0;j<=i+1;j++){                //С�ڵ���i+1��Ϊ�˷�ֹ��λ��Ӱ�죻 
             if (j%2&&s[j]!=0){                  //ż�����ݵĵط����䣬�������ݱ�Ϊm-s[j]����һλ��+1��
              s[j]=m-s[j];
              s[j+1]+=1;
              }
              while (s[j]>=m){                  //��λ 
                  s[j]-=m;
                  s[j+1]+=1;
              }
         }
         for (int k=i+1;k>=i-1;k--){             //ͳ�Ƶ����ж���λ����ֹǰ������0�� 
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
    m=0-m;                        //������̫�ô�����ʼ���������� 
    if (n<0){
        n=0-n;
        for (int i=0;;i++){       //��������n�Ǹ���������������Ϸ����ѽ��ͣ� 
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
