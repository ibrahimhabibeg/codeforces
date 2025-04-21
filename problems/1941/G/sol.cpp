#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, a, b, c, s, e;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    map<int, int> dp;
    map<int, bool> dis;
    map<int, set<int>> adj;
    for (int i = 0; i < m; i++) scanf("%d%d%d", &a, &b, &c), adj[a].insert(c+n), adj[c+n].insert(a), adj[b].insert(c+n), adj[c+n].insert(b);
    scanf("%d%d", &s, &e);
    queue<int> q;
    q.push(s);
    dis[s] = true;
    dp[s] = 0;
    while (q.size()){
      int u = q.front();
      q.pop();
      for (int v: adj[u]) if(!dis[v]) dis[v] = true, dp[v] = dp[u] + 1, q.push(v);
    }
    printf("%d\n", dp[e]/2);
  }   
}