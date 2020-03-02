#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
const int N = 105;
char ans[3][50] = {"No", "Yes", "ERR"};
char comp[20];
bool flag;
bool vis[50];
int cnt;
struct node{
	char var[10];
	int num_s, num_e;
}loop[N];
stack<int> seq;

void init() {
	if (comp[2] == '1') flag = false, cnt = 0;
	else {
		flag = true;
		int pos = 4;
		while (comp[pos] >= '0' && comp[pos] <= '9') cnt = cnt * 10 + comp[pos] - '0', pos++;
	}
}

int main() {
	freopen("complexity.in", "r", stdin);
	freopen("complexity.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		while (!seq.empty()) seq.pop();
		memset(vis, false, sizeof vis);
		bool err = false;
		flag = false, cnt = 0;
		int final = 0, temp = 0;
		int l, cur = 0;
		scanf("%d%s", &l, comp);
		init();
		for (int i = 1; i <= l; ++i) {
			char s[10], var[10], start[10], end[10];
			scanf("%s", s);
			if (s[0] == 'F') {
				scanf("%s%s%s", var, start, end);
				if (err) continue;
				if (vis[var[0] - 'a']) err = true;
				else {
					loop[++cur].var[0] = var[0];
					vis[var[0] - 'a'] = true;
				}
				seq.push(cur);
				if (start[0] != 'n') loop[cur].num_s = start[0] - '0';
				else loop[cur].num_s = -1;
				if (end[0] != 'n') loop[cur].num_e = end[0] - '0';
				else loop[cur].num_e = -1;
			}
			else {
				if (err) continue;
				if (!seq.size()) {
					err = true;
					continue;
				}
				int now = seq.top();
				seq.pop();
				vis[loop[now].var[0] - 'a'] = false;
				int begin = loop[now].num_s, end = loop[now].num_e;
				if (begin > 0 && end > 0) continue;
				else if (begin == -1 && end == -1) continue;
				else if (begin == -1 && end > 0) continue;
				else temp++;
				if (!seq.size()) 
					final = max(final, temp), temp = 0;
			}
		}
		if (seq.size()) err = true;
		if (err) puts(ans[2]);
		else puts(ans[final == cnt]);
	}
	return 0;
}
