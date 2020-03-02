#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
int main() {
	freopen("ans.txt", "w", stdout);
	int n = 1;
	while (n <= 1000) {
		while (gcd((n + 2), (3 * n * n + 7)) == 1) n++;
		printf("%d\n", n);
		n++;
	}
	return 0;
} 
