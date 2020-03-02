#include<cstdio>
#include<cstring>
char s[105];
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		int len = strlen(s);
		for (int i = 0; i < len; ++i) {
			if (s[i] == '#') {
				printf("%c", ' ');
				continue;
			}
			else if (s[i] >= '1' && s[i] <= '9' && s[i + 1] != '-') {
				printf("%c", (s[i] - '1') + 'A');
				continue;
			}
			else if (s[i] != '-') {
				printf("%c%c", s[i], s[i + 1]);
				printf("%c", ((s[i] - '0') * 10 + s[i + 1] - '0'));
				i += 2;
			}
		}
		printf("\n");
	}
	return 0;
}
