#include <iostream>
#include <string>
#include <vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f;
int horse[N];
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horse[i] = Pi;
    }
    sort(horse, horse + n);
    int minn = inf;
    for (int i = 1; i < n; ++i) {
    	if (abs(horse[i] - horse[i - 1]) < minn) minn = abs(horse[i] - horse[i - 1]);
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << minn << endl;
}
