#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
bool map[200][200];
int x1[200]={0,-2,-2,-1,1,2,2,1,-1},y1[200]={0,-1,1,2,2,1,-1,-2,-2};
long long f[50][50];
int main()
{
    int x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    map[x+1][y+1]=true;
    for(int i=1;i<=8;i++)
        if(x1[i]+x>=0&&x1[i]+x<=n&&y1[i]+y<=m&&y1[i]+y>=0)
        map[x1[i]+x+1][y1[i]+y+1]=1;
        f[0][1]=1;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=m+1;j++)
            if(!map[i][j])
            f[i][j]=f[i-1][j]+f[i][j-1];
            else
            f[i][j]=0;
    printf("%lld",f[n+1][m+1]);
    return 0;
}
