#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 70;
int stick[N], n, sum;
bool vis[N], flag;
bool comp(int a, int b) {
	if (a < b) return false;
	return true;
}
bool dfs(int d, int left_d, int step) {
	if (!left_d && !step) return true;
	if (!left_d) left_d = d;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		if (left_d >= stick[i]) {
			vis[i] = true;
			if (dfs(d, left_d - stick[i], step - 1)) return true;
			vis[i] = false;
			if (stick[i] == left_d || d == left_d || sum == left_d) break;
			while (stick[i] == stick[i + 1]) ++i;
		}
	}
	return false;
}
int main() {
	//freopen("1.txt", "r", stdin);
	while (scanf("%d", &n) && n) {
		flag = false;
		sum = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", stick + i);
			sum += stick[i];
		}
		sort(stick + 1, stick + n + 1, comp);
		int ans = 0;
		for (int i = stick[1]; i <= sum; i++) {
			memset(vis, false, sizeof vis);
			if (!(sum % i)) {
				if (dfs(i, 0, n)) {
					ans = i;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
