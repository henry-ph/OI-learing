#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	sort (a + 1, a + n + 1);
	printf("%d %d\n", a[1], a[n]);
	return 0;
}
