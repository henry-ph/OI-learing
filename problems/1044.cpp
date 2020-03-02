#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define pb push_back
 
using namespace std;
const int N = 505;
vector<int> chu[N];
int ru[N];
priority_queue<int, vector<int>, greater<int> > q;
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m) && n) {
    	for (int i = 1; i <= m; ++i) {
	        int a, b;
	        scanf("%d%d", &a, &b);
	        ru[b]++;
	        chu[a].pb(b);
   		}
    	for (int i = 1; i <= n; ++i) if (!ru[i]) q.push(i);
    	while (!q.empty()) {
	        int now = q.top();
	        q.pop();
	        if (!ru[now]) {
	            printf("%d ", now);
	            for (int j = 0; j < chu[now].size(); ++j) {
	                q.push(chu[now][j]);
	                ru[chu[now][j]]--;
	            }
	        }
	    }
	    printf("\n");
	}
    return 0;
}
