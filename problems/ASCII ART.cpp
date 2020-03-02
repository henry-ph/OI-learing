#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
char x[] = {'A','B','C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int print[205];
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    int s = T.length();
    for (int i = 0; i < s; ++i) if(T[i] >= 'a' && T[i] <='z') T[i] -= 32;
    int len;
    len = T.length();
    string ROW[35];
    for (int i = 0; i < H; i++) {
        getline(cin, ROW[i]);
    }
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        bool flag = false;
        for (int j = 0; j < 26; ++j) {
            if (T[i] == x[j]) {
                flag = true;
                print[cnt++] = j;
            }
        }
        if (!flag) {
        	print[cnt++] = 26;
        }
    }
    for (int i = 0; i < H; ++i) {
    	for (int k = 0; k < cnt; ++k) {
    		for (int j = L * print[k]; j < L * print[k] + L; ++j) cout <<ROW[i][j];
    	}
    	cout << endl;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}
