#include<bits/stdc++.h>
using namespace std;
bool f[1005];
int ans[105];
int main() {
	memset(f, false, sizeof(f));
	int n, len = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		if (!f[a]) {
			f[a] = true;
			ans[len++] = a;
		}
	}
	sort (ans, ans + len);
	printf("%d\n", len);
	for (int i = 0; i < len; ++i) printf("%d ", ans[i]);
	printf("\n");
	return 0; 
}
