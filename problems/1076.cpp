#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> g[105];
int sum, n, m;;
bool vis[105];

void dfs(int x) {
	for (int i = 0; i < g[x].size(); ++i) {
		if (vis[g[x][i]]) continue;
		vis[g[x][i]] = true;
		dfs(g[x][i]);
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
	}
	int ans = 0;
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = true;
		ans++;
		dfs(i);
	}
	printf("%d\n", ans);
	return 0;
}
