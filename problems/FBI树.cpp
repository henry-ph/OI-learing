#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 15;
vector<int> v[N];
int main() {
	int n, s;
	scanf("%d", &n);
	int len = 1 << n;
	printf("%d\n", len);
	return 0;
}
