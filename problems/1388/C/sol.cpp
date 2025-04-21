#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N  = 2e5 +5;
int h[N], p[N], g[N];
vector<int> adj[N];

bool dfs(int u, int pr){
  if((p[u]+h[u])%2) return false;
  g[u] = (p[u]+h[u])/2;
  if(g[u]<0 || g[u]>p[u]) return false;
  int dg = 0;
  for(int v: adj[u]) if(v!=pr){
    if(!dfs(v,u)) return false;
    else dg+=g[v];
  }
  if(dg>g[u]) return false;
  return true;
}

int dfsp(int u, int pr){
  for(int v: adj[u]) if(v!=pr) p[u]+=dfsp(v,u);
  return p[u];
}

int main(){
  int TC, n, m, a, b;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]), adj[i].clear();
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = 0; i < n-1; i++) scanf("%d%d", &a, &b), adj[a].push_back(b), adj[b].push_back(a);
    dfsp(1,0);
    if(dfs(1,0)) printf("YES\n");
    else printf("NO\n");
  }   
}