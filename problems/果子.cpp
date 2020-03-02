#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
priority_queue <int,vector<int>,greater<int> >  data;//定义一个从小到大的堆 ，底层容器必须为vector 
int n;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
      {int x;
          scanf("%d",&x);
          data.push(x);
      }    
      int k=0;
      int ans=0,sum=0;
      while (data.size()>1)//当堆中元素只有一个时说明合并完了，结束算法 
      {
          int x=data.top();//每次从头取出最小的两个元素合并，计算代价，然后将合并后的元素加入堆中 
          data.pop();
          int y=data.top();
          data.pop();
          sum=x+y;
          ans+=sum;
          data.push(sum);
          sum=0;
          k++;
      }
      printf("%d\n",ans);//输出总代价 
      return 0;
}
