#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX = 1e7;
int map[10][10];
bool heng[10][10],shu[10][10],gong[10][10],un[10][10],flag;
int sum, time;
const int w[9][9]=
{{6,6,6,6, 6,6,6,6,6}
,{6,7,7,7, 7,7,7,7,6}
,{6,7,8,8, 8,8,8,7,6}
,{6,7,8,9, 9,9,8,7,6}
,{6,7,8,9,10,9,8,7,6}
,{6,7,8,9, 9,9,8,7,6}
,{6,7,8,8, 8,8,8,7,6}
,{6,7,7,7, 7,7,7,7,6}
,{6,6,6,6, 6,6,6,6,6}
};
void print(){
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j) printf("%d ",map[i][j]);
        printf("\n");
    }
}
int ju(int x,int y){
    if(x<=3&&y<=3) return 1;
    if(x>3&&x<=6&&y<=3) return 2;
    if(x>6&&y<=3) return 3;
    if(x<=3&&y>3&&y<=6) return 4;
    if(x>3&&x<=6&&y>3&&y<=6) return 5;
    if(x>6&&y>3&&y<=6) return 6;
    if(x<=3&&y>6) return 7;
    if(x>3&&x<=6) return 8;
    else return 9;
}
void dfs(int x,int y){
	time++;
	if (time >= MAX) return;
    //if(flag) return;
    int ge=ju(x,y);
    if(x==10){
        int ans=0;
        for(int i=1;i<=9;++i){
            for(int j=1;j<=9;++j){
                ans+=map[i][j]*w[i-1][j-1];
            }
        }
        flag=true;
        //print();
        sum=max(sum,ans);
        return;
    }
    if(y==10){
        dfs(x+1,1);
        return;
    }
    if(un[x][y]) {
        dfs(x,y+1);
        return;
    }
    //print();
    //getchar();
    for(int i=1;i<=9;++i){
        if(heng[x][i]||shu[y][i]||gong[ge][i]) continue;
        else{
            map[x][y]=i;
            heng[x][i]=true;
            shu[y][i]=true;
            gong[ge][i]=true;
            dfs(x,y+1);
            //if(flag) return;
            heng[x][i]=false;
            shu[y][i]=false;
            gong[ge][i]=false;
        }
    }
}
int main(){
    flag=false;
    memset(heng,false,sizeof heng);
    memset(shu,false,sizeof shu);
    memset(gong,false,sizeof gong);
    memset(un,false,sizeof un);
    for(int i=1;i<=9;++i){
        for(int j=1;j<=9;++j) {
            scanf("%d",&map[i][j]);
            if(map[i][j]) {
                int ge=ju(i,j);
                un[i][j]=true;
                heng[i][map[i][j]]=true;
                shu[j][map[i][j]]=true;
                gong[ge][map[i][j]]=true;
            }
        }
    }
    dfs(1,1);
    if(!flag) printf("-1\n");
    else printf("%d\n",sum);
    return 0;
}
