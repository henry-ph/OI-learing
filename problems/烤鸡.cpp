#include<vector>
#include<string>
#include<cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<string>ans;
    for (int a(1); a < 4; ++a)
    for (int b(1); b < 4; ++b)
    for (int c(1); c < 4; ++c)
    for (int d(1); d < 4; ++d)
    for (int e(1); e < 4; ++e)
    for (int f(1); f < 4; ++f)
    for (int g(1); g < 4; ++g)
    for (int h(1); h < 4; ++h)
    for (int i(1); i < 4; ++i)
    for (int j(1); j < 4; ++j)
        if (a+b+c+d+e+f+g+h+i+j == n) {
            char s[200];
            sprintf(s, "%d %d %d %d %d %d %d %d %d %d", a,b,c,d,e,f,g,h,i,j);
            ans.push_back(s);
        } 
    printf("%d\n", ans.size());
    for (int i(0); i < ans.size(); ++i)
        printf("%s\n", ans[i].c_str());
    return 0;
}
