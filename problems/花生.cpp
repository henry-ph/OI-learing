#include <iostream>
#include <cmath>
using namespace std;
int a[21][21], b[401], x_last = 0, y_last = 0, m, n, x_now = 0, y_now = 0;
int Find_max()
{
    int max = 0;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            if(a[i][j] > max) 
            {
                max = a[i][j];
                x_now = i; y_now = j;
            }
}
int main()
{
    int k, tot = 0, ans = 0;
    cin >> m >> n >> k;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) 
        {
            cin >> a[i][j];
            if(a[i][j] != 0) ans++;
        }
    for(int i = 1; i <= ans; ++i)
    {
        int x, y;
        Find_max();
        if(i == 1)
        {
            if(k - x_now - 1 - x_now >= 0)
            {
                k = k - x_now - 1;
                tot = tot + a[x_now][y_now];
            }
            else break;
        }
        else
        {
            x = abs(x_last - x_now); 
			y = abs(y_last - y_now);
            if(k - x - y - 1 - x_now >= 0)
            {
                k = k - x - y - 1;
                tot = tot + a[x_now][y_now];
            }
            else break;
        }
        a[x_now][y_now] = 0;
        x_last = x_now; y_last = y_now;
    }
    cout << tot<<endl;
    return 0;
}
