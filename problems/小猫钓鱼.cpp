#include<bits/stdc++.h>
using namespace std;
const int N = 108, M = 52;
vector<int> a[2];
vector<int> :: iterator it[2];
int card[N + 5];
bool vis[N + 5], app[N + 5];
stack<int> s;
int main() {
	int cnt = 0;
	srand((unsigned)time(NULL));
	for (int k = 1; k <= 2; ++k) {
		for (int i = 1; i <= 13; ++i)
			for (int j = 1; j <= 4; ++j) card[++cnt] = i;
		card[++cnt] = 14, card[++cnt] = 15;
	}
	for (int i = 1; i <= 108; ++i) {
		int temp = rand() % N + 1;
		if (vis[temp]) temp = rand() % N + 1;
		vis[temp] = true;
		a[i > 54].push_back(card[temp]);
	}
	for (int i = 0; i <= 1; ++i) it[i] = a[i].begin();
	int now = 0, t = 0;
	while (it[0] != a[0].end() && it[1] != a[1].end()) {
		//cout << t << ' ' << now << endl;
		t++;
		s.push(*it[now]), it[now]++;
		if (app[*it[now]]) {
			int match = *it[now];
			app[*it[now]] = false;
			a[now].push_back(*it[now]), s.pop();
			while (s.top() != match) {
				cout << s.empty() << endl;
				cout << match << ' ' << s.top() << endl;
				a[now].push_back(s.top());
				app[s.top()] = false;
				s.pop();
			}
			cout << "hh" << endl;
			cout << match << ' ' << s.top() << endl;
			a[now].push_back(s.top()), s.pop();
			continue;
		}
		app[*it[now]] = true;
		now ^= 1;
	}
	cout << t << endl;
	return 0;
}
