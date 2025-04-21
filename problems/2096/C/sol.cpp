#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> h(n, vector<int>(n));
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> h[i][j];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  ll INF = 2e14;
  vector<vector<ll>> dpr(n, vector<ll>(2, INF));
  dpr[0][0] = 0;
  dpr[0][1] = a[0];
  for (int i = 1; i < n; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
    bool isPoss = true;
    for (int z = 0; z < n; z++) if(h[i][z]+j == h[i-1][z]+k) {
      isPoss = false;
      break;
    }
    if(isPoss) dpr[i][j] = min(dpr[i][j], dpr[i-1][k] + j*a[i]);
  }
  vector<vector<ll>> dpc(n, vector<ll>(2, INF));
  dpc[0][0] = 0;
  dpc[0][1] = b[0];
  for (int i = 1; i < n; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
    bool isPoss = true;
    for (int z = 0; z < n; z++) if(h[z][i]+j == h[z][i-1]+k) {
      isPoss = false;
      break;
    }
    if(isPoss) dpc[i][j] = min(dpc[i][j], dpc[i-1][k] + j*b[i]);
  }
  ll res = min(dpr[n-1][0], dpr[n-1][1]) + min(dpc[n-1][0], dpc[n-1][1]);
  if(res>=INF) res = -1;
  printf("%lld\n", res);
}

int main(){
  int TC;
  cin >> TC;
  while(TC--){
    solve();
  }
}