#include<cstdio>
#include<cstring>
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int k;
		scanf("%d", &k);
		int h = k * 3;
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= k; ++j) printf("ACM");
			printf("\n");
		} 
	}
	return 0;
}
