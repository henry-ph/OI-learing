#include <cstdio>
#include <cstring>
#include<iostream>
#define N 103
using namespace std;

int fun(int b[N], int n)
{
    int i, max, c;

    c = 0;
    max = 0;
    for(i=1; i<=n; i++)
    {
        if(c > 0)
            c = c+b[i];
        else c = b[i];
        if(max < c)
            max = c;
    }
    return max;
}

int main()
{
    int i, j, n, max, sum, k;
    int a[N][N], b[N];

    scanf("%d", &n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &a[i][j]);
    max = 0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            b[j] = 0;
        for(j=i;j <=n; j++)
        {
            for(k=1; k<=n; k++)
                b[k]+=a[j][k];
            sum = fun(b, n);
            if(max < sum)
                max = sum;
        }

    }
    cout<<max<<endl;
    return 0;
}
