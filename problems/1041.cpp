#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		s.insert(u), s.insert(v);
	}
	printf("%d\n", s.size());
	return 0;
}
