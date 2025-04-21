#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
vector<int> adj[N];
int d[N];

void dfs(int u, int p) {
  for(int v: adj[u]) if(p!=v) {
    d[v] = d[u] + 1;
    dfs(v, u);
  }
} 

void solve(){
  int n, x, y, st, en;
  scanf("%d%d%d", &n, &st, &en);
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 0; i < n-1; i++) scanf("%d%d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
  d[en] = 0;
  dfs(en, 0);
  vector<int> nodes[n];
  for (int i = 1; i <= n; i++) nodes[d[i]].push_back(i);
  for (int i = n-1; i >= 0; i--) for(int node: nodes[i]) printf("%d ", node);
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}