#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
const int N = 1e3 + 5;
typedef long long ll;
const ll inf = 4e18;
ll h, r;
int n;
bool flag, vis[N];
char ans[2][10] = {"No", "Yes"};
struct axis{
	ll x, y, z;
	axis() {};
	axis(ll _x, ll _y, ll _z) {
		x = _x, y = _y, z = _z;
	}
}pos[N];
int f[N];
vector<int> low, high;

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
} 

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	f[fx] = fy;
}

ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

ll dist(axis a, axis b) {	
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z); 
}

bool comp(axis a, axis b) {
	return a.z < b.z;
}

bool check(axis a, axis b) {
	return dist(a, b) <= r * r;
}

bool init_low(axis a) {
	return a.z <= r / 2;
}

bool init_high(axis a) {
	return (h - a.z) <= r / 2;
}

int main() {
	freopen("cheese.in", "r", stdin);
	freopen("cheese.out", "w", stdout);
	int T;
	T = (int)read();
	while (T--) {
		low.clear(), high.clear();
		memset(vis, false, sizeof vis);
		flag = false;
		n = (int)read(), h = read(), r = read();
		r *= 2;
		for (int i = 1; i <= n; ++i) f[i] = i;
		for (int i = 1; i <= n; ++i) {
			ll x, y, z;
			x = read(), y = read(), z = read();
			pos[i] = axis(x, y, z);
		}
		sort(pos + 1, pos + n + 1, comp);
		for (int i = 1; i <= n; ++i) {
			if (init_low(pos[i])) low.push_back(i);
			else break;
		}
		for (int i = n; i >= 1; --i) {
			if (init_high(pos[i])) high.push_back(i);
			else break;
		}
		if (!low.size() || !high.size()) {
			puts(ans[0]);
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (check(pos[i], pos[j])) {
					if (find(i) != find(j)) merge(i, j);
				}
			}
		}
		bool flag = false;
		for (int i = 0; i < low.size(); ++i) {
			for (int j = 0; j < high.size(); ++j) {
				if (find(low[i]) == find(high[j])) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		puts(ans[flag]);
	}
	return 0;
}
