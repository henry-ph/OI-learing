#include <iostream>
using namespace std;
int a[101][101];

int main()
{
long int m, n, total=0;
cin >> m >> n;
for (int i=1; i<=m; ++i)
{
for (int j=1; j<=n; ++j)
{
cin >> a[i][j];
if (i==1||i==m||j==1||j==n)
total += a[i][j];
}
}
cout << total << endl;
return 0;
}
