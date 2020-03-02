#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e4 + 5;
const double pi = 3.1415926, eps = 1e-10;
double v[N];
int n, f;

bool check(double x) {
	int num = 0;
	for (int i = 1; i <= n; ++i) {
		double tmp = v[i];
		if (x > tmp) continue;
		while (tmp - x > 0) {
			tmp -= x;
			num++;
		}
	} 
	if (num >= f) return true;
	else return false;
}
int main() {
	scanf("%d%d", &n, &f);
	f++;
	for (int i = 1; i <= n; ++i) {
		int r;
		scanf("%d", &r);
		v[i] = (double)r * (double)r * pi;
	}
	double l = (double)0, r = (double)N * (double)N * pi, ans;
	while (r - l > eps) {
		double mid = (l + r) / (double)2;
		if (check(mid)) {
			l = mid;
			ans = mid;
		}
		else r = mid;
	}
	printf("%.3lf\n", ans);
	return 0;
}
