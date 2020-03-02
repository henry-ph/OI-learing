#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int bits[800];
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    int len, cnt = 0;
    len = MESSAGE.length();
	for (int i = 0; i < len; ++i) {
		char ch = MESSAGE[i];
		for (int j = 0; j < 7; ++j) {
			bits[cnt++] = ch & 1;
			ch >>= 1;
		}
	}
	for (int i = cnt - 1; i >= 0; --i) {
		cout << bits[i];
		if (!(i%7)) cout << ' ';
	}
	cout << endl;
	for (int i = cnt - 1; i >= 0; --i) {
		bool flag = false;
		if (bits[i] && !flag) {
			flag = true;
			cout << "0 ";
			while (bits[i]) {
				cout << '0';
				i--;
			}
		}
		if (!bits[i] && !flag) {
			flag = true;
			cout << "00 ";
			while (!bits[i]) {
				cout << '0';
				i--;
			}
		}
		++i;
		if (i) cout << " ";
	}
	cout << endl;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}
