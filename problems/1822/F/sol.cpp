#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vector<vi> adj, d_nodes;
vi p, d;

void dfs(int u)
{
  d[u] = 1 + d[p[u]];
  d_nodes[d[u]].push_back(u);
  for (int v: adj[u])
    if(v!=p[u]){
      p[v] = u;
      dfs(v);
    }
}

int main(){
  int TC, n, k, c, u, v;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d %d", &n, &k, &c);
    vi in(n+1), out(n+1), in_sm(n+1), in_node(n+1);
    p.clear(), d.clear(), d_nodes.clear(), adj.clear();
    p.resize(n+1), d.resize(n+1), d_nodes.resize(n), adj.resize(n+1);
    for (int i = 0; i < n-1; i++)
    {
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    p[1] = 0, d[0] = -1;
    dfs(1);
    for (int i = n-1; i >= 0; i--) for (int u : d_nodes[i]) for (int v : adj[u]) if(v!=p[u] && 1+in[v]>in[u]){ in[u] = 1 + in[v]; in_node[u] = v; }
    for (int i = n-1; i >= 0; i--) for (int u : d_nodes[i]) for (int v : adj[u]) if(v!=p[u] && in_node[u]!=v && 1+in[v]>in_sm[u]) in_sm[u] = 1 + in[v];
    for (int i = 1; i < n; i++) for (int u : d_nodes[i]) out[u] = 1 + max(out[p[u]], (in_node[p[u]]==u ? in_sm[p[u]] : in[p[u]]));
    ll res = 0;
    for (int i = 1; i <= n; i++) res = max(res, k*1LL*max(out[i], in[i]) - c*1LL*d[i]);
    printf("%llu\n", res);
  }   
}