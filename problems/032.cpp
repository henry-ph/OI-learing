#include<cstdio>
using namespace std;
int ans;
int f(int x, int y) {
	ans++;
	if (!x || !y) return x + y + 1;
	else return f(x - 1, f(x, y - 1));
}
int main() {
	printf("%d\n",f(3, 2));
	printf("%d\n", ans);
	return 0;
}
