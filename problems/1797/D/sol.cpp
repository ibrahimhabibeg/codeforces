#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int MAX_N = 1e5 + 5;

vector<int> p(MAX_N, -1);
int imp[MAX_N], sz[MAX_N];
ll w[MAX_N];
vector<int> adj[MAX_N];

void dfs(int u){
  w[u] = imp[u];
  sz[u] = 1;
  for (int v: adj[u]) if(v!=p[u])
  {
    p[v] = u;
    dfs(v);
    sz[u] += sz[v];
    w[u] += w[v];
  }
}

struct cmp {
  bool operator()(const int &u, const int &v) const {
    if(sz[u]==sz[v]) return u<v;
    return sz[u]>sz[v];
  }
};

int main(){
  int n, m, a, b, t, x;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &imp[i]);
  for (int i = 0; i < n-1; i++) scanf("%d %d", &a, &b), adj[a-1].push_back(b-1), adj[b-1].push_back(a-1);
  dfs(0);
  set<int, cmp> s[n];
  for (int u = 0; u < n; u++) for (int v: adj[u]) if(v!=p[u]) s[u].insert(v);
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &t, &x);
    x--;
    if(t==1){
      printf("%lld\n", w[x]);
      continue;
    }
    if(s[x].size()==0) continue;
    auto it = s[x].begin();
    int y = *it;
    p[y] = p[x], p[x] = y;
    s[p[y]].erase(x);
    s[x].erase(it);
    w[x] -= w[y], w[y] += w[x];
    sz[x] -= sz[y], sz[y] += sz[x];
    s[y].insert(x); 
    s[p[y]].insert(y);
  }
  
}