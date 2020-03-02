#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1005, inf = 0x3f3f3f3f;
int dist[N][N];
vector<int> g[N];
bool vis[N];
int du[N];
struct node{
	int degree, step;
	node() {};
	node(int _degree, int _step) {
		degree = _degree, step = _step;
	}
}pos[N];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int main() {
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);
	int n, m, now, f_num = 0, ans = 0;
	scanf("%d%d", &n, &m);
	memset(dist, inf, sizeof dist);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if (dist[u][v] == inf) {
			g[u].push_back(v), g[v].push_back(u);
			du[u]++, du[v]++;
			if (du[u] > f_num) f_num = du[u], now = u;
			if (du[v] > f_num) f_num = du[v], now = v;
		} 
		dist[u][v] = dist[v][u] = min(dist[u][v], w);
	}
	pos[now] = node(f_num, 1);
	vis[now] = true;
	q.push(make_pair(f_num, now));
	while (!q.empty()) {
		pair<int, int> head = q.top(); q.pop();
		int u = head.second;
		int step = pos[u].step;
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			if (!vis[v]) {
				vis[v] = true;
				ans += dist[u][v] * pos[u].step;
				pos[v].step = pos[u].step + 1;
				q.push(make_pair(du[v], v));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
