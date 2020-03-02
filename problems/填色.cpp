#include<cstdio>
#include<iostream>
using namespace std;
struct a0001{
    int x,y;
}list[1000];
int map[32][32],n,l,r;//l,r为队列的指针

void reload(){
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) 
            cin>>map[i][j];
}

void bfs(){
    a0001 temp;
    l=1;r=0;
    while(r<l){
            r++;
            temp=list[r];
            if (map[temp.x][temp.y]!=0) continue;//已经填过，无论01
            if (temp.x<=0||temp.x>n||temp.y<=0||temp.y>n) continue;//边界
            map[temp.x][temp.y]=2;
            if (map[temp.x][temp.y-1]==0) {l++;list[l].x=temp.x;list[l].y=temp.y-1;}
            if (map[temp.x][temp.y+1]==0) {l++;list[l].x=temp.x;list[l].y=temp.y+1;}
            if (map[temp.x-1][temp.y]==0) {l++;list[l].x=temp.x-1;list[l].y=temp.y;}
            if (map[temp.x+1][temp.y]==0) {l++;list[l].x=temp.x+1;list[l].y=temp.y;}
        }
}

void work(){
    bool check;
    a0001 temp;
    for (int i=1;i<=n;i++){//只是因为我懒，直接一个for4个if拉倒，if中的是确定边界处为0的点，作为起点
        if (map[i][1]==0){         
            list[1].x=i;
            list[1].y=1;
            bfs();
        }
        if (map[i][n]==0){         
            list[1].x=i;
            list[1].y=n;
            bfs();
        }
        if (map[1][i]==0){         
            list[1].x=1;
            list[1].y=i;
            bfs();
        }
        if (map[n][i]==0){         
            list[1].x=n;
            list[1].y=i;
            bfs();
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            switch (map[i][j]){//反向输出
                case 0:{
                    cout<<"2 ";
                    break;
                }
                case 2:{
                    cout<<"0 ";
                    break;
                }
                default:{
                    cout<<"1 ";
                }
            }
        }
        cout<<endl;
    }
}

int main(){
    reload();
    work();
    return 0;
}
