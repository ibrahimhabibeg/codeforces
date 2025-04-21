#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+5;
int a[N], dp[N], s[N];
bool c[N];

void cycle(int u){
  if(s[u]==2) return;
  if(s[u]) c[u] = true;
  s[u]++;
  cycle(a[u]);
  s[u] = 2;
}

int dfs(int u) {
  if(dp[u]!=-1) return dp[u];
  if(c[u]) dp[u] = 0;
  else dp[u] = 1 + dfs(a[u]);
  return dp[u];
}

void solve(){
  int n, x, res = 2;
  scanf("%d", &n);
  for (int i = 1; i <=n; i++) scanf("%d", &a[i]), dp[i] = -1, c[i] = false, s[i] = 0;
  for (int i = 1; i <=n; i++) cycle(i);
  for (int i = 1; i <=n; i++) res = max(res, 2+dfs(i));
  printf("%d\n", res);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}