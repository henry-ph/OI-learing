#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int Mx=2e7+5;
int n;
int main()
{
    cin>>n;
    for(int i=int(sqrt(2*n)); i>=2; i--)
        {
            if(2*n%i==0)
                {
                    int x=(i+2*n/i-1)/2;
                    int y=2*n/i-x;
                    if(x<n&&x-y+1==i)  
                    cout<<y<<' '<<x<<endl;
                }
        }
    return 0;
}
