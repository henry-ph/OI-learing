#include<bits/stdc++.h>
using namespace std;
const double x = 1e-8;
char ans[2][5] = {"no", "yes"};
int main() {
	double a, b;
	scanf("%lf%lf", &a, &b);
	printf("%s", ans[abs(a - b) <= x]);
	return 0;
}
