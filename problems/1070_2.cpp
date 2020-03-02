#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 205, inf = 0x3f3f3f3f;
int dist[N][N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(dist, inf, sizeof dist);
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = dist[b][a] = c;
	}
	int x, y;
	scanf("%d%d", &x, &y);
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
		}
	}
	printf("%d\n", dist[x][y]);
}
