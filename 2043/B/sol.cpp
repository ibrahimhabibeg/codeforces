#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, d;
  scanf("%d%d", &n, &d);
  printf("1 ");
  if((d%3)==0 || n>2) printf("3 ");
  if(d==5) printf("5 ");
  if(d==7 || n>2) printf("7 ");
  if(d==9 || n>5 || (n>2 && ((d%3)==0))) printf("9 ");
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}