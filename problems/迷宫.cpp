#include<stdio.h>
#include<string.h>
char a[110][110];
bool mp[110][110];
int n,sa,sb,ta,tb,fa[4]={1,-1,0,0},fb[4]={0,0,1,-1};
bool F;
void dfs(int xa,int xb)
{
mp[xa][xb]=true;
if(xa==ta&&xb==tb)
{
F=true;
return ;
}
int ya,yb;
for(int i=0;i<=3;i++)
{
ya=xa+fa[i];yb=xb+fb[i];
if(!F&&ya>=0&&ya<=n-1&&yb>=0&&yb<=n-1&&a[ya][yb]=='.'&&!mp[ya][yb])
dfs(ya,yb);
}
return;
}
int main()
{
int T;
scanf("%d",&T);
while(T--)
{
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%s",a[i]);
scanf("%d%d%d%d",&sa,&sb,&ta,&tb);
if(a[sa][sb]=='#')
{
printf("NO\n");
continue;
}
else if(a[ta][tb]=='#')
{
printf("NO\n");
continue;
}
F=false;
memset(mp,false,sizeof(mp));
dfs(sa,sb);
if(F)printf("YES\n");
else printf("NO\n");
}
return 0;
}
