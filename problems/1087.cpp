#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define pb push_back
using namespace std;
const int N = 1005;
struct edge {
	int from, to;
} e[N];
vector<int> G[N];
int matching[N];
bool check[N];

bool dfs(int x) {
	for (int i = 0; i < G[x].size(); ++i) {
		int v = e[i].to;
		if (!check[v]) {
			check[v] = true;
			if (matching[v] == -1 || dfs(matching[v])) {
				matching[v] = x;
				matching[x] = v;
				return true;
			}
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
		G[a].pb(b);
		e[i].from = a, e[i].to = b;
	}
	int ans = 0;
	memset(matching, -1, sizeof matching);
	for (int i = 1; i <= nl; ++i) {
		if (matching[i] == -1) {
			memset(check, false, sizeof check);
			if (dfs(i)) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
