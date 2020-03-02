    #include <stdio.h>  
    #include <string.h>  
    #include <algorithm>  
    using namespace std;  
      
    int n,p,root;  
    int dp[155][155];  
    int father[155],son[155],brother[155];  
      
    void dfs(int root)  
    {  
        int i,j,k,tem;  
        for(i = 0; i<=p; i++)  
            dp[root][i] = 10000000;  
        dp[root][1] = 0;  
        k = son[root];  
        while(k)  
        {  
            dfs(k);  
            for(i = p; i>=1; i--)  
            {  
                tem = dp[root][i]+1;  
                for(j = 1; j<i; j++)  
                    tem = min(tem,dp[k][i-j]+dp[root][j]);  
                dp[root][i] = tem;  
            }  
            k = brother[k];  
        }  
    }  
      
    int solve()  
    {  
        int ans,i;  
        dfs(root);  
        ans = dp[root][p];  
        for(i = 1; i<=n; i++)//除了根节点，其他节点要想成为独立的跟，必先与父节点断绝关系，所以要先加1  
            ans = min(ans,dp[i][p]+1);  
        return ans;  
    }  
      
    int main()  
    {  
        int i,x,y;  
        while(~scanf("%d%d",&n,&p))  
        {  
            memset(father,0,sizeof(father));  
            memset(son,0,sizeof(son));  
            for(i = 1; i<n; i++)  
            {  
                scanf("%d%d",&x,&y);  
                father[y] = 1;//记录该点有父亲节点  
                brother[y] = son[x];//记录兄弟节点  
                son[x] = y;//记录子节点  
            }  
            for(i = 1; i<=n; i++)  
            {  
                if(!father[i])//找到根节点  
                {  
                    root = i;  
                    break;  
                }  
            }  
            printf("%d\n",solve());  
        }  
      
        return 0;  
    }  
