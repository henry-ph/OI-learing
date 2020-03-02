#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int x;
	int y;
	node(){}
	node(int _x,int _y){
		x=_x;
		y=_y;
	}
};
queue<node> q;
char gra[25][25];
int ans,w,h;
bool vis[25][25];
int main(){
	while(scanf("%d%d",&h,&w),w,h){
		memset(vis,false,sizeof vis);
		while(!q.empty()) q.pop();
		ans=0;
		int sx,sy;
		char x[25];
		for(int i=1;i<=w;++i){
			scanf("%s",x);
			for(int j=1;j<=h;++j) gra[i][j]=x[j-1];
		}
		for(int i=1;i<=w;++i){
			for(int j=1;j<=h;++j){
				if(gra[i][j]=='#') vis[i][j]=true;
				if(gra[i][j]=='@'){
					sx=i;
					sy=j;
				}
			}
		}
		q.push(node(sx,sy));
		while(!q.empty()){
			node cnt=q.front();
			vis[cnt.x][cnt.y]=true;
			q.pop();
			if(cnt.x+1<=w&&!vis[cnt.x+1][cnt.y]) q.push(node(cnt.x+1,cnt.y));
			if(cnt.x-1>=1&&!vis[cnt.x-1][cnt.y]) q.push(node(cnt.x-1,cnt.y));
			if(cnt.y+1<=h&&!vis[cnt.x][cnt.y+1]) q.push(node(cnt.x,cnt.y+1));
			if(cnt.y-1>=1&&!vis[cnt.x][cnt.y-1]) q.push(node(cnt.x,cnt.y-1));
 		}
		for(int i=1;i<=w;++i){
			for(int j=1;j<=h;++j) if(vis[i][j]&&gra[i][j]!='#') ans++;
		}
		printf("%d\n",ans);
	}
}
