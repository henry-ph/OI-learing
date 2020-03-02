#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N = 45;
char gra[N][N];
bool vis[N][N];
int dir[4][2] = {{0, 1}, {1, 0},{0, -1}, {-1, 0}};
int facel[4] = {3, 0, 1, 2}, facer[4] = {1, 0, 3, 2};
int sx, sy, ex, ey, n, m, ansl, ansr, ans, step;
bool flag;
struct node{
	int x, y, step;
	node(){};
	node(int _x, int _y, int _step) {
		x = _x;
		y = _y;
		step = _step;
	} 
};
queue <node> q;
bool check(int x, int y) {
	if (x <= 0 || x > m || y <= 0 || y > n) return false;
	else if (gra[x][y] == '#') return false;
	else if (vis[x][y]) return false;
	return true;
}
void dfsl(int x, int y, int tow) {
	if (flag) return;
	if (x == ex && y == ey) {
		ansl = step;
		flag = true;
		return;
	}
	step++;
	for (int i = 0; i < 4; ++i) {
		int j = (facel[i] + tow) % 4;
		int dx = x + dir[j][0];
		int dy = y + dir[j][1];
		if (!check(dx, dy)) continue;
		dfsl(dx, dy, j);
		return;
	}
}
void dfsr(int x, int y, int tow) {
	if (flag) return;
	if (x == ex && y == ey) {
		ansr = step;
		flag = true;
		return;
	}
	step++;
	for (int i = 0; i < 4; ++i) {
		int j = (facer[i] + tow) % 4;
		int dx = x + dir[j][0];
		int dy = y + dir[j][1];
		if (!check(dx, dy)) continue;
		dfsr(dx, dy, j);
		return;
	}
}
int bfs() {
	node a, next;
	a = node(sx, sy, 1);
	vis[a.x][a.y] = true;
	q.push(a);
	while (!q.empty()) {
		a = q.front();
		//printf("%d %d %d\n", a.x, a.y, a.step);
		q.pop();
		if (a.x == ex && a.y == ey) return a.step;
		for (int i = 0; i < 4; ++i) {
			next.x = a.x + dir[i][0];
			next.y = a.y + dir[i][1];
			if (check(next.x, next.y)) {
				next.step = a.step + 1;
				vis[next.x][next.y] = true;
				//printf("%d %d %d\n", next.x, next.y, next.step);
				q.push(next);
			}
		}
	}
	return 0;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k) {
		memset(vis, false, sizeof vis);
		flag = false;
		scanf("%d%d", &n, &m);
		while (!q.empty()) q.pop();
		for (int i = 1; i <= m; ++i) {
			char s[N];
			scanf("%s", s);
			for (int j = 0; j < n; ++j) {
				gra[i][j + 1] = s[j];
				if (s[j] == 'S') {
					sx = i;
					sy = j + 1;
				}
				if (s[j] == 'E') {
					ex = i;
					ey = j + 1;
				}
			} 
		}
		int dirc;
		if (sx == 1) dirc = 0;
		if (sx == m) dirc = 2;
		if (sy == 1) dirc = 1;
		if (sy == n) dirc = 3;
		step = 1;
		dfsl(sx, sy, dirc);
		printf("%d ", ansl);
		flag = false;
		step = 1;
		dfsr(sx, sy, dirc);
		printf("%d ", ansr);
		ans = bfs();
		printf("%d\n", ans);
	}
}
