#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 10;
int n, maxd;
int vis[N][N], map[N][N], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool col[N];
void print() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) printf("%d ", vis[i][j]);
        printf("\n");
    }
    return;
}
void get_color(int x, int y, int color) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > n || nx < 1 || ny > n || ny < 1) continue;
        if (vis[nx][ny] == 1) continue;
        vis[nx][ny] = 2;
        if (map[nx][ny] != color) continue;
        get_color(nx, ny, color);
    }
    return;
}
int h() {
    int cnt = 0;
    memset(col, false, sizeof col);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) 
            if(vis[i][j] != 1 && !col[map[i][j]]) {
                col[map[i][j]] = true;
                cnt++;
            }
    }
    return cnt;
}
bool find_color(int x) {
	bool flag = false;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (vis[i][j] == 2 && map[i][j] == x) {
                get_color(i, j, x);
                flag = true;
            }
        }
    }
    if (!flag) return false;
    else return true;
}
bool dfs(int step) {
    //print();
    if (step == maxd) return !h();
	//printf("%d %d\n", step, h());
    int viss[N][N];
    memcpy(viss, vis, sizeof viss);
    if (step + h() > maxd) {
        //printf("hh\n");
        return false;
    }
    for (int i = 0; i < 6; ++i) {
        if (!find_color(i)) continue;
        if (dfs(step + 1)) return true;
        memcpy(vis, viss, sizeof vis);
    }
    return false;
} 
int main() {
    //freopen("a.txt", "r", stdin);
    while (scanf("%d", &n) && n) {
        memset(col, false, sizeof col);
        memset(vis, false, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &map[i][j]);
                col[map[i][j]] = true;
            }
        }
        maxd = -1;
        for (int i = 0; i < 6; ++i) 
            if (col[i]) maxd++;
        //printf("%d\n", maxd);
        get_color(1, 1, map[1][1]);
        for (maxd; ; ++maxd) {
            if (dfs(0)) break;
        }
        printf("%d\n", maxd);
    }
    return 0;
}
