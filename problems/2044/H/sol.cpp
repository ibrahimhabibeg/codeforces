#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, q, x1, x2, y1, y2;
  scanf("%d%d", &n, &q);
  ll a[n+1][n+1], s[n+1][n+1], si[n+1][n+1], sj[n+1][n+1];
  for (int i = 0; i <= n; i++) a[0][i] = a[i][0] = s[0][i] = s[i][0] = si[0][i] = si[i][0] = sj[0][i] = sj[i][0] = 0; 
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%lld", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    ll sum = 0;
    for (int j = 1; j <= n; j++) sum+=a[i][j], s[i][j] = s[i-1][j] + sum;
  }
  for (int i = 1; i <= n; i++) {
    ll sum = 0;
    for (int j = 1; j <= n; j++) sum+=i*a[i][j], si[i][j] = si[i-1][j] + sum;
  }
  for (int i = 1; i <= n; i++) {
    ll sum = 0;
    for (int j = 1; j <= n; j++) sum+=j*a[i][j], sj[i][j] = sj[i-1][j] + sum;
  }
  while(q--) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    ll res = ( s[x2][y2]- s[x1-1][y2]- s[x2][y1-1]+ s[x1-1][y1-1])*(1-x1-y1-x1*(y2-y1));
    res +=   (si[x2][y2]-si[x1-1][y2]-si[x2][y1-1]+si[x1-1][y1-1])*(y2-y1+1);
    res +=   (sj[x2][y2]-sj[x1-1][y2]-sj[x2][y1-1]+sj[x1-1][y1-1]);
    printf("%lld ", res);
  }
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}