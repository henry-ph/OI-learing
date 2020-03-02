#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[10],b[10];
int main()
{
	int sa=1,sb=1,ana=0,anb=0,lena=0,lenb=0;
	gets(a);
	gets(b);
	lena=strlen(a);
	lenb=strlen(b);
	for(int i=0;i<lena;i++)
	sa*=a[i]-64;
	for(int i=0;i<lenb;i++)
	sb*=b[i]-64;
	ana=sa%47;
	anb=sb%47;
	if(ana==anb)
	cout<<"GO"<<endl;
	else
	cout<<"STAY"<<endl;
	return 0;
}
