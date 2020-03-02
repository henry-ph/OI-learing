#include<cstdio>
int main() {
	int n, cnt;
	scanf("%d", &n);
	for (int i = 1; ; i++) {
		if ((1 + i) * i / 2 >= n) {
			cnt = i;
			break;	
		} 
	}
	int rest = n - (cnt - 1) * cnt / 2;
	if (cnt % 2) 
		printf("%d/%d\n", cnt - rest + 1, rest);
	else 
		printf("%d/%d\n", rest, cnt - rest + 1);
	return 0;	
}
