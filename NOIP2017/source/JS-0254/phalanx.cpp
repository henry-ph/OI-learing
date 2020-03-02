#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e3 + 5;
int a[N][N];

int main() {
	freopen("phalanx.in", "r", stdin);
	freopen("phalanx.out", "w", stdout);
	int n, m, q, cnt = 0;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) a[i][j] = ++cnt;
	while (q--) {
		int x, y, temp;
		scanf("%d%d", &x, &y);
		temp = a[x][y];
		printf("%d\n", temp);
		for (int i = m; i > y; --i) a[x][i - 1] = a[x][i], a[x][i] = 0;
		if (x != n)
			for (int i = x + 1; i > 1; --i) a[i - 1][m] = a[i][m], a[i][m] = 0;
		a[n][m] = temp;
		
	}
	return 0;
}
