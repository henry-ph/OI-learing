#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int factor[N];
int cnt = 0;
map<int, int> comp;
void fac(int n) {
	for (int i = 1; i <= sqrt(n); ++i) {
		if (!(n % i)) factor[++cnt] = i, factor[++cnt] = n / i; 
	}
	sort(factor + 1, factor + cnt + 1);
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	fac(n);
	for (int i = 1; i < cnt; ++i) {
		for (int j = i + 1; j <= cnt; ++j) 
			comp.insert(make_pair(factor[j] + factor[i], 1));
	}
	for (int i = 1; i < cnt; ++i) {
		for (int j = i + 1; j <= cnt; ++j) 
			if (comp.count(factor[j] - factor[i])) {
				printf("true\n");
				return 0;
			}
	}
	printf("false\n");
	return 0;
}
