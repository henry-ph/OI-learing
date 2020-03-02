#include<bits/stdc++.h>
using namespace std;
set<int> s;
set<int> :: iterator it;
int main() {
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		s.clear();
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d", &a);
			s.insert(a);
		}
		for (int i = 1; i <= m; ++i) {
			int a;
			scanf("%d", &a);
			s.insert(a);
		}
		for (it = s.begin(); it != s.end(); ++it) printf("%d ", *it);
		printf("\n");
	}
}
