#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
struct node{
	int a, b, step;
	string ans;
	node(){};
	node(int x, int y, int _step) {
		a = x;
		b = y;
		step = _step;
	}
};
const int N = 205;
bool vis[N][N];
queue <node> q;
int main() {

	int a, b, C;
	while (~scanf("%d%d%d", &a, &b, &C)) {
		bool flag = false;
		while (!q.empty()) q.pop();
		memset(vis, false, sizeof vis);
		node now, next;
	now = node(0, 0, 0);
	vis[now.a][now.b] = true;
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.a == C || now.b == C) {
			printf("%d\n", now.step);
			for (int i = 0; i < now.step; ++i) {
				char c = now.ans[i];
				if ('1' == c)
				puts("FILL(1)");
				else if ('2' == c)
				puts("FILL(2)");
				else if ('6' == c)
				puts("POUR(2,1)");
				else if ('5' == c)
				puts("POUR(1,2)");
				else if ('3' == c)
				puts("DROP(1)");
				else
				puts("DROP(2)");
			}
			flag = true;
			break;
		}
			next.a = a, next.b = now.b;
			if (!vis[next.a][next.b]) {
				next.step = now.step + 1;
				char c = 1 + '0';
				next.ans = "";
				next.ans += (now.ans + c);
				q.push(next);
				vis[next.a][next.b] = true;
			}
			next.b = b, next.a = now.a;
			if (!vis[next.a][next.b]) {
				next.step = now.step + 1;
				char c = 2 + '0';
				next.ans = "";
				next.ans += (now.ans + c);
				q.push(next);
				vis[next.a][next.b] = true;
			}
			next.a = 0, next.b = now.b;
			if (!vis[next.a][next.b]) {
				char c = 3 + '0';
				next.ans = "";
				next.ans += (now.ans + c);
				next.step = now.step + 1;
				q.push(next);
				vis[next.a][next.b] = true;
			}
			next.b = 0, next.a = now.a;
			if (!vis[next.a][next.b]) {
				next.step = now.step + 1;
				char c = 4 + '0';
				next.ans = "";
				next.ans += (now.ans + c);
				q.push(next);
				vis[next.a][next.b] = true;
			}
		if (now.a > now.b) {
			int temp = b - now.b;
			next.a = now.a - temp > 0 ? now.a - temp : 0;
			next.b = now.a - temp > 0 ? b : now.b + now.a;
			if (!vis[next.a][next.b]) {
				next.step = now.step + 1;
				char c = 5 + '0';
				next.ans = "";
				next.ans += (now.ans + c);
				q.push(next);
				vis[next.a][next.b] = true;
			}
		}
		if (now.a < now.b) {
			int temp = a - now.a;
			next.b = now.b - temp > 0 ? now.b - temp : 0;
			next.a = now.b - temp > 0 ? a : now.a + now.b;
			if (!vis[next.a][next.b]) {
				next.step = now.step + 1;
				char c = 6 + '0';
				next.ans = "";
				next.ans += (now.ans + c);
				q.push(next);
				vis[next.a][next.b] = true;
			}
		}
	}
	if (!flag) printf("impossible\n");
	}
	return 0;
}
