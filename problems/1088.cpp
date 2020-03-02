#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-10;
double _bow(double x, int t) {
	double ans = 1;
	while (t--) ans *= x;
	return ans;
}
double ff(double x, double y) {
	return 42 * _bow(x, 6) + 48 * _bow(x, 5) + 21 * _bow(x, 2) + 10 * x - y;
}

double f(double x, double y) {
	return 6 * _bow(x, 7) + 8 * _bow(x, 6) + 7 * _bow(x, 3) + 5 * _bow(x, 2) - y * x;
}

int main() {
	double x, y;
	scanf("%lf", &y);
	double l = 0, r = 100, ans;
	while (l < r) {
		double mid = (l + r) / (double)2;
		if (fabs(ff(mid, y) - 0) <= eps) {
			ans = mid;
			break;
		}
		if (ff(mid, y) < 0) l = mid;
		else r = mid; 
	}
	printf("%.4lf\n", f(ans, y));
	return 0;
}
