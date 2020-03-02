#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm> 
using namespace std;
int n,m,p,t,j,nex[105];
int main()
{
    cin >> n >> m; 
    for(int i = 1; i < n; i++)
        nex[i] = i+1; 
    for(nex[0]=nex[n]=1, p=n, t=0, j=1; t<n; cout << nex[p] << ' ',t++,nex[p] = nex[nex[p]],j = 1)
        while(j++ < m)
            p = nex[p];
     return 0;
}
