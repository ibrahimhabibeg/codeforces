#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, m, queries, x, y, z;
  scanf("%d%d%d", &n, &m, &queries);
  vector<pair<int, int>> adj[n+1];
  int f[n+1][n+1][m+1];
  vector<vector<int>> edges(m, vector<int>(3));
  for (int i = 0; i < m; i++) 
    scanf("%d%d%d", &x, &y, &z), adj[x].push_back(make_pair(y, z)), adj[y].push_back(make_pair(x, z)), edges[i][0] = x, edges[i][1] = y, edges[i][2] = z;
  sort(edges.begin(), edges.end(), [](vector<int> a, vector<int> b) {
    return a[2] > b[2];
  });
  for (int r = 1; r <= n; r++) {
    queue<int> q;
    vector<bool> dis(n+1);
    q.push(r);
    dis[r] = true;
    int level = 0;
    while(!q.empty()) {
      int sz = q.size();
      while(sz--){
        int u = q.front();
        q.pop();
        f[r][u][m] = level;
        for(auto p: adj[u]) {
          int v = p.first;
          if(!dis[v]) {
            dis[v] = true;
            q.push(v);
          }
        }
      }
      level++;
    }
  }
  for (int i = m-1; i >=0; i--) {
    int a = edges[i][0], b = edges[i][1];
    for (int u = 1; u <= n; u++) for (int v = 1; v <= n; v++)
      f[u][v][i] = min(f[u][v][i+1], min(f[u][a][i+1]+f[b][v][i+1], f[u][b][i+1]+f[a][v][i+1]));
  }
  int a, b, k;
  while(queries--){
    scanf("%d%d%d", &a, &b, &k);
    int res = 2e9;
    for (int i = m-1; i>=0; i--) {
      int u = edges[i][0], v = edges[i][1], w = edges[i][2];
      if(f[a][u][i] + f[v][b][i] < k) {
        printf("%d ", w);
        break;
      }
    }
  }
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}