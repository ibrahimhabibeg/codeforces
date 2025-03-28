#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e17;

void solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  ll a[n], b[n], d[1 + 2*n];
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
  d[0] = 0;
  for (int i = 1; i <= 2*n; i++) d[i] = d[i-1] + b[(i-1)%n] - a[(i-1)%n];
  stack<pair<ll ,int>> s;
  s.push(make_pair(INF, 2*n+10));
  int res = 0;
  for (int i = 2*n; i >= 0; i--) {
    while (d[i]>s.top().first) s.pop();
    if(i<n) res = max(res, s.top().second-i);
    s.push(make_pair(d[i], i));
  }
  printf("%d\n", res);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}