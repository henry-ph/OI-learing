#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 5;
long long box[N], num[N];
int main() {
	long long n, x, ans = 0;
	scanf("%lld%lld", &n, &x);
	for (int i = 1; i <= n; ++i) scanf("%lld", box + i);
	for (int i = 1; i < n; ++i) num[i] = box[i + 1] + box[i];
	for (int i = 1; i < n; ++i) {
		if (num[i] > x) {
			int cnt = num[i] - x;
			ans += cnt;
			num[i] -= cnt;
			num[i + 1] -= cnt;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
