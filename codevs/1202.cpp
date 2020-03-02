#include<bits/stdc++.h>
using namespace std;
int main() {
	int sum = 0, n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
	}
	printf("%d\n", sum);
	return 0;
}
