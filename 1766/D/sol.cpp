#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, x, y;
  scanf("%d", &n);
  int MX = 1e7 + 2;
  int p[MX];
  for (int i = 0; i < MX; i++) p[i] = i;
  for (int i = 2; i < MX; i++) for (int j = i; j < MX; j+=i) p[j] = min(p[j], i);
  while (n--){
    scanf("%d%d", &x, &y);
    int z = abs(x-y);
    if(x==1 && y==1){
      printf("1\n");
      continue;
    }
    if(z==0){
      printf("0\n");
      continue;
    }
    if(z==1){
      printf("-1\n");
      continue;
    }
    int res = z, d = p[z];
    while (d>1){
      res = min(res, (d+((-x)%d))%d);
      z/=d;
      d=p[z];
    }
    printf("%d\n", res);
  }   
}