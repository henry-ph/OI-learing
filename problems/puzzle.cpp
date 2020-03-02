#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int maze[10][10],book[10][10],n,m,t,sx,sy,ex,ey,ans=0;//bookΪ�������
void dfs(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m||maze[x][y]==1||book[x][y]==1)//���Խ�磬װ���ϰ����Ѿ�·������ֹͣ������
    {
        return;
    }
    else if(x==ex&&y==ey)//�����յ㣬�𰸼�1
    {
        ans++;
        return;
    }
    else
    {
        book[x][y]=1;//���ñ��
        dfs(x+1,y);//�������>_>
        dfs(x,y+1);
        dfs(x-1,y);
        dfs(x,y-1);
        book[x][y]=0;//���ݣ����ñ��
    }
}
void solve()
{
    memset(maze,0,sizeof(maze));
    memset(book,0,sizeof(book));
    scanf("%d %d %d",&n,&m,&t);
    scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
    sx--;//���Ǵ��㿪ʼ������Ҫ����
    sy--;
    ex--;
    ey--;
    for(int i=0;i<t;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        maze[x-1][y-1]=1;//���Թ��б���ϰ�
    }
    dfs(sx,sy);
    printf("%d",ans);
}
int main()
{
    solve();
    return 0;
}
