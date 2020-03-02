#include<bits/stdc++.h>
using namespace std;
const int N = 6000;
set<int> s;
set<int> :: iterator it;
int main() {
	s.insert(1);
	for (int i = 1; ; ++i) {
		if (s.size() >= 5842) break;
		s.insert(2 * i), s.insert(3 * i), s.insert(5 * i), s.insert(7 * i);
	} 
	int n;
	while (scanf("%d", &n) && n) {
		int cnt = 1;
		for (it = s.begin(); it != s.end(); ++it) {
			printf("%d\n", *it);
			getchar();
			cnt++;
		}
	}
	return 0;
}
