#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
ll a[N], b[N], n, m;

bool ea(ll v) {
  ll i = lower_bound(a, a+n, v) - a;
  return i < n && a[i] == v;
}

bool eb(ll v) {
  ll i = lower_bound(b, b+m, v) - b;
  return i < m && b[i] == v;
}

void solve(){
  int q;
  scanf("%lld%lld%d", &n, &m, &q);
  ll A = 0, B = 0, x;
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]), A += a[i];
  for (int i = 0; i < m; i++) scanf("%lld", &b[i]), B += b[i];
  sort(a, a+n);
  sort(b, b+m);
  while (q--){
    scanf("%lld", &x);
    bool found = false;
    for (ll d1 = 1; d1 * d1 <= abs(x); d1++) if(x%d1 == 0){
      ll d2 = x / d1;

      if((ea(A-d1) && eb(B-d2)) || (ea(A+d1) && eb(B+d2)) || (ea(A-d2) && eb(B-d1)) || (ea(A+d2) && eb(B+d1))){
        found = true;
        break;
      }
    }
    if(found) printf("YES\n");
    else printf("NO\n");
  }
}

int main(){
  solve();
}