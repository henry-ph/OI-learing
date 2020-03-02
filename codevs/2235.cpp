#include<cstdio>
int main() {
	double p, c;
	int tmp, ans;
	scanf("%lf%lf", &p, &c);
	ans = p * 0.1 * c;
	tmp = ans % 10, ans /= 10;
	if (tmp >= 5) ans += 1;
	printf("%d\n", ans * 10);
	return 0;
}
