#include<cstdio>
#include<iostream>
using namespace std;
int a[1000000]={0},b[1000000]={0},c[1000000]={0},d[1000000]={0},ans[1000000],n,tim=0;
void print(){
        for(int i=1;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<ans[n]<<endl;
    return;
}
int dfs(int k){
    if(k>n)print();
    else {
        for(int i=1;i<=n;i++){
            if(a[i]==0&&b[i]==0&&c[i-k]==0&&d[i+k]==0){
                a[i]=1;ans[k]=i;b[i]=1;c[i-k]=1;d[i+k]=1;
                dfs(k+1);
                a[i]=0;b[i]=0;c[i-k]=0;d[i+k]=0;
            }        
            continue;
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}
