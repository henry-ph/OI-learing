#include<cstdio>
#include<algorithm>
using namespace std;
int a[10005];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 1; i <= k; ++i) {
		int tar;
		bool f = false;
		scanf("%d", &tar);
		int l = 0, r = n - 1;
		while (r - l > 1) {
			int mid = l + r >> 1;
			if (a[mid] == tar) {
				printf("%d ", mid);
				f = true;
			}
			if (a[mid] > tar) r = mid;
			else l = mid; 
		}
		if (!f) printf("-1 ");
	}
	printf("\n");
	return 0;
}
