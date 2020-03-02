#include<stdio.h>  
   
int main()  
{  
    int a[10],j[10]={0},o[10]={0},m=0,n=0,temp=0,i=0,jcount=0,ocount=0;  
    while(scanf("%d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9])!=EOF)  
    {  
        for(i=0,ocount=0,jcount=0;i<10;i++)  
        {  
            if(a[i]%2==1)  
            {  
              j[jcount]=a[i];  
              jcount++;  
            }  
            else  
            {  
                o[ocount]=a[i];  
                ocount++;  
            }  
        }  
        for(m=0;m<jcount;m++)//ц╟ещ  
        {  
           for(n=0;n<jcount-m-1;n++)  
               if(j[n+1]>j[n])  
               {  
                   temp=j[n];  
                   j[n]=j[n+1];  
                   j[n+1]=temp;  
               }  
        }  
   
        for(m=0;m<ocount;m++)  
            for(n=ocount-1;n-m>0;n--)  
            {  
                if(o[n]<o[n-1])  
                {  
                    temp=o[n-1];  
                    o[n-1]=o[n];  
                    o[n]=temp;  
                }  
            }  
        if(ocount>0)  
        {  
            for(i=0;i<jcount;i++)  
            printf("%d ",j[i]);  
            for(i=0;i<ocount-1;i++)  
            printf("%d ",o[i]);  
            printf("%d",o[ocount-1]);  
        }  
        else  
        {  
            for(i=0;i<jcount-1;i++)  
            printf("%d ",j[i]);  
            printf("%d",j[jcount-1]);  
   
        }  
   
        printf("\n");  
   
    }  
    return 0;  
   
}  
