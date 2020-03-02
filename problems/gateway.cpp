#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
bool vis[100][100];
int Exit[100];
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	memset(vis, false, sizeof vis);
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        vis[N1][N2] = vis[N2][N1] = true;
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        Exit[i] = EI;
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        bool flag = false;
        int x, y;
		for (int i = 0; i < N; ++i) {
			if (flag) continue;
			for (int j = 0; j < N; ++j) {
				if (!vis[i][j] && !vis[j][i]) {
					continue;
				}
				if (flag) continue;
				if (i == SI || j == SI) {
					x = i;
					y = j;
					for (int u = 0; u < E; ++u) {
						if (i == Exit[u] || j == Exit[u]) {
							flag = true;
							cout << SI << " " << Exit[u] << endl;
						}
					}
				}
			}
			if (i == N - 1) cout << x << " " << y << endl;
		}	
	}
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
}
