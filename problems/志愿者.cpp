#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
struct re{
    int id,score;
}ren[10000];
int cmp(re a,re b)
{
    if(a.score==b.score)return a.id<b.id;
    return a.score>b.score;
}//SORT��������
int main()
{
    int n,m,tmp,sum=0;
    cin>>n>>m;
    tmp=m*1.5;
    //cout<<tmp<<endl;
    for(int i=0;i<n;i++)
        cin>>ren[i].id>>ren[i].score;
    sort(ren,ren+n,cmp);
    for(int i=tmp;i<n;i++){
        if(ren[i].score==ren[tmp-1].score)tmp++;//�жϺ�����û���ظ�
    }
    cout<<ren[tmp-1].score<<" "<<tmp<<endl;
    for(int i=0;i<tmp;i++)
    {
        cout<<ren[i].id<<" "<<ren[i].score<<endl;
    }
}
