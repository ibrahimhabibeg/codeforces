#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, r;
  scanf("%d", &n);
  int i = n-1, j = n-2, p[n];
  p[1] = 0;
  while (i>1 && j>0) {
    printf("? %d %d\n", i, j);
    fflush(stdout);
    scanf("%d", &r);
    if(!r) p[i] = j, i--;
    j--;
  }
  while (i>1) p[i] = 0, i--;
  printf("! ");
  for (int i = 1; i < n; i++) printf("%d ", p[i]);
  printf("\n");
  fflush(stdout);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}