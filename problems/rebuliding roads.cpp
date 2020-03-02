#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 160, inf = 0x3f3f3f3f;
int dp[N][N], s[N], b[N];
bool f[N];
int p;
void dfs(int root) {
	int k, temp;
	for (int i = 0; i <= p; ++i) dp[root][i] = inf;
	dp[root][1] = 0;
	k = s[root];
	while (k) {
		dfs(k);
		for (int i = p; i >= 1; --i) {
			temp = dp[root][i] + 1;
			for (int j = 1; j < i; ++j) {
				temp = min(temp, dp[k][i - j] + dp[root][j]);
			}
			dp[root][i] = temp;
		}
		k = b[k];
		//printf("%d\n", k);
	}
	return;
}
int main() {
	memset(f, false, sizeof f);
	memset(s, 0, sizeof s);
	int n, root, ans;
	scanf("%d%d", &n, &p);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		f[y] = true;
		b[y] = s[x];
		s[x] = y;
	}
	for (int i = 1; i <= n; ++i) {
		if (!f[i]) {
			root = i;
			break;
		}
	}
	dfs(root);
	ans = dp[root][p];
	for (int i = 1; i <= n; ++i) ans = min(ans, dp[i][p] + 1);
	printf("%d\n", ans);
	return 0;
}
