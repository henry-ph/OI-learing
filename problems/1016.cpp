#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int k;
int a[N], ans[N];
bool vis[N];
void dfs(int x, int u) {
	if (x == 7) {
		for (int i = 1; i <= 6; ++i) printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = u; i <= k; ++i) {
		if (vis[i]) continue;
		vis[i] = true;
		ans[x] = a[i];
		dfs(x + 1, i);
		vis[i] = false;
	}
} 
int main() {
	while (scanf("%d", &k) && k) {
		memset(vis, false, sizeof vis);
		for (int i = 1; i <= k; ++i) scanf("%d", a + i);
		dfs(1, 1);
		printf("\n");
	}
	return 0;
}
