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
        for(i = 1; i<=n; i++)//���˸��ڵ㣬�����ڵ�Ҫ���Ϊ�����ĸ��������븸�ڵ�Ͼ���ϵ������Ҫ�ȼ�1  
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
                father[y] = 1;//��¼�õ��и��׽ڵ�  
                brother[y] = son[x];//��¼�ֵܽڵ�  
                son[x] = y;//��¼�ӽڵ�  
            }  
            for(i = 1; i<=n; i++)  
            {  
                if(!father[i])//�ҵ����ڵ�  
                {  
                    root = i;  
                    break;  
                }  
            }  
            printf("%d\n",solve());  
        }  
      
        return 0;  
    }  
