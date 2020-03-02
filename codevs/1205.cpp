#include<bits/stdc++.h>
using namespace std;
char s[105], ans[105][105];
int main() {
	int len = 0;
	while (scanf("%s", s) != EOF) {
		int tlen = strlen(s);
		len += 1;
		for (int i = 0; i < tlen; ++i) ans[len][i] = s[i];
	}
	for (int i = len; i >= 1; --i) printf("%s ", ans[i]);
	printf("\n");
	return 0;
}
