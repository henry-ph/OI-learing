#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("rand.txt", "w", stdout);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 1000; ++i) printf("%d, ", rand());
	printf("\n");
} 
