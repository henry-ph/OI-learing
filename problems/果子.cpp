#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
priority_queue <int,vector<int>,greater<int> >  data;//����һ����С����Ķ� ���ײ���������Ϊvector 
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
      while (data.size()>1)//������Ԫ��ֻ��һ��ʱ˵���ϲ����ˣ������㷨 
      {
          int x=data.top();//ÿ�δ�ͷȡ����С������Ԫ�غϲ���������ۣ�Ȼ�󽫺ϲ����Ԫ�ؼ������ 
          data.pop();
          int y=data.top();
          data.pop();
          sum=x+y;
          ans+=sum;
          data.push(sum);
          sum=0;
          k++;
      }
      printf("%d\n",ans);//����ܴ��� 
      return 0;
}
