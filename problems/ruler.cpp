#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N = 55;
bool vis[N];
struct node{
	int len;
	int step;
	node(){};
	node(int _len, int _step) {
		len = _len;
		step = _step;
	}
}scale[N];
queue <node> q; 
bool comp(node a, node b) {
	return a.len > b.len;
}
int main() {
	int n;
	while (scanf("%d", &n) && n) {
		//memset(vis,false, sizeof vis);
		while (!q.empty()) q.pop();
		for (int i = 0; i < n; ++i) scanf("%d", scale[i].len);
		sort(scale, scale + n, comp);
		node a = node(scale[0], 0);
		q.push(a);
		while (!q.empty()) {
			node now = q.front();
			node next;
			q.pop();
			next.step = now.step + 1;
			next.len = scale[now.step];
			q.push(next);
			next.len = now.len - scale[now.step];
			q.push()
		}
	}
	return 0;
}
