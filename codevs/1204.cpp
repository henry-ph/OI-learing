#include<cstdio>
#include<cstring>
const int N = 105;
char a[N], b[N];
int main() {
	scanf("%s%s", a, b);
	int lena = strlen(a), lenb = strlen(b);
	for (int i = 0; i < lena; ++i) {
		if (a[i] == b[0]) {
			bool f = true;
			for (int j = 0; j < lenb; ++j) 
				if (b[j] != a[i + j]) f = false;
			if (f) {
				printf("%d\n", i + 1);
				return 0;
			}
		}
	}
}
