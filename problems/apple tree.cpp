#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 205;
int c[N], dp[N][N][2], st[N], pro[N];
int next, n, m;
struct node {
	int to, next;
}tree[N * N];
void add(int fr, int to) {
	tree[next].to = to;
	tree[next].next = st[fr];
	st[fr] = next++;
}
