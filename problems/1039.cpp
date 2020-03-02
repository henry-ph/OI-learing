#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		int tmpa = 0, tmpb = 0;
		if (a < b) {
			for (int i = 1; ; ++i) {
				tmpa += a;
				if (!(tmpa % b)) {
					printf("%d\n", tmpa);
					break;
				}
			}
		}
		else {
			for (int i = 1; ; ++i) {
				tmpb += b;
				if (!(tmpb % a)) {
					printf("%d\n", tmpb);
					break;
				}
			}
		}
	}
	return 0;
}
