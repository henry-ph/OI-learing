#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N,a[110],dp1[110],dp2[110];
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    dp1[1] = 1;
    int maxn = 1;
    for (int j = 2; j <= N; ++j) {
        maxn = 1;
        for (int i = j-1; i > 0; --i) {
            if(a[i] < a[j])
                maxn = max(dp1[i] + 1,maxn);
        }
        dp1[j] = maxn;
    }
    dp2[N] = 1;
    for (int l = N-1; l > 0; --l) {
        maxn = 1;
        for (int i = l + 1; i <= N; ++i) {
            if(a[l] > a[i])
                maxn = max(maxn,dp2[i] + 1);
        }
        dp2[l] = maxn;
    }
    maxn = 1;
    for (int m = 1; m <= N; ++m) {
        maxn = max(maxn,dp1[m] + dp2[m]);
    }
    cout << N - maxn + 1 << endl;
    return 0;
}
