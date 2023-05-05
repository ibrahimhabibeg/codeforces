#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, u, v;
  scanf("%d", &n);
  vector<vector<int>> adj(n+1), depth_nodes(n);
  for (int i = 0; i < n-1; i++)
  {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> p(n+1), in(n+1), in_sm(n+1), in_node(n+1), out(n+1), res(n+1); 
  p[1] = -1;
  queue<int> q;
  int depth = 0;
  q.push(1);
  while (!q.empty())
  {
    int size = q.size();
    while (size--)
    {
      int u = q.front();
      q.pop();
      depth_nodes[depth].push_back(u);
      for(int v: adj[u]) if(p[u]!=v){
        p[v] = u;
        q.push(v);
      }
    }
    depth++;
  }
  for (int i = n-1; i >= 0; i--) for (int u: depth_nodes[i]) for (int v: adj[u]) if(v!=p[u] && in[v]+1>in[u]){in[u] = 1 + in[v]; in_node[u] = v;}
  for (int i = n-1; i >= 0; i--) for (int u: depth_nodes[i]) for (int v: adj[u]) if(v!=p[u] && in_node[u]!=v) in_sm[u] = max(in_sm[u], 1+in[v]); 
  for (int i = 1; i < n; i++) for (int u: depth_nodes[i]) out[u] = 1 + max(out[p[u]], (in_node[p[u]]==u?in_sm[p[u]]:in[p[u]]));
  for (int i = 1; i<=n; i++) res[max(out[i], in[i])]++;
  res[0]++;
  for (int i = 0; i < n; i++)
  {
    printf("%d ", min(res[i],n));
    res[i+1]+=res[i];
  }
}