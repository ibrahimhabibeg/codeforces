#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int l, r, L, R;
  scanf("%d%d%d%d", &l, &r, &L, &R);
  int over = max(min(r, R) - max(l, L) + 1, 0), ans = over + 1;
  if(l==L) ans--;
  if(r==R) ans--;
  printf("%d\n", ans);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}