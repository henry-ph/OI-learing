#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long b,p,k;
long long ans;
long long Mod(long long t){
     if (t==1) return b%k;
     ans=Mod(t/2);
     ans=(ans*ans)%k;  
     if (t%2==1) ans=(ans*(b%k))%k;  
     return ans;
}
int main(){
    cin>>b>>p>>k;
    cout<<b<<'^'<<p<<" mod "<<k<<'='<<Mod(p)<<endl;
    return 0;
}
