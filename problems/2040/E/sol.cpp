#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

void solve(){
  int n, x, y, k;
  scanf("%d%d", &n, &k);
  vector<int> adj[n+1];
  for (int i = 0; i < n-1; i++) scanf("%d%d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
  int d[n+1], p[n+1], level = 0;
  for (int i = 0; i <= n; i++) p[i] = -1;
  p[1] = 0;
  p[0] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      int u = q.front();
      q.pop();
      d[u] = level;
      for(int v: adj[u]) if(p[v]==-1) {
        p[v] = u;
        q.push(v);
      }
    }
    level++;
  }
  while (k--) {
    int v, c;
    scanf("%d%d", &v, &c);
    int w = p[v];
    multiset<ll> s;
    while (p[w]) {
      ll sz = adj[w].size();
      s.insert(2*sz - 2);
      w = p[p[w]];
    }
    ll res = d[v];
    for (int i = 0; i < (d[v]/2)-c; i++) {
      if(s.empty()) break;
      res = (res + *s.begin());
      s.erase(s.begin());
    }
    printf("%lld\n", res);
  }
  
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}