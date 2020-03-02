#include<iostream>
#include<cstring>
using namespace std;
int main() {
	string s, num;
	getline(cin, s);
	int cnt = 0;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		bool flag = false;
		if (s[i] == '0' && s[i + 1] == ' ' && !flag) {
			flag = true;
			while (s[i++] != ' ');
			while (s[i++] != ' ') num[cnt++] = '1';
		}
		if (s[i] == '0' && s[i + 1] == 0 && !flag) {
			flag = true;
			while (s[i++] != ' ');
			while (s[i++] != ' ') num[cnt++] = '0';
		}
		if (!(cnt % 7)) num[cnt++] = ' '; 
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; ++i) cout<< num[i];
	cout <<endl;
	return 0;
}
