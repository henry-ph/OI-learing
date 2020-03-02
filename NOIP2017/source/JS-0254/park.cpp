#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
const int N = 5e5 + 5, inf = 0x3f3f3f3f;
struct edge{
	int to, next, w;
	edge() {};
	edge(int _to, int _next, int _w) {
		to = _to, next = _next, w = _w;
	}
}e[N];

struct Edge{
	int to, next, w;
	Edge() {};
	Edge(int _to, int _next, int _w) {
		to = _to, next = _next, w = _w;
	}
}rev[N];

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
queue<int> q;
int p, ecnt, revcnt, ans, n, m, k;
int dis[N], head[N], head_rev[N], dist[N];
bool inq[N];
int vis[N];

void add(int u, int v, int w) {
	e[++ecnt] = edge(v, head[u], w);
	head[u] = ecnt;
}

void add_rev(int u, int v, int w) {
	rev[++revcnt] = Edge(u, head_rev[v], w);
	head_rev[v] = revcnt;
}

void dfs(int u, int sum, int lim) {
	if (u == n && sum <= lim) ans = (ans + 1) % p;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].to, w = e[i].w;
		if (dist[v] + sum <= lim) 
			dfs(v, sum + w, lim);
	}
}
int main() {
	freopen("park.in", "r", stdin);
	freopen("park.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		bool flag = false;
		while (!q.empty()) q.pop();
		while (!Q.empty()) Q.pop();
		memset(dis, inf, sizeof dis);
		memset(dist, inf, sizeof dist);
		scanf("%d%d%d%d", &n, &m, &k, &p);
		for (int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add_rev(u, v, w);
		}
		dis[1] = 0;
		q.push(1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			inq[u] = false;
			if (vis[u]++ > n) {
				flag = true;
				break;
			}
			for (int i = head[u]; i; i = e[i].next) {
				int v = e[i].to, w = e[i].w;
				if (!inq[v]) {
					if (dis[v] >= dis[u] + w) {
						dis[v] = dis[u] + w;
						inq[v] = true;
						q.push(v);
					}
				}
			}
		}
		if (flag) {
			puts("-1");
			continue;
		}
		dist[n] = 0;
		Q.push(make_pair(dist[n], n));
		while (!Q.empty()) {
			pair<int, int> now = Q.top();
			Q.pop();
			int u = now.second;
			for (int i = head_rev[u]; i; i = rev[i].next) {
				int v = rev[i].to, w = rev[i].w;
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					Q.push(make_pair(dist[v], v));
				}
			}
		}
		dfs(1, 0, dis[n] + k);
		printf("%d\n", ans);
	}
	return 0;
}
