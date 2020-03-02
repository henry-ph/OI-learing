#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node{
	int x, step;
	node(){};
	node(int _x, int _step) {
		x = _x;
		step = _step;
	}
};
queue <node> q;
const int N = 1e4;
bool prime[N], vis[N];
void is_prime() {
	memset(prime, true, sizeof prime);
	for (int i = 2; i <= N; ++i) {
		if (prime[i]) {
			for (int j = 2; j * i <= N; j++) prime[j * i] = false;
		}
	}
	return;
}
bool check(int x) {
	if (prime[x] && !vis[x]) return true;
	return false;
}
int bfs(int a, int b) {
	node now, next;
	now = node(a, 0);
	vis[now.x] = true;
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.x == b) return now.step;
		for (int i = 1; i <= 9; i += 2) {
			next.x = now.x / 10 * 10 + i;
			if (check(next.x)) {
				//printf("%d %d\n", now.x, next.x);
				vis[next.x] = true;
				next.step = now.step + 1;
				q.push(next);
			}
		}
		for (int i = 0; i <= 9; ++i) {
			next.x = now.x % 10 + now.x / 100 * 100 + i * 10;
			if (check(next.x)) {
				//printf("%d %d\n", now.x, next.x);
				vis[next.x] = true;
				next.step = now.step + 1;
				q.push(next);
			} 
		}
		for (int i = 0; i <= 9; ++i) {
			next.x = now.x % 100 + now.x / 1000 * 1000 + i * 100;
			if (check(next.x)) {
				//printf("%d %d\n", now.x, next.x);
				vis[next.x] = true;
				next.step = now.step + 1;
				q.push(next);
			} 
		}
		for (int i = 1; i <= 9; ++i) {
			//printf("%d %d\n", now.x, next.x);
			next.x = now.x % 1000 + i * 1000;
			if (check(next.x)) {
				vis[next.x] = true;
				next.step = now.step + 1;
				q.push(next);
			} 
		}
	}
}
int main() {
	int t;
	is_prime();
	scanf("%d", &t);
	while (t--) {
		bool flag = false;
		memset(vis, false, sizeof vis);
		while (!q.empty()) q.pop();
		int a, b;
		scanf("%d%d", &a, &b);
		int ans;
		if (a == b) {
			printf("0\n");
			flag = true;
		}
		if (!flag) {
			ans = bfs(a, b);
			if (!ans) printf("Impossible\n");
			else printf("%d\n", ans);
		}
	}
	return 0;
}
