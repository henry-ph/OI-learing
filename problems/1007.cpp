#include<cstdio>
#include<algorithm>
using namespace std;
int a[5];
int main() {
	for (int i = 0; i < 3; ++i) scanf("%d", a + i);
	sort(a, a + 3);
	for (int i = 0; i < 2; ++i) printf("%d ", a[i]);
	printf("%d\n", a[2]);
	return 0;
}
