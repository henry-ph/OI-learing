#include<cstdio>
#include<cstring>
char s[55];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		int len = strlen(s);
		for (int j = 0; j < len; j += 2) s[j] ^= s[j + 1] ^= s[j] ^= s[j + 1];
		printf("%s\n", s);
	}
	return 0;
}
