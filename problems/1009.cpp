#include<cstdio>
int main() {
	int cnt = 0, n;
	while(scanf("%d", &n) && n) {
		printf("����%d:%d\n", ++cnt, n);
	}
	return 0;
}
