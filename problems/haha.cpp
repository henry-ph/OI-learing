#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e4 + 5;
const int inf = 1e5;
int a[N];
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for (int i = 1; i <= n; ++i) cin >> a[i]; // the n temperatures expressed as integers ranging from -273 to 5526
    if (!n) cout << '0' << endl;
    else {
        int x = 0, delta = inf;
        for (int i = 1; i <= n; ++i) {
            if (abs(a[i]) < delta) {
            	x = a[i];
            	delta = abs(a[i]);
            }
        }
        cout << x <<endl;
    }
        
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}
