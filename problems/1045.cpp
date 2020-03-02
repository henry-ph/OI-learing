#include<bits/stdc++.h> 
using namespace std;
const int N = 105, inf = 0x3f3f3f3f;
int dis[N][N];
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) && n) {
		memset(dis, inf, sizeof dis); 
		for (int i = 1; i <= m; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			dis[u][v] = dis[v][u] = c;
		}
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
		printf("%d\n", dis[1][n]);
	}
	return 0;
}
