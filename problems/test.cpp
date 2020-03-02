#include<cstdio>
const int MAX = 1000;
int main() {
	int a, b, c, d;
	for (a = 1; a <= MAX; ++a) {
		for (b = 1; b <= MAX; ++b) {
				for (d = 1; d <= MAX; ++d) {
					int c = 19 + a;
					//printf("%d %d %d %d\n", a, b, c, d);
					if (a * a * a * a * a == b * b * b * b && c * c * c == d * d) {
						printf("%d %d %d %d\n", a, b, c, d);
						printf("%d\n", d - b);
						return 0;
					}
				}
			}
	}
	printf("impossible\n");
	return 0;
}
