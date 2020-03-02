#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX = 59049, inf = 0x3f3f3f3f;
int dp[MAX + 5][15], map[15][15], city[MAX + 5][15];
int tri[13] = {0, 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int main() {
	int m, n;
	memset(city, inf, sizeof city);
	for (int i = 0; i < MAX; ++i) {
		int tmp = i;
		for (int j = 1; j <= 10; ++j) {
			city[i][j] = tmp % 3;
			tmp /= 3;
		}
	}
	while (~scanf("%d%d", &n, &m)) {
		int ans = inf;
		memset(map, inf, sizeof map);
		memset(dp, inf, sizeof dp);
		for (int i = 1; i <= n; ++i) dp[tri[i]][i] = 0;
		dp[0][0] = 0;
		for (int i = 1; i <= m; ++i) {
			int a, b, k;
			scanf("%d%d%d", &a, &b, &k);
			map[a][b] = min(map[a][b], k);
			map[b][a] = map[a][b];
		}
		for (int i = 0; i < tri[n + 1]; ++i) {
			bool f = true;
			for (int j = 1; j <= n; ++j) {
				if (city[i][j] == 0) f = false;
				if (city[i][j] == 2) continue;
				for (int k = 1; k <= n; ++k) {
					dp[i + tri[j]][j] = min(dp[i + tri[j]][j], dp[i][k] + map[k][j]);
				}
			}
			if (f) {
				for (int j = 1; j <= n; ++j) {
					ans = min(ans, dp[i][j]);
				}
			}
		}
		if (ans == inf) {
			printf("-1\n"); 
			continue;
		}
		else printf("%d\n", ans);
	}
	return 0;
}
