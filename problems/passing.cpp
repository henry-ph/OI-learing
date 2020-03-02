#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
const int N = 2e6 + 5, inf = 0x3f3f3f3f;
int a[N], v[N], u[N];
int maxx, now;
void dfs(int x, int z) {
	if (v[x]) {
		if (u[x] == now) maxx = min(maxx, z - v[x]);
		return;
	}
	u[x] = now;
	v[x] = z;
	dfs(a[x], z + 1);
	return;
}
int main() {
	maxx = inf;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= n; ++i) {
		now = i;
		if (!v[i]) {
			u[i] = now;
			v[i] = 1;
			dfs(a[i], 2);
		}
	}
	printf("%d\n", maxx);
	return 0;
}
