#include<cstdio>
int main() {
	int n, hour, mini, sec;
	scanf("%d", &n);
	hour = n / 3600;
	n %= 3600;
	mini = n / 60;
	n %= 60;
	sec = n;
	printf("%d:%d:%d\n", hour, mini, sec);
	return 0;
}
