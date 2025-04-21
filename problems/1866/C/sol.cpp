#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int N = 1e5 + 2;
vector<pair<int, int>> adj[N];
ll c0[N], c1[N], inv[N];

ll dfs(int u){
  if(inv[u]!=-1) return inv[u];
  inv[u] = c0[u] = c1[u] = 0;
  for (auto p: adj[u]){
    int v = p.first, w = p.second;
    if(w==0) c0[u]=(c0[u]+1)%MOD, inv[u]=(inv[u]+c1[u])%MOD;
    else c1[u]=(c1[u]+1)%MOD;
    dfs(v);
    inv[u]=(inv[u]+inv[v])%MOD;
    inv[u]=(inv[u]+(c0[v]*c1[u]))%MOD;
    c0[u]=(c0[u]+c0[v])%MOD, c1[u]=(c1[u]+c1[v])%MOD;
  }
  return inv[u];
}

int main(){
  int n, a, sz, b;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) c0[i] = c1[i] = inv[i] = -1;
  for (int i = 1; i <= n; i++){
    scanf("%d", &sz);
    for (int j = 0; j < sz; j++) scanf("%d%d", &a, &b), adj[i].push_back(make_pair(a, b));
  }
 printf("%lld\n", dfs(1));
}