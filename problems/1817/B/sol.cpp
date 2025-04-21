#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int u = 1; u <= n; u++) if(adj[u].size()>=4) for(int v: adj[u]){
    vector<int> cur, p(n+1); vector<bool> dis(n+1);
    auto dfs = [&](auto&& dfs, int x) -> bool {
      dis[x] = true;
      cur.push_back(x);
      if(x==v) return true;
      for(int y: adj[x]){
        if(x==u && y==v)continue;
        if(!dis[y]){
          p[y] = x;
          if(dfs(dfs, y)) return true;
        }
      }
      cur.pop_back();
      return false;
    };
    if(dfs(dfs, u)){
      vector<int> tails = adj[u];
      tails.resize(4);
      int mn = cur.size();
      for (int w: tails) {
        auto it = find(cur.begin(), cur.end(), w);
        if(it!=cur.begin()+1) mn = min(mn, int(it-cur.begin())+1);
      }
      cur.resize(mn);
      printf("YES\n%d\n%d %d\n", (int)cur.size()+2, u, (int)cur[mn-1]);
      int c = 0;
      for (int w: adj[u]){
        if(c>=2) break;
        auto it = find(cur.begin(), cur.end(), w);
        if(it==cur.end()){c++; printf("%d %d\n", u, w);}
      }
      for(int i = 1; i<cur.size(); i++) printf("%d %d\n", cur[i], cur[i-1]);
      return;
    }
  }
  printf("NO\n");
}

int main(){
  int TC;
  cin >> TC;
  while (TC--) solve();
}