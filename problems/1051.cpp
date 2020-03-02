#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1005;
vector<int> v[N];
queue<int> q;
bool vis[N];
int g[N][N];

void dfs(int x) {
	printf("%d ", x);
	for (int i = 0; i < v[x].size(); ++i) {
		int u = v[x][i];
		if (vis[u]) continue;
		vis[u] = true;
		dfs(u);
	} 
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &g[i][j]);
			if (g[i][j]) v[i].pb(j);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = true;
		dfs(i);
	}
	printf("\n");
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = true;
		q.push(i);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			printf("%d ", now);
			for (int j = 0; j < v[now].size(); ++j) {
				int u = v[now][j];
				if (vis[u]) continue;
				vis[u] = true;
				q.push(u);
			} 
		}
	}
	printf("\n");
	return 0;
}
