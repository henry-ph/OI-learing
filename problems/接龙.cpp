#include <iostream>
#include <string>
using namespace std;
int n;
int side[21][21];
int visited[20];
string word[21];    //������ĸҲ����һ�����ʣ���ֻ���ڿ�ͷ��һ��
int Max;
void calc(int i, int j);    //����word[j]�ӵ�word[i]�������ӵĳ���
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
            break;          //����ȷ���ܽ��ϵĳ��ȱ�Ȼ����ģ�ֱ���˳�
        }
    }
    if (i > j)
        calc(j, i);         //i��j��j��i�������
}
void dfs(int i, int len){
    int j;
    if (len > Max)
        Max = len;
    for (j = 0; j < n; j++)
        if (side[i][j] > 0 && visited[j] < 2){
            visited[j]++;
            dfs(j, len+side[i][j]);    //�����µĳ���
            visited[j]--;
        }
}
