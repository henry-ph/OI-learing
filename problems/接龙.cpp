#include <iostream>
#include <string>
using namespace std;
int n;
int side[21][21];
int visited[20];
string word[21];    //把首字母也当做一个单词，但只能在开头用一次
int Max;
void calc(int i, int j);    //计算word[j]接到word[i]后面增加的长度
void dfs(int i, int len);
int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++){
        cin >> word[i];
        for (int j = 0; j <= i; j++)
            calc(i, j);
    }
    dfs(n, 1);
    cout << Max;
    return 0;
}
void calc(int i, int j){
    int len = word[i].length() < word[j].length() ? word[i].length() : word[j].length();
    int k;
    int l = 0;
    while (l < len){
        l++;
        for (k = 0; k < l; k++)
            if (word[i][word[i].length() - k - 1] != word[j][l - k - 1])
                break;
        if (k == l){
            side[i][j] = word[j].length() - l;
            break;          //首先确定能接上的长度必然是最长的，直接退出
        }
    }
    if (i > j)
        calc(j, i);         //i接j和j接i两种情况
}
void dfs(int i, int len){
    int j;
    if (len > Max)
        Max = len;
    for (j = 0; j < n; j++)
        if (side[i][j] > 0 && visited[j] < 2){
            visited[j]++;
            dfs(j, len+side[i][j]);    //传递新的长度
            visited[j]--;
        }
}
