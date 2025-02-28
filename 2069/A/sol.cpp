#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  int b[n-2];
  for (int i = 0; i < n-2; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n-4; i++) if(b[i] && !b[i+1] && b[i+2]) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}