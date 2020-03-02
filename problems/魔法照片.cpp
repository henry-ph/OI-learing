#include <stdio.h>
#include <algorithm>
int n,k;
int E[10];
int ync=0;
typedef struct One
{
    int ID;
    int IDT;
    int W;
    int C;
    bool operator <(const One&i)const
    {
        if(W==i.W)
            return IDT<i.IDT;
        else return W>i.W;
    }
}O,*LPO;
O All[20000];
void Input()
{
    scanf("%d %d",&n,&k);
    int wi;
    for(wi=0;wi<10;++wi)
        scanf("%d",E+wi);
    for(wi=0;wi<n;++wi)
    {
        scanf("%d",&All[wi].W);
        All[wi].IDT=wi+1;
    }
}
int main()
{
    Input();
    std::sort(All,All+n);
    int wi;
    for(wi=0;wi<n;++wi)
    {
        All[wi].ID=wi+1;
        All[wi].C=(All[wi].ID-1)%10+1;
        All[wi].W+=E[All[wi].C-1];
    }
    ync=1;
    std::sort(All,All+n);
    for(wi=0;wi<k;++wi)
        printf("%d ",All[wi].IDT);
    return 0;
}
