#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define pb push_back
using namespace std;
const int N = 205, inf = 0x3f3f3f3f;
struct edge {
	int to, cap, rev;
};
vector <edge> g[N];

bool vis[N];

void add(int from, int to, int cap) {
	g[from].pb((edge){to, cap, g[to].size()});
	g[to].pb((edge){from, 0, g[from].size() - 1});
	return;
}

int dfs(int v, int t, int f) {
	if (v == t) return f;
	vis[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		edge &e = g[v][i];
		if (!vis[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	while (true) {
		memset(vis, false, sizeof vis);
		int f = dfs(s, t, inf);
		if (!f) return flow;
		flow += f;
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	printf("%d\n", max_flow(1, m));
	return 0;
}
