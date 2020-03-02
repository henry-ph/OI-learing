#include<cstdio>
#include<algorithm>
#include<cstring>
#define debug printf("hello,world\n")
using namespace std;
const int N = 10;
int maxd, n, k;
char s[N][8], exm[N] = "ATGC";
int pos[N], len[N];
void print() {
	for (int i = 1; i <= k; ++i) printf("%d ", pos[i]);
	printf("\n");
	return;
}
int h() {
	int ans = 0;
	for (int i = 1; i <= k; ++i) {
		ans = max(ans, len[i] - pos[i]);
	}
	return ans;
}
bool dfs(int d) {
	//print();
	//printf("%d\n", d);
	//getchar();
	if (d + h() > maxd) return false;
	if (!h()) return true;
	int tem[N];
	memset(tem, 0, sizeof tem);
	for (int i = 0; i < 4; ++i) {
		bool flag = false;
		for (int j = 1; j <= k; ++j) tem[j] = pos[j];
		for (int j = 1; j <= k; ++j) {
			//printf("%c %c\n", s[j][pos[j]], exm[i]);
			if (s[j][pos[j]] == exm[i]) {
				flag = true;
				pos[j]++;
			}
		}
		if (flag) {
			if (dfs(d + 1)) return true;
			//debug;
			for (int j = 1; j <= k; ++j) pos[j] = tem[j];
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		int maxlen = 0;
		for (int i = 1; i <= k; ++i) {
			memset(pos, 0, sizeof pos);
			
			scanf("%s", s + i);
			len[i] = strlen(s[i]);
			maxlen = max(len[i], maxlen);
		}
		for (maxd = maxlen; ; maxd++) {
			//printf("%d\n", maxd);
			if (dfs(0)) break;
		}
		printf("%d\n", maxd);
	}
}
