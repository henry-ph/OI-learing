#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e4 + 5;
bool vis[N];
int prime[N];
void unit() {
	for (int i = 2; i <= 10000; ++i) {
		if (!vis[i]) continue;
		for (int j = 2; i * j <= 10000; ++j) vis[i * j] = false;
	}
	return;
}
int main() {
	memset(vis, true, sizeof vis);
	unit();
	int n = 0, ans;
	for (int i = 2; i < N; ++i) if (vis[i]) prime[++n] = i;
	int a;
	while (scanf("%d", &a) && a) {
		ans = 0;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum = a;
			if (prime[i] > a) break;
			for (int j = i; j <= n; ++j) {
				sum -= prime[j];
				if (sum <= 0) {
					if (!sum) ans++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
