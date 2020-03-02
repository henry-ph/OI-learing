#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define Size 2000

int x,y;
int top=0,i=0;
int stack[Size];
char s[Size];

int comp(char s[]){

    while (i<strlen(s)-1){
        switch (s[i]){
            case '+':stack[--top]+=stack[top+1];  break;
            case '-':stack[--top]-=stack[top+1];  break;
            case '*':stack[--top]*=stack[top+1];  break;
            case '/':stack[--top]/=stack[top+1];  break;
            default:
                x=0;
                while (s[i]!='.') x=x*10+s[i++]-'0';
                stack[++top]=x;
                break;
        }
        i++;
    }

    return stack[top];

}

int main(){

    gets(s);
    printf ("%d",comp(s));
    return 0;

}
