#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
string a;
int main() {
	while (getline(cin, a) && a[0] != '#') {
		int len, ans = 0;
		len = a.length();
		for (int i = 0; i < len; ++i) {
			if(a[i] == ' ') continue;
			else ans += (a[i] - 'A' + 1) * (i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}
