#include<stdio.h>
int main()
{
    int i,ca=1,t,s,e,n,x,now,before,max;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       {
         scanf("%d",&now);
         if(i==1) 
         {
            max=before=now;  
            x=s=e=1; 
         }
         else {
             if(now>now+before) 
             {
                before=now;
                x=i; 
             }       
             else before+=now;
              }
         if(before>max) 
           max=before,s=x,e=i;
       }
       printf("Case %d:\n%d %d %d\n",ca++,max,s,e);
       if(t)printf("\n"); 
    }
    return 0;
}
