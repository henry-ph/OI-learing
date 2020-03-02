#include <iostream>  
#include <cmath>  
using namespace std;  
char a[100001];  
int main()  
{  
    int i,w=0,l=0;  
    for (i=1;;i++) 
    {   
      cin>>a[i];  
      if (a[i]=='E') {i--;break;}  
    }  
    for (int j=1;j<=i;j++)  
    {  
        if (a[j]=='W') w++;  
          else l++;  
        if (abs(w-l)>=2&&(w>=11||l>=11)) 
    {
    	cout<<w<<':'<<l<<endl;  
    w=0;  
    l=0; 
	}
	}
	cout<<w<<':'<<l<<endl<<endl;
	w=0;
	l=0; 
    for (int j=1;j<=i;j++)  
    {  
        if (a[j]=='W') w++;  
          else l++;  
        if (abs(w-l)>=2&&(w>=21||l>=21)) 
    	{
    		cout<<w<<':'<<l<<endl;
    	w=0;
    	l=0;
		}
	}
	cout<<w<<':'<<l<<endl;	
    return 0;  
}  
