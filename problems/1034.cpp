#include<cstdio>
#include<cstring>
char x[15];
int main() {
	int n, pos;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%d", x, &pos);
		int len = strlen(x), post;
		for (int i = 0; i < len; ++i) if (x[i] == '.') post = i;
		if (pos > len - post - 1) {
			printf("0\n");
			continue;
		}
		printf("%c\n", x[pos + post]);
	}
	return 0;
}
