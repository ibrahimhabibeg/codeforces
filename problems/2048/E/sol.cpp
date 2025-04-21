#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  if(m>=2*n) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  int a[m][2*n];
  for (int i = 0; i < m; i++) for (int j = 0; j < 2*n; j++) a[i][j] = (((i+j)%(2*n)) + 2)/2;
  for (int j = 0; j < 2*n; j++) {
    for (int i = 0; i < m; i++) printf("%d ", a[i][j]);
    printf("\n");
  }
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}