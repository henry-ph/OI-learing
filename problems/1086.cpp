#include<cstdio>
#include<algorithm>
#include<vector>
#define pb push_back
using namespace std;
const int N = 205, inf = 0x3f3f3f3f;
vector<int> v[N];
bool vis[N][N], flag[N];
int c[N][N], f[N][N], d, ans, cnt = 1, pos[N], n, m;;
void dfs(int x) {
	if (x == m) {
		for (int i = 1; i <= cnt; ++i) printf("%d ", pos[i]);
		printf("\n");
		int oppo = 0;
		for (int i = 1; i < cnt; ++i) {
			if (vis[i][i + 1]) d = min(d, c[i][i + 1] - f[i][i + 1]);
			else oppo = max(oppo, c[i][i + 1] - f[i][i + 1]);
		}
		d = min(d, oppo);
		if (!d) return;
		for (int i = 1; i < cnt; ++i) f[i][i + 1] += d;
		ans += d;
		return;
	}
	for (int i = 0; i < v[x].size(); ++i) {
		flag[v[x][i]] = true;
		pos[++cnt] = v[x][i];
		dfs(v[x][i]);
		cnt--;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int a, b, cos;
		scanf("%d%d%d", &a, &b, &cos);
		vis[a][b] = true, c[a][b] = cos;
		v[a].pb(b);
	}
	d = inf;
	pos[1] = 1;
	dfs(1);
	printf("%d\n", ans);
	return 0;
}

