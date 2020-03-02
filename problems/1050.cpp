#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 60;
struct node{
	int x, y, z, step;
	node node() {};
	node node(int _x, int _y, int _z, int _step) {
		x = _x;
		y = _y;
		z = _z; 
		step = _step;
	}
};
int dirx[] = {1, 0, -1, 0, 0, 0}, diry[] = {0, -1, 0, 1, 0, 0}, dirz[] = {0, 0, 0, 0, 1, -1};
bool vis[N][N][N], gra[N][N][N];

int main() {
	int l, r, c, sx, sy, ex, ey;
	while (scanf("%d%d%d", &l, &r, &c) && l) {
		for (int i = 1; i <= c; ++i) {
			for (int j = 1; j <= l; ++j) {
				char s[N];
				scanf("%s", s);
				for (int u = 1; u <= r; ++u) {
					if (s[u - 1] == '.') gra[j][u][i] = true;
					if (s[u - 1] == 'S') sx = 
				}
			}
		}
		node a = node()
		while (!q.empty()) {
		
		}	
	}
}
