#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
struct node {
	int x, y, step;
	bool drag;
};
queue<node> q;
const int N = 1e3 + 5;
bool gra[N][N];
int H, W;
bool check(int x, int y) {
	if (!gra[x][y] || x > H || y > W) return false;
	else return true;
}
int main() {
	int D, R;
	scanf("%d%d%d%d", &H, &W, &D, &R);
	for (int i = 1; i <= H; ++i) {
		char s[N];
		scanf("%s", s);
		for (int j = 1; j <= W; ++j) {
			if (s[j - 1] == '.') gra[i][j] = true;
			else gra[i][j] = false;
		}
	}
	node a;
	a.x = 1, a.y = 1, a.step = 1;
	q.push(a);
	while (!q.empty()) {
		node now;
		now = q.front();
		q.pop();
		if (now.x == H && now.y == W) {
			printf("%d\n", now.step);
			return 0;
		}
		if (check(now.x + 1, now.y)) {
			node next;
			next.x = now.x + 1, next.y = now.y, next.step = now.step + 1;
			q.push(next);
		}
		if (check(now.x, now.y + 1)) {
			node next;
			next.x = now.x, next.y = now.y + 1, next.step = now.step + 1;
			q.push(next);
		}
		if (!now.drag && check(now.x + D, now.y + R)) {
			node next;
			next.x = now.x + D, next.y = now.y + R, next.step = now.step + 1;
			q.push(next);
		}
	}
	printf("-1\n");
	return 0;
}
