#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &m);
    int a1, a2 = 0, a3;
    printf("? 1 1\n");
    fflush(stdout);
    scanf("%d", &a1);
    a1++;
    if(a1 <= n){
      printf("? %d 1\n", a1);
      fflush(stdout);
      scanf("%d", &a2);
      a2++;
    }
    if(a2!=0 && a2!=a1) {
      printf("! %d %d\n", a1, a2);
      fflush(stdout); 
      continue;
    }
    printf("? 1 %d\n", a1);
    fflush(stdout);
    scanf("%d", &a3);
    a3++;
    printf("! %d %d\n", a3, a1);
    fflush(stdout);
  }   
}