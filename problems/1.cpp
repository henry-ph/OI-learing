#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
 
using namespace std;
 
const int inf = 0x3f3f3f3f;
 
int dp[60000][15];
int dist[15][15];
int three[15] = {0, 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int city[60000][15];
 
int main()
{
    int n, m, u, v, w;
    memset (city, inf, sizeof(city));
    for (int i = 0; i < 59059; ++i)
    {
        int tmp = i;
        for (int j = 1; j <= 10; ++j)
        {
            city[i][j] = tmp % 3;
            tmp /= 3;
        }
    }
    while (~scanf("%d%d", &n, &m))
    {
        memset (dist, inf, sizeof(dist));
        memset (dp, inf, sizeof(dp));
        for (int i = 1; i <= n; ++i)
        {
            dp[three[i]][i] = 0;
        }
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = dist[u][v];
        }
        int ans = inf;
        for (int i = 0; i < three[n + 1]; ++i)
        {
            bool is_end = 1;
            for (int j = 1; j <= n; ++j)
            {
                if (city[i][j] == 0)
                {
                    is_end = 0;
                }
                for (int k = 1; k <= 10; ++k)
                {
                    if (city[i][j] == 2)
                    {
                        continue;
                    }
                    dp[i + three[j]][j] = min(dp[i + three[j]][j], dp[i][k] + dist[k][j]);
                }
            }
            if (is_end)
            {
                for (int j = 1; j <= n; ++j)
                {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        if (ans == inf)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n", ans);
    }
    return 0;
}
