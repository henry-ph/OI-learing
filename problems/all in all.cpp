#include<cstdio>
#include<cstring>
const int N = 1e5 + 5;
char s[N], t[N];
int main() {
	while (~scanf("%s%s", s, t)) {
		int lena, lenb;
		lena = strlen(s);
		lenb = strlen(t);
		int j = 0;
		for (int i = 0; i < lenb; ++i) {
			if (t[i] == s[j]) j++;
		}
		if (j == lena) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
