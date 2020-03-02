#include<iostream>
#include<math.h>
#include<stdio.h>
#include<map>
using namespace std;

long long a[100005];
long long p[100005];
long long minn;
int main()
{
    int n;
    scanf("%d",&n);
    minn = 9999LL;
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i],&p[i]);
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        minn = min(minn,p[i]);
        ans += minn*a[i];
    }
    cout<<ans<<endl;
}
