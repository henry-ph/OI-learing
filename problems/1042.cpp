#include<bits/stdc++.h>
using namespace std;
const int N = 15, inf = 0x3f3f3f3f;
int g[N][N];
int main() {
	int n, m, k;
	while (~scanf("%d%d", &n, &m)) {
		memset(g, inf, sizeof g);
		for (int i = 1;i <= m; ++i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			g[u][v] = g[v][u] = c;
		}
		int x, y;
		scanf("%d%d", &x, &y);
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (i == j) continue;
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
				}
			}
		}
		if (g[x][y] == inf) printf("No path\n");
		else printf("%d\n", g[x][y]);
	}
	return 0;
}
