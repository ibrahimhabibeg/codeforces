#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
  while(b){
    int c = a;
    a =b, b = c%b;
  }
  return a;
}

int main(){
  int TC, a, b;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d",&a, &b);
    if(b%a){
      int res = (a/gcd(a,b))*b;
      printf("%d\n", res);
    }else{
      printf("%d\n", (b/a)*b);
    }
  }   
}