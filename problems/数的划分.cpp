#include<cstdio>
int n,k,sum=0;
void dfs(int a,int b,int c){                                
    if(a<b) return;
    if(b==1){ sum++; return;  }
    for(int i=c;i<=a/b;i++)    dfs(a-i,b-1,i);                
}
int main(){
    scanf("%d%d",&n,&k);                                  
    dfs(n,k,1);                                                    
    printf("%d",sum);
}
