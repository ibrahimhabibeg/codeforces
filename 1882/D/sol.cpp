#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll a[N], s[N], sz[N];
vector<int> adj[N];

ll calcSz(int u, int p){
  sz[u] = 1;
  for(int v: adj[u]) if(v!=p) sz[u]+=calcSz(v, u);
  return sz[u];
}

void dfs1(int u, int p, ll e){
  if(a[u]%2!=e)s[1]+=sz[u];
  for(int v: adj[u]) if(v!=p) dfs1(v, u, a[u]%2);
}

void dfs2(int u, int p){
  for(int v: adj[u]) if(v!=p){
    ll nv = sz[u], nu = sz[u] - sz[v], ou = sz[u], ov = sz[v];
    s[v] = s[u];
    if(a[u]%2!=a[v]%2) s[v]+=nu-sz[v];
    sz[u] = nu, sz[v] = nv;
    dfs2(v, u);
    sz[u] = ou, sz[v] = ov;
  }
}

int main(){
  int TC, n, x, y;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    vector<ll> m(n+1);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), adj[i].clear();
    for (int i = 0; i < n-1; i++) scanf("%d%d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
    calcSz(1, 0);
    for (int z = 0; z <= 20; z++){
      s[1] = 0;
      dfs1(1,0,a[1]%2);
      dfs2(1, 0);
      for (int i = 1; i <= n; i++) m[i]+=(1<<z)*1LL*s[i], a[i]/=2;
    }
    for (int i = 1; i <= n; i++) printf("%lld ", m[i]);
    printf("\n");
  }   
}