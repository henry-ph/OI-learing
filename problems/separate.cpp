#include<cstdio>
int sum;
void dfs(int x, int last) {
	if (!x) {
		sum++;
		return;
	}
	for (int i = last; i <= x; ++i) dfs(x - i, i); 
}
int main() {
	int n;
	while (~scanf("%d", &n)) {
		sum = 0;
		dfs(n, 1);
		printf("%d\n", sum);
	}
	return 0;
}
