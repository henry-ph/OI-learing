#include<cstdio>
const int N = 205;
int a[N], b[N];
int res[5][5] = {{0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0}};
int main() {
	int n, na, nb, ansa = 0, ansb = 0;
	scanf("%d%d%d", &n, &na, &nb);
	for (int i = 0; i < na; ++i) scanf("%d", a + i);
	for (int i = 0; i < nb; ++i) scanf("%d", b + i);
	for (int i = 0; i < n; ++i) {
		int cnta = i % na;
		int cntb = i % nb;
		ansa += res[a[cnta]][b[cntb]];
		ansb += res[b[cntb]][a[cnta]];
	}
	printf("%d %d\n", ansa, ansb);
	return 0;
}
