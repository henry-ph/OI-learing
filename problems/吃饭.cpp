#include <iostream>//搜索 考虑每件是否选入
using namespace std;
int money,num,ans=0;
int v[110];
void dfs(int n,int cmoney) {  //       start from dfs(num,money)
  if (cmoney==0) ans++;
  else if (n>0&&cmoney>0) {
           dfs(n-1,cmoney);
           dfs(n-1,cmoney-v[n]);
          }

  }
int main() {
    cin>>num>>money;
    for (int i=1;i<=num;i++) cin>>v[i];
    ans=0;
    dfs(num,money);
    cout<<ans<<endl;
}
