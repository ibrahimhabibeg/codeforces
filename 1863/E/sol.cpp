#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, a, b, k;
  cin >> TC;
  while (TC--){
    scanf("%d%d%d", &n, &m, &k);
    vector<int> adj[n+1];
    bool dis[n+1];
    ll cmx = 0, t[n+1], c[n+1], invAdj[n+1];
    pair<ll, int> f[n+1];
    for (int i = 1; i <= n; i++) scanf("%lld", &t[i]), f[i] = make_pair(k,i), invAdj[i] = 0, dis[i] = false;
    for (int i = 0; i < m; i++){
      scanf("%d%d", &a, &b);
      adj[a].push_back(b), invAdj[b]++;
    }
    set<pair<ll, int>> s;
    ll time = 0;
    for (int i = 1; i <= n; i++) if(invAdj[i]==0) s.insert(make_pair(t[i], i)), dis[i] = true, f[i] = make_pair(t[i], i);
    while (!s.empty()){
      auto it = s.lower_bound(make_pair(time%k, 0));
      if(it==s.end()) it = s.begin();
      pair<ll, int> p = *it;
      s.erase(it);
      int tm = p.first, u = p.second;
      if(tm<time%k) time+=k+tm-(time%k);
      else time+=tm-(time%k);
      c[u] = time, cmx = max(cmx, time);
      for(int v: adj[u]) if(!dis[v]){
        invAdj[v]--;
        if(invAdj[v]==0) dis[v] = true, s.insert(make_pair(t[v], v));
      }
    }
    for (int u = 1; u <= n; u++) for(int v: adj[u]) if(c[v]-c[u]<k) f[v].first = min(f[v].first, f[u].first);
    ll res = cmx;
    sort(f+1, f+n+1);
    sort(t+1, t+n+1);
    int x = 1;
    for (int i = 1; i <= n; i++){
      while (x<=n && f[x].first<t[i]) cmx = max(cmx, c[f[x].second]+k), x++;
      res = min(res, cmx - t[i]);
    }
    printf("%lld\n", res);
  }   
}