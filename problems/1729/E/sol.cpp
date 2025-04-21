#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll x = 2, v1, v2;
  while (true){
    printf("? 1 %lld\n", x);
    fflush(stdout);
    scanf("%lld", &v1);
    printf("? %lld 1\n", x);
    fflush(stdout);
    scanf("%lld", &v2);
    if(v1==-1){
      printf("! %lld\n", x-1);
      fflush(stdout);
      break;
    }
    if(v1!=v2){
      printf("! %lld\n", v1+v2);
      fflush(stdout);
      break;
    }
    x++;
  }
}