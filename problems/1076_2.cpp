#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> g[105], e[105];
int n, m;
int match[205];
bool vis[205], G[105][105];

bool matching(int v) {
	vis[v] = true;
	for (int i = 0; i < e[v].size(); ++i) {
		int u = e[v][i], w = match[u];
		if (w < 0 || !vis[w] && matching(w)) {
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	return false;
}

void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) if ((G[i][k] & G[k][j])) G[i][j] = true;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = true;
	}
	floyd();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (G[i][j]) e[i].pb(j + n);
		}
	}
	int ans = 0;
	memset(match, -1, sizeof match);
	for (int i = 1; i <= n; ++i) {
		if (match[i] < 0) {
			memset(vis, false, sizeof vis);
			if (matching(i)) ans++;
		}
	}
	printf("%d\n", n - ans);
	return 0;
}
