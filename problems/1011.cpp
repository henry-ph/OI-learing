#include<cstdio>
int main() {
	int a = 1, b = 1;
	while (true) {
		scanf("%d%d", &a, &b);
		if (!a) break;
		a ^= b ^= a ^= b;
		printf("%d %d\n", a, b);
	}
	printf("\n");
	return 0;
}
