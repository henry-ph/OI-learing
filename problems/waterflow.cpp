#include<cstdio>
#include<iostream>
using namespace std;
double a[5];
int main() {
	for (int i = 0; i < 4; ++i) scanf("%lf", a + i);
	double sum = 0, time = 0;
	int cnt = -1;
	while (true) {
		cnt = (cnt + 1) % 4;
		printf("%lf\n", sum);
		if (cnt <= 2) {
			if (sum + 1 / a[cnt] >= 1) {
				time += (1 - sum) * a[cnt];
				cout << time << endl;
				return 0;
			}
			else {
				sum += 1 / a[cnt];
				time++;
			}
		}
		else {
			sum - 1 / a[cnt] < 0 ? sum = 0 : sum -= 1/ a[cnt];
			time++;
		}
	}
	return 0;
}
