#include<cstdio>
#include<cstring>
using namespace std;
char str[500];
int main() {
	bool flag = false;
	double l, r, sum = 0;
	scanf("%s", str);
	int len;
	len = strlen(str);
	for (int i = 0; i < len; ++i) {
		if (str[i] == '=') flag = true; 
		if (str[i] == 'a' && !flag) {
			if (i == 1) l = str[i - 1] - 48;
			else if (str[i - 2] == '+') l = str[i - 1] - 48;
			else l = 48 - str[i - 1];
		}
		if (str[i] == 'a' && flag) {
			if (str[i - 2] == '+' || str[i - 2] == '=') r = str[i - 1] - 48;
			else r = 48 - str[i - 1];
		}
		if (str[i] >= '0' && str[i] <= '9' && str[i + 1] != 'a') {
			if (i == 1) sum += str[i] - 48;
			else if (str[i - 1] == '+' || str[i - 1] == '=') sum += str[i] - 48;
			else sum -= str
		} 
	}
}
