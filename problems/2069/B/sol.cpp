#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n][m];
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  vector<int> b(n*m+1);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    b[a[i][j]] = max(b[a[i][j]], 1);
    if(i>0 && a[i][j]==a[i-1][j]) b[a[i][j]] = 2;
    if(j>0 && a[i][j]==a[i][j-1]) b[a[i][j]] = 2;
  }
  sort(b.begin(), b.end());
  int res = 0;
  for (int i = 0; i < n*m; i++) res+=b[i];
  printf("%d\n", res);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}