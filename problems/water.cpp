#include<cstdio>
const int N = 1005;
int main() {
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		if (a == m) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
