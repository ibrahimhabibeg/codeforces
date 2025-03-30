#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  int a[n], mn = 1e9 + 10, mx = 0;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), mn = min(mn, a[i]), mx = max(mx, a[i]);
  printf("%d\n", mx-mn);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}