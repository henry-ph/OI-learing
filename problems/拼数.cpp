#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 25
using namespace std;
inline bool cmp(string a,string b){
  for(int i=0;i<4;i++){
    a+=a;
    b+=b;
  }
  return a>b;
}

string a[MAXN];
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n,cmp);
  for(int i=0;i<n;i++){
    cout<<a[i];
  }
  return 0;
}
