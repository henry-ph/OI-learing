#include<cstdio>
#include<cstdlib>
#include<cmath>
int main() {
	char t[1], d[1];
	double a, b;
	while (scanf("%s", t) && t[0] != 'E') {
		scanf("%lf%s%lf", &a, d, &b);
		double h, e;
		e = 6.11 * exp(5417.7530 * (((1 / 273.16) - (1 / (b + 273.16)))));
		h = (0.5555) * (e - 10.0);
		h += a;
		printf("%c %.1lf %c %.1lf %c %.1lf\n",'T', a, 'D', b, 'H', h);
	}
	return 0;
}
