#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
vector<int> adj[N];
ll c[N], dp[N];

ll dfs(int u){
  if(dp[u]!=-1) return dp[u];
  if(adj[u].size()==0) return dp[u] = c[u];
  ll res = 0;
  for (int v: adj[u]) res+=dfs(v);
  return dp[u] = min(res, c[u]);
}

int main(){
  int TC, n, k, a, m;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]), adj[i].resize(0), dp[i]=-1;
    for (int i = 1; i <= k; i++) scanf("%d", &a), c[a] = 0;
    for (int i = 1; i <= n; i++){
      scanf("%d", &m);
      for (int j = 0; j < m; j++){
        scanf("%d", &a);
        adj[i].push_back(a);
      } 
    }
    for (int i = 1; i <= n; i++) printf("%lld ", dfs(i));
    printf("\n");
  }   
}