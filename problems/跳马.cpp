#include<iostream>
using namespace std;
int fx,fy,sum;
int map[8][8];
int u[8][2]={(1,2),(-1,2),(1,-2),(2,1),(2,-1),(-2,1),(-1,-2),(-2,-1)};
int dfs(int x,int y);
int print();
int dfs(int x,int y)
{
	if(map[x][y]==1) return 0;
	if(x==fx&&y==fy) print();
	for(int i=0;i<8;i++)
	{
		if(x+u[i][0]>=0&&x+u[i][0]<8&&y+u[i][1]>=0&&y+u[i][1]<8)
		{
			map[x][y]=1;
			dfs(x+u[i][0],y+u[i][1]);
		}
		x-=u[i][0];
		y-=u[i][1];
		map[x][y]=0;
	}
	return 0;
}
int print()
{
	sum++;
	return 0;	
}
int main()
{
	int sx,sy;
	cin>>sx>>sy>>fx>>fy;
	dfs(sx,sy);
	return 0;
}
