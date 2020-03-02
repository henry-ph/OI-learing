#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e6;
bool vis[N];
int prime[N];
int len;
void unit() {
	for (int i = 2; i <= N; ++i) {
		if (!vis[i]) continue;
		else prime[len++] = i;
		for (int j = 2; i * j <= N; ++j) vis[i * j] = false;
	}
	return;
}
int main() {
	memset(vis, true, sizeof vis);
	unit();
	int n;
	while (scanf("%d", &n) && n) {
		for (int i = 0; prime[i] < n; ++i) {
			bool flag = false;
			int l = 0, r = len, mid;
			int sum = n;
			sum -= prime[i];
			while (l <= r) {
				mid = (l + r) / 2;
				if (prime[mid] == sum) {
					flag = true;
					break;
				}
				if (prime[mid] > sum) r = mid - 1;
				else l = mid + 1;
			}
			if (flag) {
				printf("%d = %d + %d\n", n, prime[i], sum);
				break;
			} 
		} 
	}
	return 0;
}
