#include<cstdio>
int g[105][105];
int n;
void print() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) printf("%d", g[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main() {
	int cnt = 1;
	bool f = false;
	scanf("%d", &n);
	int i = (n + 1) / 2, j = (n + 1) / 2;
	while (true) {
		print();
		g[i][j] = cnt;
		cnt++;
		if (i == n && j == n) break;
		if (j == n && i != 1) {
			f = !f, i--;
			continue;
		}
		if (j == 1 && i != n) {
			f = !f, i++;
			continue;
		}
		if (!f) j++;
		if (f) j--;
	}
	return 0;
}
