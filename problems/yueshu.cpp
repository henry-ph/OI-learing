#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 2; i <= max(a, max(b, c)); ++i) {
		if (a % i == b % i && a % i == c % i) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
