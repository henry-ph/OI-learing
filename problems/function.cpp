#include<cstdio>
int main() {
	int a, b, c, ans = 0;
	scanf("%d%d%d", &a, &b, &c);
	for (int x = 0; x <= 1000; ++x) {
		if ((c - a * x) < 0) break;
		if (!((c - a * x) % b)) ans++; 
	}
	printf("%d\n", ans);
	return 0;
}
