#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e7 + 5;
bool check[N];
int prime[N], factor[N];
void init() {
	memset(check, true, sizeof check);
	check[1] = false;
	int cnt = 1;
	for (int i = 2; i <= N; ++i) {
		if (!check[i]) continue;
		else {
			prime[cnt++] = i;
			for (int j = 2; j * i <= N; ++j) check[i * j] = false;
		}
	}
}
int main() {
	int t, n;
	init();
	scanf("%d", &t);
	while(t--) {
		int num = 0;
		memset(factor, 0, sizeof factor);
		scanf("%d", &n);
		int cnt = n;
		for (int i = 1; cnt != 1; ++i) {
			while (!(cnt % prime[i])) {
				num++;
				factor[prime[i]]++;
				cnt /= prime[i];
			}
		}
		int ans = 0;
		for (int i = 2; i <= num; ++i) {
			int tmp;
			for (int j = 1; j <= i; ++j) {
				for (int u = 2; u <= n; ++u) {
					if (!prime[u]) continue;
					
				}
			}
		}
	}
	return 0;
}
