#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define pb push_back
using namespace std;
const int N = 205, M = 1005, inf = 0x3f3f3f3f;
int e[M][M], dist[M];
vector<int> v[M];
queue<int> q;
bool vis[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(dist, inf, sizeof dist);
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
		v[a].pb(b), v[b].pb(a);
	}
	int x, y;
	scanf("%d%d", &x, &y);
	q.push(x);
	dist[x] = 0;
	vis[x] = true;
	while (!q.empty()) {
		int now = q.front(), next;
		q.pop();
		if (now == y) {
			printf("%d\n", dist[y]);
			return 0;
		}
		for (int i = 0; i < v[now].size(); ++i) {
			if (dist[v[now][i]] > dist[now] + e[now][v[now][i]]) dist[v[now][i]] = dist[now] + e[now][v[now][i]];
		}
		int num = inf;
		for (int i = 0; i < n; ++i) {
			if (dist[i] < num && !vis[i]) next = i, num = dist[i];
		}
		vis[next] = true;
		q.push(next);
	}
	return 0;
}
