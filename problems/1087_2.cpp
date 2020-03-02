#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back
using namespace std;
const int N = 2005;
int v;
vector<int> g[N];
int matching[N];
bool vis[N];
bool dfs(int v) {
	vis[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i], w = matching[u];
		if (w < 0 || !vis[w] && dfs(w)) {
			matching[u] = v;
			matching[v] = u;
			return true;
		}
	}
	return false;
}
int main() {
	int nl, nr, m;
	scanf("%d%d%d", &nl, &nr, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b + nl);
		g[b + nl].pb(a);
	}
	int ans = 0;
	memset(matching, -1, sizeof matching);
	for (int i = 1; i <= nl; ++i) {
		if (matching[i] < 0) {
			memset(vis, false, sizeof vis);
			if (dfs(i)) ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= nl; ++i) {
		if (matching[i] < 0) printf("0 ");
		else printf("%d ", matching[i] - nl);
	}
	printf("\n");
	return 0;
}
