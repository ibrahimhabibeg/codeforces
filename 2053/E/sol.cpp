#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
vector<int> adj[N];
int a[N], n;
bool isAdjEdge[N];
ll ans, A;

void initIsAdjEdge() {
  for (int u = 1; u<=n; u++){
    isAdjEdge[u] = adj[u].size() == 1;
    for(int v: adj[u]) if(adj[v].size() == 1) isAdjEdge[u] = true;
  }
  isAdjEdge[0] = false;
}

ll calcA(int u, int p) {
  a[u] = !isAdjEdge[u];
  for (int v: adj[u]) if(v!=p) a[u] += calcA(v, u);
  return a[u];
}

int f(int u, int p) {
  int res = 0;
  if(adj[u].size()==1) return res;
  for (int v: adj[u]) if(v!=p && isAdjEdge[v]) res+=a[v];
  if(isAdjEdge[p]) res += A-a[u];
  return res;
}

void dfs(int u, int p) {
  ans += f(u, p);
  for (int v: adj[u]) if(v!=p) dfs(v, u);
}

void solve(){
  int x, y;
  scanf("%d", &n);
  for (int i = 1; i<= n; i++) adj[i].clear();
  for (int i = 0; i < n-1; i++) scanf("%d%d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
  initIsAdjEdge();
  calcA(1, 0);
  int m = 0;
  A = 0;
  for (int i = 1; i <= n; i++) A+=!isAdjEdge[i], m+=adj[i].size()==1;
  ans = m*1ll*(n-m);
  dfs(1, 0);
  printf("%lld\n", ans);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}