#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int inf = 0x3f3f3f, N = 1e4 + 5;
int ans = inf, n, m;
int mins[N], minv[N];
void dfs(int lev, int h, int r, int s, int v) {
	if (!lev) {	
		if (v == n) {
			ans = min(ans, s);
		}
		return;
	}
	if (s + mins[lev - 1] > ans || v + minv[lev - 1] > n || s + 2 * (n - v) / r >= ans) return;
	for (int i = r - 1; i >= lev; --i) {
		if (lev == m) s = i * i;
		int hm = min((n - v - minv[lev - 1]) / (i * i), h - 1);
		for (int j = hm; j >= lev; --j) {
			dfs(lev - 1, j, i, s + 2 * i * j, v + i * i * j);
		}
	}
	return;
} 
int main() {
	scanf("%d%d", &n, &m);
	int rmax, hmax;
	rmax = (int)sqrt(n);
	hmax = n;
	for (int i = 1; i <= m; ++i) {
		minv[i] = minv[i - 1] + i * i * i;
		mins[i] = mins[i - 1] + 2 * i * i;
	} 
	dfs(m, hmax, rmax, 0, 0);
	if (ans == inf) printf("0\n");
	else printf("%d\n", ans);
	return 0;
}
