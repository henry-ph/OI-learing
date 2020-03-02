#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1005;
vector<int> g[N], rg[N];
bool vis[N], happen[N];
int any[N], must[N];
priority_queue<int, vector<int>, greater<int> > q;

void impossible(int x) {
	for (int i = 0; i < rg[x].size(); ++i) {
		vis[rg[x][i]] = true;
		impossible(rg[x][i]);
	}
}

void possible(int x) {
	happen[x] = true;
	for (int i = 0; i < g[x].size(); ++i) {
		int u = g[x][i];
		if (vis[u]) continue;
		possible(u);
	}
}
int main() {
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		rg[v].pb(u);
	}
	for (int i = 1; i <= d; ++i) {
		scanf("%d", must + i);
		q.push(must[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) if (rg[i].empty()) any[++cnt] = i;
	for (int i = 1; i <= n; ++i) {
		memset(vis, false, sizeof vis);
		memset(happen, false, sizeof happen);
		impossible(i);
		for (int j = 1; j <= cnt; ++j) {
			if (vis[j]) continue;
			possible(any[j]);
		}
		for (int j = 1; j <= d; ++j) {
			if (i == must[j]) continue;
			if (!happen[must[j]]) {
				q.push(i);
				break;
			} 
		}
	}
	while (!q.empty()) {
		int u = q.top();
		q.pop();
		printf("%d ", u);
	}
	printf("\n");
	return 0;
}
