#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include<cstdio>
using namespace std;
struct node {
    int x,y;
    int step;
};
char map[50][50];
int vis[50][50];
int jx[]= {0,1,0,-1};
int jy[]= {1,0,-1,0};
//设置为右上左下
int jr[]= {1,0,3,2};
int jl[]= {3,0,1,2};
int cnt,d;
char sx,sy,ex,ey;
int w,h;
void dfs_left(int d,int x,int y)
{
    int i,j;
    if(x==ex&&y==ey) {
        printf("%d ",cnt);
        return ;
    }
    cnt++;
    for(j=0; j<4; j++) {
        i=(d+jl[j])%4;
        int dx=x+jx[i];
        int dy=y+jy[i];
        if(dx>=0&&dx<h&&dy>=0&&dy<w&&map[dx][dy]!='#') {
            dfs_left(i,dx,dy);
            return;
        }
    }
}
void dfs_right(int d,int x,int y)
{
    int i,j;
    if(x==ex&&y==ey) {
        printf("%d ",cnt);
        return ;
    }
    cnt++;
    for(j=0; j<4; j++) {
        i=(d+jr[j])%4;
        int dx=x+jx[i];
        int dy=y+jy[i];
        if(dx>=0&&dx<h&&dy>=0&&dy<w&&map[dx][dy]!='#') {
            dfs_right(i,dx,dy);
            return;
        }
    }
}
void bfs(int x,int y)
{
    int i;
    memset(vis,0,sizeof(vis));
    queue<node >q;
    struct node t,f;
    t.x=x;
    t.y=y;
    t.step=0;
    q.push(t);
    vis[t.x][t.y]=1;
    while(!q.empty()) {
        t=q.front();
        q.pop();
        if(t.x==ex&&t.y==ey) {
            printf("%d\n",t.step+1);
            return ;
        }
        for(i=0; i<4; i++) {
            f.x=t.x+jx[i];
            f.y=t.y+jy[i];
            if(f.x>=0&&f.x<h&&f.y>=0&&f.y<w&&map[f.x][f.y]!='#'&&!vis[f.x][f.y]) {
                vis[f.x][f.y]=1;
                f.step=t.step+1;
                q.push(f);
            }
        }
    }
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&w,&h);
        memset(vis,0,sizeof(vis));
        for(i=0; i<h; i++) {
            scanf("%s",map[i]);
            for(j=0; j<w; j++) {
                if(map[i][j]=='S') {
                    sx=i;
                    sy=j;
                }
                if(map[i][j]=='E') {
                    ex=i;
                    ey=j;
                }
            }
        }
        if(sx==0) d=0;
        if(sx==h-1) d=2;
        if(sy==0) d=1;
        if(sy==w-1) d=3;
        cnt=1;
        dfs_left(d,sx,sy);
        cnt=1;
        dfs_right(d,sx,sy);
        bfs(sx,sy);
    }
    return 0;
}
